class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxi = -1
        r = 0
        l = 0
        isThere = set()
        while r < len(s):
            if s[r] in isThere:
                while s[r] in isThere:
                    isThere.remove(s[l])
                    l += 1
            isThere.add(s[r])
            if r- l + 1 > maxi:
                maxi = r - l + 1
            r += 1
        return maxi
        