class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) == 0:
            return "" 
        res = 0
        resLen = float("inf")
        countT = {}
        for i in range(len(t)):
            countT[t[i]] = countT.get(t[i], 0) + 1
        l = 0
        have = 0
        need = len(countT)
        window = {}
        for r in range(len(s)):
            c = s[r]
            window[c] = window.get(c, 0) + 1
            if c in countT and window[c] == countT[c]:
                have += 1
            while have == need:
                if r - l + 1 < resLen:
                    resLen = r - l + 1
                    res = [l, r]

                window[s[l]] -= 1
                if s[l] in countT  and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        if resLen == float("inf"):
            return
        return s[res[0]:res[1] + 1]
