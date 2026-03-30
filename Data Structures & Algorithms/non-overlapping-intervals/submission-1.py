class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key= lambda i: i[0])
        cnt = 0
        prevEnd = -50001
        for interval in intervals:
            if interval[0] < prevEnd:
                prevEnd = min(prevEnd, interval[1])
                cnt += 1
            else :
                prevEnd = interval[1]
        return cnt