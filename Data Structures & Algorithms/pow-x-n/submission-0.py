class Solution:
    def myPow(self, x: float, n: int) -> float:
        res = 1
        if n < 0:
            n *= -1
            x = 1/x
        while n:
            if n % 2 == 1:
                res *= x
            x = x * x
            n //= 2
        return res