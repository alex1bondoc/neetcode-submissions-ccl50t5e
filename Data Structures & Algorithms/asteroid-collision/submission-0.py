class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for asteroid in asteroids:
            stack.append(asteroid)
            while len(stack) >= 2 and stack[-2] > 0  and stack[-1] < 0:
                last = stack.pop()
                penultimate = stack.pop()
                if -last > penultimate:
                    stack.append(last)
                elif -last < penultimate:
                    stack.append(penultimate)
        return stack