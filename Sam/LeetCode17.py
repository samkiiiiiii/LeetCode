class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        
        phone_map = {
            '2': 'abc', '3': 'def', '4': 'ghi',
            '5': 'jkl', '6': 'mno', '7': 'pqrs',
            '8': 'tuv', '9': 'wxyz'
        }
        
        def backtrack(index, path):
            # When the path length equals the digits length, add the combination to the result
            if len(path) == len(digits):
                combinations.append("".join(path))
                return
            
            # Get the letters that the current digit can represent
            possible_letters = phone_map[digits[index]]
            
            # Iterate through all letters and continue the backtrack
            for letter in possible_letters:
                path.append(letter)
                backtrack(index + 1, path)
                path.pop()  # backtrack
        
        combinations = []
        backtrack(0, [])
        return combinations