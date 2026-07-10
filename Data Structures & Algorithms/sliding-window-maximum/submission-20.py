class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque([])
        l = 0
        res = []
        for i in range(len(nums)):
            while q and nums[q[-1]] <= nums[i]:
                q.pop()
            q.append(i)
            while len(res) <= i - k:
                q.popleft()
            if i >= k - 1:
                res.append(nums[q[0]])
        return res