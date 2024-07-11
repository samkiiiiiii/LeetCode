#include "_include.h"

class Solution {
public:
        string longestPalindrome(string s) {
                int n = s.length();
                if (n == 1) return s;

                int maxlen = 1;
                int begin = 0;
                vector<vector<int>> dp(n, vector<int>(n, 0));

                for (int i = 0; i < n; ++i) {
                        dp[i][i] = true;
                        if (i > 0 && s[i] == s[i - 1]) {
                                dp[i][i - 1] = true;
                                if (maxlen < 2) {
                                        maxlen = 2;
                                        begin = i - 1;
                                }
                        }
                        for (int disp = 2; disp <= i; ++disp) {
                                if (i-disp>=0&&s[i] == s[i - disp]) {
                                        dp[i][i - disp] = dp[i - 1][i - disp + 1];
                                        if (dp[i][i - disp]) {
                                            if(maxlen < disp + 1){
                                                maxlen = disp + 1;
                                                begin = i - disp;
                                            }
                                        }
                                }
                        }
                }

                return s.substr(begin, maxlen);
        }
};