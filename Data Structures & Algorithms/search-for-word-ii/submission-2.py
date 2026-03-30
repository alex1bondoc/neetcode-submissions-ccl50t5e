class WordDictionary:

    def __init__(self):
        self.dic = {}
        self.end = False
        self.index = 0
        self.val = ""
    def addWord(self, word: str, index) -> None:
        root = self
        for i in range(len(word)):
            if word[i] not in root.dic:
                root.dic[word[i]] = WordDictionary()
                root.dic[word[i]].val = word[i]
            root = root.dic[word[i]]
            if i == len(word) - 1:
                root.end = True
                self.index = index

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


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = WordDictionary()
        for i in range(len(words)):
            trie.addWord(words[i], i)
        res = []
        word = []
        def backtrack(i, j, node):
            if not node:
                return 
            board[i][j] = "#"
            if node.end == True and node.index != -1:
                node.index = -1
                res.append("".join(word))
            di = [1,0,-1,0]
            dj = [0,1,0,-1]
            for k in range(4):
                ii = i + di[k]
                jj = j + dj[k]
                if ii >=0 and jj >=0 and ii < len(board) and jj < len(board[0]):
                    word.append(board[ii][jj])
                    backtrack(ii, jj, node.dic.get(board[ii][jj], None))
                    word.pop()
            board[i][j] = node.val

        for i in range(len(board)):
            for j in range(len(board[0])):
                word.append(board[i][j])
                backtrack(i, j, trie.dic.get(board[i][j], None))
                word.pop()
        return res




