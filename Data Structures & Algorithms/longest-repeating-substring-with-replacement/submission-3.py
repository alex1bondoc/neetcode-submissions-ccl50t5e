class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        res = 0
        count = {}

        max = 0
        l = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            if count[s[r]] > max:
                max = count[s[r]]
            while r - l + 1 - max > k:
                count[s[l]] -= 1
                l += 1
            if r - l + 1 > res:
                res = r - l + 1
        return res