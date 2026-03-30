class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points = [[(point[0] * point[0] + point[1] ** 2) ** (1/2), point[0], point[1]] for point in points]
        heapq.heapify(points)
        res = []
        for i in range(k):
            p = heapq.heappop(points)
            res.append([p[1], p[2]])
        return res