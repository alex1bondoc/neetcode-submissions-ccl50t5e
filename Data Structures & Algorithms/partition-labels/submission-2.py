class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        first = {}
        last = {}
        for i in range(len(s)):
            if s[i] not in first:
                first[s[i]] = i
            last[s[i]] = i
        l, r = 0, 0
        res = []
        while l < len(s):
            l = first[s[l]]
            r = last[s[l]]
            for j in range(l + 1, r):
                r = max(last[s[j]], r)

            res.append(r - l + 1)
            l = r + 1
        return res