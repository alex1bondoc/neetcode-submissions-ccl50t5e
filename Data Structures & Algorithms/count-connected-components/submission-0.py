class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for i in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        cnt = 0
        visited = set()
        def dfs(node):
            if node in visited:
                return 
            visited.add(node)
            for nei in adj[node]:
                dfs(nei)
        
        for i in range(n):
            if i not in visited:
                cnt += 1
                dfs(i)
        return cnt