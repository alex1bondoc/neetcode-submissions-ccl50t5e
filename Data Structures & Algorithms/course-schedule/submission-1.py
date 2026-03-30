class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        inDegree = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for src, dst in prerequisites:
            adj[src].append(dst)
            inDegree[dst] += 1

        final = 0
        queue = deque()
        for i in range(numCourses):
            if inDegree[i] == 0:
                queue.append(i)
        
        while queue:
            node = queue.popleft()
            final += 1
            for nei in adj[node]:
                inDegree[nei] -= 1
                if inDegree[nei] == 0:
                    queue.append(nei)
        return final == numCourses
