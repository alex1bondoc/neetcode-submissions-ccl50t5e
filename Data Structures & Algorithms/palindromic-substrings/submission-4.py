class Solution:
    def countSubstrings(self, s: str) -> int:
        #manacher

        t = '#' + '#'.join(s) + '#'
        n = len(t)
        res = 0

        p = [0] * n
        l, r = 0, 0
        for i in range(n):
            p[i] = min(r - i, p[l + (r - i)]) if i < r else 0
            while (i + p[i] + 1 < n and i - p[i] - 1 >= 0) and t[i + p[i] + 1] == t[i - p[i] - 1]:
                p[i] += 1
            if i + p[i] > r:
                l, r = i - p[i], i + p[i]
        for i in p:
            res += (i + 1) // 2
        return res

            