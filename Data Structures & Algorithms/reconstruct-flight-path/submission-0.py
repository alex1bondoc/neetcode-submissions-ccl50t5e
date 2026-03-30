class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        dic = defaultdict(list)
        for ticket in sorted(tickets)[::-1]:
            source, destination = ticket
            dic[source].append(destination)

        start = "JFK"
        res = []
        def dfs(node):
            while dic[node]:
                dst = dic[node].pop()
                dfs(dst)
            res.append(node)

        dfs(start)
        return res[::-1]