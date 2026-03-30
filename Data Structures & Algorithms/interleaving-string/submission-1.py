class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n, m, l = len(s1), len(s2), len(s3)
        dic = {}
        def rec(i, j, k):
            if k >= l and i >= n and j >= m:
                if (i, j, k) not in dic:
                    dic[(i, j, k)] = True
                return True
            ok = False
            if (i, j, k) in dic:
                return dic[(i, j, k)]
            if i < n and k < l and s1[i] == s3[k]:
                ok = ok or rec(i + 1, j, k + 1)
            if j < m and k < l and s2[j] == s3[k]:
                ok = ok or rec(i, j + 1, k + 1)
            dic[(i, j, k)] = ok
            return ok
        rec(0, 0, 0)
        return dic[(0, 0, 0)]
            