class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        left = 0
        check = set()
        max_length = 0
        for right in range(0,len(s)):
            while s[right] in check:
                check.remove(s[left])
                left = left+1
            
            check.add(s[right])
            max_length = max(max_length, right - left + 1)
        return max_length
                

