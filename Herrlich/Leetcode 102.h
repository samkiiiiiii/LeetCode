class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

	// 建议背诵的标准解法, 正向queue, 逆向则为stack
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()){
            int n = my_queue.size();
            vector<int> tmp;
            for(int i = 0;i<n;++i){
                TreeNode* node = my_queue.front();
                my_queue.pop();
                if(node->left) my_queue.push(node->left);
                if(node->right) my_queue.push(node->right);
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};