class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        def back(k, cur, total):
            if total == target:
                res.append(cur.copy())
                return
            elif k >= len(nums) or total > target:
                return
            cur.append(nums[k])
            back(k, cur, total + nums[k])
            cur.pop()
            back(k + 1, cur, total)
        back(0, [], 0)
        return res