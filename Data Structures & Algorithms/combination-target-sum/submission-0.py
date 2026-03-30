class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        def backtracking(k, cur, total):
            if total == target:
                res.append(cur.copy())
                return 
            if total > target:
                return 
            
            
            for i in range(len(nums)):
                if len(cur) == 0  or nums[i] >= cur[-1]:
                    cur.append(nums[i])
                    backtracking(k + 1, cur, total +  nums[i])
                    cur.pop()
        backtracking(0, [], 0)
        return res