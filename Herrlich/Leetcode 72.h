#include "_include.h"

class Solution {
public:
        int minDistance(string word1, string word2) {
                int n1 = word1.length();
                int n2 = word2.length();

                vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
                dp[0][0] = 0;
                for (int i = 1; i <= n1; ++i) {
                        dp[i][0] = i;
                }
                for (int j = 1; j <= n2; ++j) {
                        dp[0][j] = j;
                }

                for (int i = 1; i <= n1; ++i) {
                        for (int j = 1; j <= n2; ++j) {
                                // 状态转移方程
                                // dp[i][j] = dp[i-1][j-1]^s[i] == p[j]
                                // dp[i][j] = dp[i-1][j-1] + 1^s[i]!=p[j] 替换 匹配 dp[i+1][j+1]
                                // dp[i][j] = dp[i-1][j-1] + 1^s[i]!=p[j] 删除 匹配 dp[i+1][j]
                                // dp[i][j] = dp[i-1][j-1] + 1^s[i]!=p[j] 添加 匹配 dp[i][j+1]
                                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                                else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                        }
                }
                return dp[n1][n2];
        }
};