class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hash = set(nums)
        maxLength = 0
        for num in nums:
            if num - 1 not in hash:
                length = 1
                x = num
                while x + 1 in hash:
                    length += 1
                    x += 1
                if length > maxLength :
                    maxLength = length

        return maxLength

