class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        inDegree = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for src, dst in prerequisites:
            adj[src].append(dst)
            inDegree[dst] += 1

        final = 0
        res = []
        queue = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)
        
        while queue:
            node = queue.popleft()
            final += 1
            res.append(node)
            for nei in adj[node]:
                inDegree[nei] -= 1
                if inDegree[nei] == 0:
                    queue.append(nei)
        
        if final == numCourses:
            return res[::-1]
        return []