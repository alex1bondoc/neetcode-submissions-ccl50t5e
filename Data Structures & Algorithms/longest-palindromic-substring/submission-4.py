class Solution:
    def longestPalindrome(self, s: str) -> str:
        #manacher
        t = '#' + '#'.join(s) + '#'
        p = [0] * len(t)
        l = 0
        r = 0
        for i in range(len(t)):
            p[i] = min(r - i, p[l + (r - i)]) if i < r else 0
            while (i + p[i] + 1 < len(t) and i - p[i] - 1 >= 0) and (t[i + p[i] + 1] == t[i - p[i] - 1]):
                p[i] += 1
            if i + p[i] > r:
                l, r = i - p[i], i + p[i]
        resLen, center = max((v, i) for i, v in enumerate(p))
        index = (center - resLen) // 2
        return s[index:index + resLen]