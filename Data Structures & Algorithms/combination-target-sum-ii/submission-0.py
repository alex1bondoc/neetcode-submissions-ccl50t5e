class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = set()
        aux = [-1] * len(candidates)
        def backtracking(k, cur, total):
            if total == target:
                res.add(tuple(cur))
                return 
            if total > target:
                return 
            
            
            for i in range(len(candidates)):
                if len(cur) == 0  or candidates[i] >= cur[-1]:
                    if aux[i] == -1:
                        aux[i] = 1
                        cur.append(candidates[i])
                        backtracking(k + 1, cur, total +  candidates[i])
                        cur.pop()
                        aux[i] = -1
        backtracking(0, [], 0)
        return [list(combination) for combination in res]