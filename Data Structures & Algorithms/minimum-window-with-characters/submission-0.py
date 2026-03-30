class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == "":
            return ""
        count = {}
        window = {}
        resLen = 1001
        res = [-1, -1]
        for c in t:
            count[c] = 1 + count.get(c, 0)
        l = 0
        have = 0
        need = len(count)
        for r in range(len(s)):
            window[s[r]] = 1 + window.get(s[r], 0)
            if window.get(s[r], 0) == count.get(s[r], 0):
                have += 1
            while have == need:
                if r - l + 1 < resLen:
                    resLen = r - l + 1
                    res = s[l:r + 1]
                window[s[l]] -= 1
                if count.get(s[l],0) != 0 and window.get(s[l], 0) < count.get(s[l],0):
                    have -= 1
                l += 1
        if resLen == 1001:
            return ""
        return res

            