class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        sol = 0
        while l <= r:
            mid = (l + r) // 2
            hours = h
            for pile in piles:
                print(hours)
                hours = hours - (pile // mid + (1 if pile % mid != 0 else 0))
            print(hours, mid)
            if hours >= 0:
                sol = mid
                r = mid - 1
            else :
                l = mid + 1
        return sol