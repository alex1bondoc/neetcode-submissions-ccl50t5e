class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        visited = set()
        res = []
        def back(k, j) :
            if k > len(nums):
                return 
            res.append([nums[i] for i in visited])

            for i in range(j, len(nums)):
                if i not in visited:
                    visited.add(i)
                    back(k + 1, i)
                    visited.remove(i)
        back(0, 0)
        return res
        