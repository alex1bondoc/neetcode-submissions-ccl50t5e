class CountSquares:

    def __init__(self):
        self.points = {}

    def add(self, point: List[int]) -> None:
        self.points[(point[0], point[1])] = self.points.get((point[0], point[1]), 0) + 1

    def count(self, point: List[int]) -> int:
        x1, y1 = point
        c = 0
        d1 = [(1, -1), (-1, 1), (-1, -1), (1, 1)]
        d2 = [(1, 0), (-1, 0), (0, -1), (0, 1)]
        for point2 in self.points.keys():
            x2, y2 = point2
            if abs(x2 - x1) == abs(y2 - y1) and x2 != x1: 
                print(point, point2)
                for i in range(4):
                    a, b = d1[i]
                    a *= (x2 - x1)
                    b *= (x2 - x1)
                    if (x2 + a, y2) in self.points and (x2, b + y2) in self.points:
                        c += max(self.points[(x2, y2)], self.points[(x2 + a, y2)], self.points[(x2, y2 + b)])
        return c


        
