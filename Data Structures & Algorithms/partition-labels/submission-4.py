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
            j = l + 1

            while j < r:
                print(l, r, s[j])
                r = max(last[s[j]], r)
                j += 1
            print(s[l], s[r])
            res.append(r - l + 1)
            l = r + 1
        return res