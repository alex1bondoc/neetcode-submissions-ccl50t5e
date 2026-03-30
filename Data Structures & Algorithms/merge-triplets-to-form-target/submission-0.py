class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        exist = [False, False, False]
        for triplet in triplets:
            good = True
            for i in range(3):
                if triplet[i] > target[i]:
                    good = False
                    break
            if good:
                for i in range(3):
                    if not exist[i] and target[i] == triplet[i]:
                        exist[i] = True

        return exist[0] and exist[1] and exist[2]