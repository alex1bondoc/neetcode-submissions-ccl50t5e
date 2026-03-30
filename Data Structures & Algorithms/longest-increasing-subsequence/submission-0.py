class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [[0] * (len(nums) + 1) for _ in range(len(nums) + 1)]
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i - 1, -2, -1):
                aux = dp[i + 1][ j + 1]
                if j == -1 or nums[j] < nums[i]:
                    aux = max(aux, dp[i + 1][i + 1] + 1)
                dp[i][j + 1] = aux
        return dp[0][0]