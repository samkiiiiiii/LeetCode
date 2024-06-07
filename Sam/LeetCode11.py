class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left = 0
        right = len(height)-1
        area = 0

        while right>left:
            curr_area = min(height[left], height[right]) * (right - left)
            if curr_area > area:
                area = curr_area

            if height[right] > height[left]:
                left += 1
            else:
                right -= 1

        return area
