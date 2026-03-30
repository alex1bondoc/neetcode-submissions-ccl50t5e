class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        sorted_nums = sorted(nums)
        res = []
        cur = []
        def backtrack(last_index):

            res.append(cur.copy())
                
            for i in range(last_index + 1, len(nums)):
                if i > last_index + 1 and sorted_nums[i] == sorted_nums[i - 1]:
                    continue

                cur.append(sorted_nums[i])
                backtrack(i)
                cur.pop()
                    


        backtrack(-1)
        return res        
