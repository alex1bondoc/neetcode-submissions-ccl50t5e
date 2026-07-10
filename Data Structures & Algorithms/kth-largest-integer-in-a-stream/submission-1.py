class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.list = []
        for i in range(k):
            heapq.heappush(self.list, nums[i])
        for i in range(k, len(nums),1):
            if self.list[0] > nums[i]:
                continue
            else :
                heapq.heappop(self.list)
                heapq.heappush(self.list, nums[i])
        print(self.list)

    def add(self, val: int) -> int:
        if val >= self.list[0]:
            heapq.heappop(self.list)
            heapq.heappush(self.list, val)
        return self.list[0]
