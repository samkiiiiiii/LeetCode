#include "_include.h"

class Solution {
public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
                int n = strs.size();
                vector<vector<string>> res;
                unordered_map<string, vector<string>> myMap;
                for (int i = 0; i < n; ++ i) {
                        string tmp = strs[i];
                        sort(strs[i].begin(), strs[i].end());
                        myMap[strs[i]].push_back(tmp);
                }
                for (auto&c: myMap) {
                        res.push_back(c.second);
                }
                return res;
        }
};