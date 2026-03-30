class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        adj = [[] for i in range (n + 1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        visited = [False] * (n + 1)
        cycle = set()
        self.start = -1
        def dfs(node, parent):
            if visited[node]:
                self.start = node
                return True
            visited[node] = True
            for neighbor in adj[node]:
                if neighbor == parent:
                    continue
                if dfs(neighbor, node):
                    if self.start != -1:
                        cycle.add(node)
                    if node == self.start:
                        self.start = -1
                    return True
            return False 


        dfs(1, -1)
        for u, v in reversed(edges):
            if u in cycle and v in cycle:
                return [u, v]

        return []
