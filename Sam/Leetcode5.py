class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""


        def recursive(s,left, right):

            while left>=0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            print ([right-left -1,s[left+1:right]])
            return [right-left -1,s[left+1:right]]

        max_length = 0
        result = ""

        for i in range(len(s)):
            len1, substr1 = recursive(s, i, i)
            len2, substr2 = recursive(s, i, i + 1)

            if len1 > max_length:
                max_length = len1
                result = substr1
            if len2 > max_length:
                max_length = len2
                result = substr2

        return result














