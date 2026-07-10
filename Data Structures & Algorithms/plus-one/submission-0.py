class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []
        carry = 1
        for digit in reversed(digits):
            res.append((digit + carry) % 10)
            if digit == 9:
                carry = 1
            else:
                carry = 0
        if carry:
            res.append(carry)
        res.reverse()
        return res