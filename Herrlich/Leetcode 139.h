#include "_include.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<int> myset;
        unordered_map<string, bool> word_map;
        for (auto& c : wordDict) {
            word_map[c] = true;
        }
// trie recursion
        return dfs(s, word_map, myset, 0);
    }

    bool dfs(string& s, unordered_map<string, bool>& word_map, unordered_set<int>& myset, int start) {
        if (start == s.length()) {
            return true;
        }

        if (myset.find(start) != myset.end()) {
            return false;
        }

        for (int i = start; i < s.length(); i++) {
            string tmp = s.substr(start, i - start + 1);
            if (word_map.find(tmp) != word_map.end()) {
                if (dfs(s, word_map, myset, i + 1)) {
                    return true;
                }
                myset.insert(i + 1);
            }
        }
        return false;
    }
};