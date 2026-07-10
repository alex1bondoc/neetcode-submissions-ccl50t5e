class Solution:
    def search(self, nums: List[int], target: int) -> int:
        found = -1
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                found = mid
                break
            if nums[mid] > nums[r]:
                if target > nums[r] and target < nums[mid]:
                    r = mid
                else :
                    l = mid + 1
            else :
                if target < nums[mid] and target > nums[l]:
                    r = mid
                else:
                    l = mid + 1

        return found 