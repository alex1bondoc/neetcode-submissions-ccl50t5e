class MedianFinder:

    def __init__(self):
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.minHeap, num)
        if len(self.minHeap) > len(self.maxHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
        if self.maxHeap and self.minHeap and -self.maxHeap[0] >  self.minHeap[0]:
            mini = -heapq.heappop(self.minHeap)
            maxi = -heapq.heappop(self.maxHeap)
            heapq.heappush(self.minHeap, maxi)
            heapq.heappush(self.maxHeap, mini)


    def findMedian(self) -> float:
        print(self.minHeap, self.maxHeap)
        if len(self.minHeap) == len(self.maxHeap):
            return (self.minHeap[0] + -self.maxHeap[0]) / 2
        else:
            return -self.maxHeap[0]