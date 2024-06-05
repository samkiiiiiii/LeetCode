class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        output = []
        length = len(s)
        i = length - 1

        while i >= 0:
            if s[i] == " ":
                i -= 1
            else:
                start = i
                while i >= 0 and s[i] != " ":
                    i -= 1
                output.append(s[i + 1:start + 1])
        
        return ' '.join(output)





        # method 1
        # text = s.split()
        # text.reverse()
        # return ' '.join(text)