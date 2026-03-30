class PrefixTree:

    def __init__(self):
        self.children = {}
        self.end = False

    def insert(self, word: str) -> None:
        root = self
        for i in range(len(word)):
            if word[i] not in root.children:
                root.children[word[i]] = PrefixTree()
            root = root.children[word[i]]
            if i == len(word) - 1:
                root.end = True
            
    def search(self, word: str) -> bool:
        root = self
        for i in range(len(word)):
            if word[i] not in root.children:
                return False
            root = root.children[word[i]]
        if root.end == True:
            return True
        return False 

    def startsWith(self, prefix: str) -> bool:
        root = self
        for i in range(len(prefix)):
            if prefix[i] not in root.children:
                return False
            root = root.children[prefix[i]]
        return True