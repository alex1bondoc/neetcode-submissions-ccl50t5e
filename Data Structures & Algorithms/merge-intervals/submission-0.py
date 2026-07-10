class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key= lambda i: i[0])
        res = []
        for interval in intervals:
            if not res:
                res.append(interval)
            else :
                if interval[0] <= res[-1][1]:
                    res[-1][1] = interval[1]
                else :
                    res.append(interval)
        return res