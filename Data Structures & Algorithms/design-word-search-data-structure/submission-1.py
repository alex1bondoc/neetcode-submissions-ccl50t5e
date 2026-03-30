class WordDictionary:

    def __init__(self):
        self.dic = {}
        self.end = False
    def addWord(self, word: str) -> None:
        root = self
        for i in range(len(word)):
            if word[i] not in root.dic:
                root.dic[word[i]] = WordDictionary()
            root = root.dic[word[i]]
            if i == len(word) - 1:
                root.end = True

    def search(self, word: str) -> bool:
        def dfs(root, level, word) ->bool:
            if level == len(word):
                if root.end == True:
                    return True
                return False
            if word[level] != '.' and word[level] not in root.dic:
                return False
            res = False
            if word[level] == '.':
                for node in root.dic:
                    res = res or dfs(root.dic[node], level + 1, word)
            else :
                res = dfs(root.dic[word[level]], level + 1, word)
            return res
        return dfs(self, 0, word)                
