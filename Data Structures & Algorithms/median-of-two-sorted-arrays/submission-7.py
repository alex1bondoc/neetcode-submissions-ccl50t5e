class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        if n > m:
            m, n = n, m
            nums1, nums2 = nums2, nums1
        
        l, r = 0, n
        while True:
            i = (l + r) // 2
            j = m - i - 2
            aMax = nums1[i] if i >= 0 else float("-inf")
            aMin = nums1[i + 1] if i + 1 <= n - 1 else float("inf")
            bMax =  nums2[j] if j >=0 else float("-inf")
            bMin = nums2[j + 1] if j + 1 <=  m - 1 else float("inf")
            print(aMax, aMin, bMax, bMin)

            if aMax <= bMin and aMin >= bMax:
                if (n + m) % 2 == 0:
                    return (max(bMax, aMax) + min(aMin, bMin)) / 2
                else :
                    return max(bMax, aMax)
            elif aMax >= bMin:
                r = i - 1
            else:
                l = i + 1
        return 0