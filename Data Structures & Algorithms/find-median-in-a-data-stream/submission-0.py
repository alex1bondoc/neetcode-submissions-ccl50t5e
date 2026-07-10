class MedianFinder:

    def __init__(self):
        self.size = 0
        self.maxHeap = []
        self.minHeap = []

    def addNum(self, num: int) -> None:
        self.size += 1
        if not self.maxHeap or -num > self.maxHeap[0]:
            heapq.heappush(self.maxHeap, -num)
        else :
            heapq.heappush(self.minHeap, num)
        if abs(len(self.minHeap) - len(self.maxHeap)) > 1:
            while len(self.minHeap) - len(self.maxHeap) > 1:
                heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
            while len(self.maxHeap) - len(self.minHeap) > 1:
                heapq.heappush(self.minHeap, heapq.heappop(self.maxHeap))
        if len(self.minHeap) >  len(self.maxHeap):
            heapq.heappush(self.maxHeap, -heapq.heappop(self.minHeap))
        print(self.maxHeap, self.minHeap)
    def findMedian(self) -> float:
        if self.size % 2 == 0:
            return (-self.maxHeap[0] + self.minHeap[0]) / 2
        else :
            return -self.maxHeap[0]
        