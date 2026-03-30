class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(p, s) for p, s in zip(position, speed)]
        cars.sort(reverse=True)
        fleets = 1
        stack = []
        time = (target - cars[0][0])/ cars[0][1] 
        for i in range(1, len(cars)):
            p, s = cars[i]
            curTime = (target - p) / s
            if time < curTime:
                fleets += 1
                time = curTime
        return fleets