class Solution:
    def countBits(self, n: int) -> List[int]:
        res = []
        res.append(0)
        offset = 1
        for i in range(1, n + 1):
            if offset * 2 == i:
                offset = i
            print(i - offset)
            res.append(res[i - offset] + 1)
        return res