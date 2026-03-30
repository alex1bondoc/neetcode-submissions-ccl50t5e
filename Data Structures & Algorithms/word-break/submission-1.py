class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        aux = [False] * (len(s) + 1)
        n = len(s)
        for i in range(n):
            for word in wordDict:
                same = True
                for j in range(len(word)):
                    if i + j >= n or s[i + j] != word[j]:
                        same = False
                        break
                if same:
                    print(word, i)
                if same and (i == 0 or aux[i - 1] == True):
                    aux[i + j] = True
        print(aux)
        return aux[n - 1]
