class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        visited = set()
        def back(k, cur):
            if k == len(nums):
                res.append(cur.copy())
                return 
            for i in range(len(nums)):
                if nums[i] not in cur:
                    cur.append(nums[i])
                    back(k + 1, cur)
                    cur.pop()
        back(0, [])
        return res