class Solution:
    def isHappy(self, n: int) -> bool:
        def calculate(x):
            sum = 0
            while x:
                sum += (x % 10) * (x % 10)
                x //= 10
            return sum
        slow = n
        fast = n
        while fast != 1:
            slow = calculate(slow)
            fast = calculate(calculate(fast))
            if slow == 1 or fast == 1:
                return True
            if fast == slow:
                return False

        return fast == 1