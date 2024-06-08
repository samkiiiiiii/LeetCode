class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()  # Sort the array to facilitate the two-pointer approach

        for i, a in enumerate(nums):
            if i > 0 and a == nums[i - 1]:
                continue  # Skip duplicates for the 'a' value

            l, r = i + 1, len(nums) - 1  # Two pointers
            while l < r:
                threeSum = a + nums[l] + nums[r]
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])  # Append the correct triplet
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:  # Skip duplicates for 'l' value
                        l += 1
        return res