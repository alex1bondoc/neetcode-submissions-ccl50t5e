class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        best = 0
        while l <= r:
            mid = (l + r) // 2
            time = 0
            for i in range(len(piles)):
                s = piles[i] // mid
                if piles[i]%mid != 0:
                    s += 1
                time += s
            if time > h:
                l = mid + 1
            else:
                best = mid
                r = mid - 1
        return best
            