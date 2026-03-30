class Solution:
    def climbStairs(self, n: int) -> int:
        one = 1
        two = 1
        for i in range(0,n):
            tmp = one + two
            one = two
            two = tmp
        return one