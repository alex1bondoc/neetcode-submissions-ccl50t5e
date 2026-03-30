class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList or beginWord == endWord:
            return 0
        words = set(wordList)
        queue = deque([(beginWord, 1)])
        res = 0
        while queue:
            node, steps = queue.popleft()
            if node in words:
                words.remove(node)
            for i in range(len(node)):
                for j in range(97, 123):
                    if chr(j) == node[i]:
                        continue
                    
                    nei = node[:i] + chr(j) + node[i + 1:]
                    if nei in words:
                        if nei == endWord:
                            return steps + 1
                        queue.append((nei, steps + 1))        
        return 0