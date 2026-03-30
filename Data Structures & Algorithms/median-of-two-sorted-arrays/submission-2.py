class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        total = len(nums1) + len(nums2)
        half = total // 2

        l = 0
        r = len(nums1)
        while True:
            i = (l + r) // 2
            j = half - i
            left1 = 0
            if i == 0:
                left1 = float("-infinity")
            else:
                left1 = nums1[i - 1]
            right1 = 0
            if i >= len(nums1):
                right1 = float("infinity")
            else :
                right1 = nums1[i]
            left2 = 0
            right2 = 0
            if j == 0:
                left2 = float("-infinity")
            else :
                left2 = nums2[j - 1]
            if j >= len(nums2):
                right2 =  float("infinity")
            else :
                right2 = nums2[j]
            if left1 <= right2 and left2 <= right1:
                if total % 2 == 1:
                    return min(right1, right2)
                else :
                    return (max(left1, left2) + min(right1, right2)) / 2.0
            elif left1 >  right2:
                r = i - 1
            else:
                l = i + 1 
        return 0.0