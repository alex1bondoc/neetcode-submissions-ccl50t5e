class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        uniq = set(s)
        max = 0
        for u in uniq:
            cnt = 0
            l = 0
            r = -1
            for r in range(len(s)):
                if s[r] != u:
                    if cnt < k:
                        cnt += 1
                    else :
                        while s[l] == u:
                            l += 1
                        l += 1
                if r - l + 1 > max:
                    max = r - l + 1
                
        return max
        