class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(p, s) for p, s in zip(position, speed)]
        cars.sort(reverse=True)
        fleets = 0
        time = 0
        for p, s in cars:
            curr = (target - p) / s
            if curr > time:
                fleets += 1
                time = curr
        return fleets