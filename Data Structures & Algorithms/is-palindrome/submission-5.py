class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < len(s) and not (ord('a') <= ord(s[l].lower()) <= ord('z') or ord('0') <=  ord(s[l]) <= ord("9")):
                l += 1
            while r > -1 and not (ord('a') <= ord(s[r].lower()) <= ord('z') or ord('0') <=  ord(s[r]) <= ord("9")):
                r -= 1
            if l >= r:
                break
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1

        return True