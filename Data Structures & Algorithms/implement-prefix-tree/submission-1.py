class TrieNode:
    def __init__(self):
        self.map = {}
        self.isFinal = False
class PrefixTree:

    def __init__(self):
        self.node = TrieNode()
    def insert(self, word: str) -> None:
        node = self.node
        for i in range(len(word)):
            c = word[i]
            if c not in node.map:
                node.map[c] = TrieNode()
            node = node.map[c]
        node.isFinal = True

    def search(self, word: str) -> bool:
        node = self.node
        for i in range(len(word)):
            c = word[i]
            if c not in node.map:
                return False
            node = node.map[c]
        return node.isFinal        

    def startsWith(self, prefix: str) -> bool:
        node = self.node
        for i in range(len(prefix)):
            c = prefix[i]
            if c not in node.map:
                return False
            node = node.map[c]
        return True
        