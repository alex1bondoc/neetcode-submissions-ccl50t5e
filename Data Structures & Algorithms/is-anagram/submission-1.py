class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        chars = {}
        cnt = 0
        for c in s:
            if c not in chars:
                chars[c] = 1
                cnt += 1
            else:
                chars[c] += 1
        for c in t:
            if c not in chars:
                return False
            else :
                chars[c] -= 1
                if chars[c] == 0:
                    cnt -= 1
                if chars[c] < 0:
                    return False
        return cnt == 0
        