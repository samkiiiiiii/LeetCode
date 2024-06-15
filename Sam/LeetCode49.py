class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = {}
        for s in strs:
            count = [0] * 26  # Initialize count of each letter to 0

            for c in s:
                count[ord(c) - ord('a')] += 1  # Count frequency of each letter in the string

            key = tuple(count)  # Create a tuple key from the count list
            if key not in res:
                res[key] = []  # Initialize the list at this key if it doesn't already exist
            res[key].append(s)  # Append the current string to the list corresponding to this key

        return list(res.values())  # Convert the values view to a list before returning