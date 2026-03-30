class Solution:
    def longestPalindrome(self, s: str) -> str:
        # Two pointer
        resIndex, res = 0, 0
        for i in range(len(s)):
            l = i
            r = i
            cnt = 0
            while l >= 0 and r < len(s) and s[l] == s[r]:
                cnt += 1
                r += 1
                l -= 1
            if cnt * 2 - 1> res:
                res = cnt * 2 - 1
                resIndex = l + 1

            l = i
            r = i + 1
            cnt = 0
            while l >= 0 and r < len(s) and s[l] == s[r]:
                cnt += 1
                l -= 1
                r += 1
            if cnt * 2 > res:
                res = cnt * 2
                resIndex = l + 1
        return s[resIndex:resIndex + res]