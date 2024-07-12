class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        n = len(nums)
        dp = [1] * n  
        counts = [1] * n 
        
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        counts[i] = counts[j]
                    elif dp[i] == dp[j] + 1:
                        counts[i] += counts[j]
        
        max_length = max(dp)
        return sum(counts[i] for i in range(n) if dp[i] == max_length)
        

