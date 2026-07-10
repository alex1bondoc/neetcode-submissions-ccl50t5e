class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        hand.sort()
        counter = {}
        if len(hand) % groupSize :
            return False
        groups = 0
        for elem in hand:
            counter[elem] = counter.get(elem,0) + 1
        print(counter)
        for elem in hand:
            if counter[elem] == 0:
                continue
            for j in range(elem, elem + groupSize):
                if counter[j] == 0:
                    return False
                counter[j] = counter[j] - 1

            groups += 1
            if groups == len(hand) // groupSize:
                return True
        return False