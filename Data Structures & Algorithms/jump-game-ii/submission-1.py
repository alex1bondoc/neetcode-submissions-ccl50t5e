class Solution:
    def jump(self, nums: List[int]) -> int:
        cnt = 0
        l, r = 0, 0
        while l < len(nums):
            maxi = 0
            for j in range(l, r + 1):
                if j < len(nums):
                    maxi = max(j + nums[j], maxi)
                else :
                    return cnt
            l = r + 1
            r = maxi
            cnt += 1
        return cnt - 1
