class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        nrZero = 0
        prod = 1
        for num in nums:
            if num == 0:
                nrZero += 1
            else :
                prod *= num
        if nrZero > 1:
            return [0] * len(nums)
        elif nrZero == 1:
            rez = []
            for num in nums:
                if num == 0:
                    rez.append(prod)
                else :
                    rez.append(0)
            return rez
        else :
            return [prod // x for x in nums]

        