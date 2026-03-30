class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) > n - 1:
            return False
        adj = [[] for i in range(n)]
        for src, dst in edges:
            adj[src].append(dst)
            adj[dst].append(src)
        visited = set()
        def dfs(node, par):
            if node in visited:
                return False
            visited.add(node)
            for nei in adj[node]:
                if nei == par:
                    continue
                if not dfs(nei, node):
                    return False
            return True
        if not dfs(0, -1):
            return False
        if len(visited) == n:
            return True
        return False

