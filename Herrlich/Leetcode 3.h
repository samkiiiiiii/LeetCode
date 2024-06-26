#include "_include.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        if (n == 0 || n == 1) return n;
        
//   记忆表
        unordered_map<char, int> myMap;
        int i = 0, j = 1;
        int tmpAns = 1;
        myMap[s[i]] = i;
        while(i < j && j < n) {
            if (myMap.find(s[j]) == myMap.end()) {
                myMap[s[j]] = j;
                j++;
                tmpAns++;
                continue;
            }

//	开滑
            int k = i;
            while(k <= myMap[s[j]]) {
                myMap.erase(s[k++]);
            }

//     记录结果
            tmpAns = j - i;
            i = k;
            ans = ans > tmpAns ? ans : tmpAns;
            tmpAns = j - k + 1;
            j++;
        }
        return ans;
    }
};