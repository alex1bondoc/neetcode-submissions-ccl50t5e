class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = l + (r - l) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else :
                r = mid
        pivot = l
        l = 0
        r = len(nums) - 1
        if target <= nums[r] and target >=nums[pivot] :
            l = pivot
        else:
            r = pivot - 1
        while l<=r:
            mid = l + (r - l) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                r = mid - 1
            else :
                l = mid + 1

        return -1