class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hs = {}
        ht = {}
        for c in s:
            if c not in hs:
                hs[c] = 1
            else :
                hs[c] += 1
        for c in t:
            if c not in ht:
                ht[c] = 1
            else :
                ht[c] += 1
        if hs == ht:
            return True
        return False
        