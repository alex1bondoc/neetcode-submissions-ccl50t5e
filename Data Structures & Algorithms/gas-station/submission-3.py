class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        index = 0
        maxSum = -1001
        s = -1
        sol = 0
        for i in range(len(gas)):
            if s < 0:
                s = 0
                index = i
            s += gas[i] - cost[i]
        return index
