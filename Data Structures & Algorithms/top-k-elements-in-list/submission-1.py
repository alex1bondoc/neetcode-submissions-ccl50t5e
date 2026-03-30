class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        vec = [[] for _ in range(1001)]
        dic = {}
        for num in nums:
            if num not in dic:
                dic[num] = 0
            else :
                vec[dic[num]].remove(num)
            dic[num] += 1
            vec[dic[num]].append(num)
        res = []
        for i in range(1000, -1, -1):
            while vec[i]:
                res.append(vec[i].pop())
                k -= 1
                if k == 0:
                    return res
        return []
