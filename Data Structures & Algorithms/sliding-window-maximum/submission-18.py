class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        q = deque()
        for i in range(len(nums)):
            while q and nums[i] > nums[q[-1]]:
                q.pop()
            q.append(i)
            print(q[0], i - k)
            while q[0] <= i - k:
                print("ok")
                q.popleft()
            print(q)
            if i >= k -1 :
                res.append(nums[q[0]])
        return res