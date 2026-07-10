class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charPos = {}
        res = 0
        start = 0
        for i in range(len(s)):
            print(s[i])
            if s[i] in charPos:
                res = max(res, i - charPos[s[i]])
                start = charPos[s[i]] + 1
                charPos[s[i]] = i
            else :
                res = max(res, i - start)
                charPos[s[i]] = i
        return res
