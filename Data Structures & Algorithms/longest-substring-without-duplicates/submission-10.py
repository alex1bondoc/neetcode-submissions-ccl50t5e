class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charPos = {}
        res = 0
        start = 0
        for i in range(len(s)):
            print(s[i])
            if s[i] in charPos:
                start = charPos[s[i]] + 1
                charPos[s[i]] = i
                res = max(res, i - charPos[s[i]])

            else :
                res = max(res, i - start + 1)
                charPos[s[i]] = i
            print(res)
        return res
