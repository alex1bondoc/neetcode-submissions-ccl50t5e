"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        start = [interval.start for interval in intervals]
        end = [interval.end for interval in intervals]
        start.sort()
        end.sort()
        n = len(intervals)
        s = 0
        e = 0
        cnt = 0
        res = 0
        while s < n:
            if start[s] < end[e]:
                s += 1
                cnt += 1
            else:
                cnt -= 1
                e += 1    
            res = max(res, cnt) 
        return res
