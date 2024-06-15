class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort()
        output = []
        start = intervals[0][0]
        end = intervals[0][1]
        for i in range(1,len(intervals)):
            if intervals[i][0]> end:
                output.append([start,end])
                start=intervals[i][0]
                end = intervals[i][1]
            else:
                end = max(end,intervals[i][1])
        output.append([start,end])
        return output

