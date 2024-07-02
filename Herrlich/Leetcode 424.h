#include "_include.h"

class Solution {
public:
        int characterReplacement(string s, int k) {
                int n = s.size();
                int res = 0;
                unordered_map<char, int> count_map;

                int start = 0;
                int end = 0;
                int tmp_res = 0;

                while (end < n){

			// sliding window
                        count_map[s[end]] += 1;
                        tmp_res = max(tmp_res, count_map[s[end]]);

                        if ((end - start + 1) - tmp_res > k) {
                                res = max(res, (end - start));
                                count_map[s[start]] -= 1;
                                start += 1;
                                
			// update res
                                tmp_res = 0;
                                for (auto& c : count_map) {
                                        tmp_res = max(tmp_res, c.second);
                                }
                        }
                        end++;
                }
                return max(res, end - start);
        }
};