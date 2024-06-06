class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        start = 0
        curr_sum = 0
        total_sum = 0

        for i in range(len(gas)):
            total_sum = total_sum + (gas[i] - cost[i])
            curr_sum = curr_sum + (gas[i] - cost[i])
            if curr_sum <0 and i<len(gas):
                start = i+1
                curr_sum =0

        if total_sum <0:
            return -1
        else:
            return start
                