class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        for string in strs:
            vec = [0] * 26
            for c in string:
                vec[ord(c) - ord('a')] += 1
            if tuple(vec) not in anagrams:
                anagrams[tuple(vec)] = []
            anagrams[tuple(vec)].append(string)
        return list(anagrams.values())