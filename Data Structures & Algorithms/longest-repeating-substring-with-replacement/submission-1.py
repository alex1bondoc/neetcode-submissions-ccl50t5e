class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        sol = 0
        count  = {}
        l = 0
        maxi = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r],0)
            maxi = max(maxi, count[s[r]])
            while (r - l + 1) - maxi > k:
                count[s[r]] -= 1
                l += 1
            sol = max(sol, r - l + 1)

        return sol       