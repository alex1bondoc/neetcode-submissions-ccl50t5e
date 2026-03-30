class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sorted_nums = sorted(nums)
        res = []
        cur = []
        def backtrack(k, last_index):
            if k > len(nums):
                return 
            if k <= len(nums):
                res.append(cur.copy())
            i = last_index + 1
            while i < len(nums):
                cur.append(sorted_nums[i])
                backtrack(k + 1, i)
                cur.pop()
                i += 1
                while i < len(nums) and i > 0 and sorted_nums[i] == sorted_nums[i - 1]:
                    i += 1
                    


        backtrack(0, -1)
        return res        
