#include "_include.h"

// Leetcode 36
class Solution {
public:
        bool isValidSudoku(vector<vector<char>>& board) {
                vector<unordered_set<string>> check_map(9, unordered_set<string>());
                string row = "row";
                string col ="col";
                string cell ="cell";

                for (int i = 0; i < 9; ++i) {
                        for (int j = 0; j < 9; ++j) {
                                if (board[i][j] != '.') {
                                        row += (i+'0');
                                        col += (j+'0');
                                        cell += (i / 3 + '0');
                                        cell += (j / 3 + '0');
                                        int num = board[i][j] - '1';
                                        if (check_map[num].find(row) != check_map[num].end()
                                                || check_map[num].find(col) != check_map[num].end()
                                                || check_map[num].find(cell)!= check_map[num].end()) {
                                                return false;
                                        }
                                        else {
                                                check_map[num].insert(row);
                                                check_map[num].insert(col);
                                                check_map[num].insert(cell);
                                                row = "row";
                                                col = "col";
                                                cell = "cell";
                                        }
                                }
                        }
                }

                return true;
        }
};


// Leetcode 37
class Solution {
private:
        //横向尺子
        unordered_set<char> ruler = { '1','2','3','4','5','6','7','8','9' };
        //定位格表
        vector<vector<int>> cell_pos = { {0,1,2},{3,4,5},{6,7,8} };

        //初始化查询表函数, 默认存在共同元素, 查询表保存未填格的位置, 即三个vector都存在才可能成为候选
        unordered_set<char> initial_query(
                vector<unordered_set<char>>& map_row, 
                vector<unordered_set<char>>& map_col,
                vector<unordered_set<char>>& map_cell,
                const int& i, const int& j)
        {
                //map_row[i],map_colume[j],map_cell[i/3][j/3]
                int x = cell_pos[i / 3][j / 3];  //格表位置

                //以行为标杆, 在另外两个set中没找到就移除
                unordered_set<char> tmp = map_row[i];
                unordered_set<char> tmp2 = tmp;

                for (auto c : tmp) {
                        if (map_col[j].find(c) == map_col[j].end() ||
                                map_cell[x].find(c) == map_cell[x].end()) {
                                tmp2.erase(c);
                        }
                }
                return tmp2;
        }

public:

        //主函数
        void solveSudoku(vector<vector<char>>& board) {

                //各行格列状态, 因为要随时检查是否只剩最后一个值, 所以用set,但确实是不需要map了
                vector<unordered_set<char>> map_row = vector<unordered_set<char>>(9, ruler);
                vector<unordered_set<char>> map_col = vector<unordered_set<char>>(9, ruler);
                vector<unordered_set<char>> map_cell = vector<unordered_set<char>>(9, ruler);

                //查询表 需要填入字符数量
                map<int, unordered_set<char>> unset_position_set;

                //初始化行表, 列表, 格表
                for (int i = 0; i < 9; i++) {
                        for (int j = 0; j < 9; j++) {
                                if (board[i][j] != '.') {
                                        map_row[i].erase(board[i][j]);
                                        map_col[j].erase(board[i][j]);
                                        map_cell[cell_pos[i / 3][j / 3]].erase(board[i][j]);
                                }
                        }
                }

                //根据三个表, 初始化查询表
                for (int i = 0; i < 9; ++i) {
                        for (int j = 0; j < 9; ++j) {
                                if (board[i][j] == '.') {
                                        int s = i * 10 + j;
                                        unset_position_set[s] = initial_query(map_row, map_col, map_cell, i, j);//定位"ij"，获得查询表
                                }
                        }
                }

                // 先进行一次绝对查询
                board = solveSudoku_absolute(board, map_row, map_col, map_cell, unset_position_set);
        }

        
        /*
        * 绝对查询, 查找无效返回空, 查找失败选择相对查询, 查找成功返回board
        * 会根据对应的board修改几个查询表, 因为接受的是引用
        */
        vector<vector<char>> solveSudoku_absolute(vector<vector<char>>& board,
                vector<unordered_set<char>>& map_row,
                vector<unordered_set<char>>& map_col,
                vector<unordered_set<char>>& map_cell,
                map<int, unordered_set<char>>& unset_position_set) {

                if (board.empty()) return board; 

                //循环函数主体
                while (!unset_position_set.empty()) {

                        bool check = 0;

                        for (auto it = unset_position_set.begin(); it != unset_position_set.end(); it++) {
                                if (it->second.size() == 0) {
                                        cout << "------------------------------------" << endl;
                                        cout << it->first <<" no choice" << endl;
                                        return{};  //查询为无效, 返回空
                                        
                                }
                        }

                        for (auto it = unset_position_set.begin(); it != unset_position_set.end(); it++) {
                                if (it->second.size() == 1) {//如果查询表set中只有唯一解

                                        //取出地址，修改board
                                        update(it->first, *(it->second.begin()), board, map_row, map_col, map_cell, unset_position_set);

                                        for (auto& c : board) {
                                                for (auto& d : c) {
                                                        cout << d << " ";
                                                }
                                                cout << endl;
                                        }
                                        cout << "------------------------------------" << endl;

                                        check = 1;
                                        break;
                                }
                        }

                        //对所有的格, 都没有可选的点, 则只能遍历, 或者进行尝试选择处理
                        if (check == 0) break;
                }

                // 绝对查询失败, 即能选择的值的个数都大于等于2, 启动相对查询
                if (!unset_position_set.empty()) {
                        board = solveSudoku_abstract(board, map_row, map_col, map_cell, unset_position_set);
                }

                return board;
        }

