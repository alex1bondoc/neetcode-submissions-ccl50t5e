class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        aux = nums[0:k]
        minHeap = heapq.heapify(aux)

        for i in range(k, len(nums)):
            if nums[i] <= aux[0]:
                continue
            else :
                heapq.heappop(aux)
                heapq.heappush(aux, nums[i])
        return aux[0]
