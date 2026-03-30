class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countT = {}
        for c in t:
            countT[c] = countT.get(c, 0) + 1
        res = (0, -1)
        resLen = float("inf")
        have = 0
        need = len(countT)
        window = {}
        l = 0
        for i in range(len(s)):
            print(window, countT)
            c = s[i]
            if c in countT:
                window[c] = window.get(c, 0) + 1
                if window[c] == countT[c]:
                    have += 1
            print(have)
            while have == need:
                if i - l + 1 < resLen:
                    res = (l, i)
                    resLen = i - l + 1
                if s[l] in countT:
                    window[s[l]] -= 1
                    if window[s[l]] + 1 == countT[s[l]]:
                        have -= 1
                l += 1
        return "" if resLen == float("inf") else s[res[0]:res[1] + 1]