        //相对查询函数, 需要对查询表中的数据进行测试, 填入一个值后进入绝对查询
        vector<vector<char>> solveSudoku_abstract(vector<vector<char>>& board,
                vector<unordered_set<char>>& map_row,
                vector<unordered_set<char>>& map_col,
                vector<unordered_set<char>>& map_cell,
                map<int, unordered_set<char>>& unset_position_set) {

                //存档
                vector<vector<char>> save_board = board;
                vector<unordered_set<char>> save_map_row = map_row;
                vector<unordered_set<char>> save_map_col = map_col;
                vector<unordered_set<char>> save_map_cell = map_cell;


                for (int num = 2; num <= 9; ++num) {

                        //从2个数开始, 重新进行绝对查询, 如果查询成功, 则直接返回成功, 查询失败, 将存档覆盖, 继续进行查询

                        for (auto it = unset_position_set.begin(); it != unset_position_set.end(); ++it) {
                                if (it->second.size() == num) {
                                        while(!it->second.empty()){
                                                auto c = it->second.begin();

                                                //因为迭代器缘故, 所以查询表必须用dfs遍历
                                                map<int, unordered_set<char>> save_unset_position_set = unset_position_set;
                                                
                                                // dfs修改
                                                //update(it->first, *v, board, map_row, map_col, map_cell, save_unset_position_set);
                                                update(it->first, *c, board, map_row, map_col, map_cell, save_unset_position_set);
                                                
                                                cout << "update " << it->first << " set: ";
                                                for (auto& c : it->second) cout << c << " ";
                                                cout << endl;

                                                for (auto& c : board) {
                                                        for (auto& d : c) {
                                                                cout << d << " ";
                                                        }
                                                        cout << endl;
                                                }
                                                cout << "------------------------------------" << endl;

                                                board = solveSudoku_absolute(board, map_row, map_col, map_cell, save_unset_position_set);

                                                if (!board.empty()) {
                                                        return board;
                                                }
                                                else{
                                                        //恢复几个
                                                        it->second.erase(c);
                                                        board = save_board;
                                                        map_row = save_map_row;
                                                        map_col = save_map_col;
                                                        map_cell = save_map_cell;

                                                        for (auto& c : board) {
                                                                for (auto& d : c) {
                                                                        cout << d << " ";
                                                                }
                                                                cout << endl;
                                                        }
                                                        cout << "------------------------------------" << endl;
                                                        continue;
                                                }
                                        }
                                }
                        }
                }
                return {};
        }

        // 改变表格, 接受一个first, 接受一个second, 改变剩下5个查询表
        void update(int first, char tmp,
                vector<vector<char>>& board,
                vector<unordered_set<char>>& map_row,
                vector<unordered_set<char>>& map_col,
                vector<unordered_set<char>>& map_cell,
                map<int, unordered_set<char>>& unset_position_set) {

                int i = first / 10;
                int j = first % 10;
                board[i][j] = tmp;

                //更新状态表
                map_row[i].erase(tmp);//更新行表
                map_col[j].erase(tmp);//更新列表
                map_cell[cell_pos[i / 3][j / 3]].erase(tmp);//更新格表

                //更新查询表,只需要更新i行，j列，x格
                for (int k = 0; k < 9; ++k) { // 更新i行
                        if (board[i][k] == '.') {
                                int s = 10 * i + k;
                                unset_position_set[s].erase(tmp);
                        }
                }

                for (int k = 0; k < 9; ++k) {
                        if (board[k][j] == '.') { //更新j列
                                int s = 10 * k + j;
                                unset_position_set[s].erase(tmp);
                        }
                }

                for (int row = (i / 3) * 3; row < (i / 3 + 1) * 3; ++row) { //更新x格
                        for (int col = (j / 3) * 3; col < (j / 3 + 1) * 3; ++col) {
                                if ((row != i || col != j) && board[row][col] == '.') {
                                        int s = 10 * row + col;
                                        unset_position_set[s].erase(tmp);
                                }

                        }
                }

                unset_position_set.erase(first);//将元素删除
        }
};
