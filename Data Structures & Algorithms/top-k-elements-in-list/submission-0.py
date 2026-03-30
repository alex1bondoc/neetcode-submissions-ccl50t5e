class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        max = 0
        buckets = [set() for _ in range(len(nums) + 1)]
        buckets[0] = set(nums)
        count = {}
        for num in nums: 
            buckets[count.get(num, 0)].remove(num)
            i = count.get(num , 0) + 1
            buckets[i].add(num)
            count[num] = i
            if i > max:
                max = i
        sol = []
        while k > 0 :
            for elem in buckets[max]:
                sol.append(elem)

                k -= 1
                if k == 0:
                    break
            max -= 1
        return sol