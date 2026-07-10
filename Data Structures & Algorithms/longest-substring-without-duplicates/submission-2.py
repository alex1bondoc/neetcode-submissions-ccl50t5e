class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxi = 0
        r = 0
        l = 0
        isThere = {}
        while r < len(s):
            if s[r] in isThere:
                l = isThere[s[r]] + 1
            isThere[s[r]] = r
            if r- l + 1 > maxi:
                maxi = r - l + 1
            r += 1
        return maxi
        