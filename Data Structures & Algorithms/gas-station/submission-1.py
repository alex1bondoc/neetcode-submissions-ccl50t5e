class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        maxi = gas[0] - cost[0]
        index = 0
        for i in range(1, len(gas)):
            if gas[i] - cost[i] > maxi:
                maxi = gas[i] - cost[i]
                index = i
        return index
