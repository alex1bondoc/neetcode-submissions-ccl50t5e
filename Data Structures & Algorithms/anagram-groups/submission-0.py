class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash = {}
        for str in strs:
            counter = [0] * 26
            for c in str:
                counter[ord(c) - ord('a')] += 1
            key = tuple(counter)
            if key in hash:
                hash[key].append(str)
            else :
                hash[key] = [str]
        solution = []
        for key in hash.keys():
            solution.append(hash[key])
        return solution