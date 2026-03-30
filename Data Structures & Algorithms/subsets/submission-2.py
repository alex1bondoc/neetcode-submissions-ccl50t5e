class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        aux = [0] * len(nums)
        result = []
        ordn = [-11] * n
        def backtracking(k):
            if k <= n:
                r = []
                for i in range(k):
                    r.append(ordn[i])
                result.append(r)
            
            for i in range( n):
                if aux[i] == 0 and nums[i] >   ordn[k - 1]:
                    aux[i] = 1
                    ordn[k] = nums[i]
                    backtracking(k + 1)
                    aux[i] = 0
                    ordn[k] = -1
        backtracking(0)
        return result