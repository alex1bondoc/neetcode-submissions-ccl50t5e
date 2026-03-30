class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charPos = {}
        res = 0
        start = 0
        for i in range(len(s)):
            if s[i] in charPos and charPos[s[i]] + 1 > start:
                start = charPos[s[i]] + 1
            charPos[s[i]] = i
            res = max(res, i - start + 1)
        return res