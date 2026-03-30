class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        par = []

        def backtrack(k):    
            if k == len(s):
                res.append(par.copy())
                return
            for j in range(k, len(s)):
                ok = True
                l, r = k, j
                while l<r :
                    if s[l] != s[r]:
                        ok = False
                        break
                    l += 1
                    r -= 1
                if ok:
                    par.append(s[k:j + 1])
                    backtrack(j + 1)
                    par.pop()

        backtrack(0)
        return res
    