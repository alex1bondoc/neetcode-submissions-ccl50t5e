class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj = {x:[] for x in range(1, n + 1)}
        for l in times:
            u, v, t = l
            adj[u].append((v,t))
        start = k
        total = n
        priority_queue = []
        visited = {}
        heapq.heappush(priority_queue, (0, start))
        visited[start] = 0
        while priority_queue:
            dist, node = heapq.heappop(priority_queue)
            print(dist, node)
            for n in adj[node]:
                v, time = n
                if v not in visited or visited[v] > dist + time:
                    heapq.heappush(priority_queue, (dist + time, v))
                    visited[v] = dist + time
        print(len(visited.keys()), total)
        if len(visited.keys()) != total:
            return -1
        return max(visited.values())

            