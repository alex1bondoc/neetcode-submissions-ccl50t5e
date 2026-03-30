class Solution:
    def isHappy(self, n: int) -> bool:
        memo = set()
        while n != 1 and n not in memo:
            memo.add(n)
            x = 0
            while n:
                digit = n % 10
                x += digit * digit
                n //= 10
            n = x
            print(n)
        return n == 1