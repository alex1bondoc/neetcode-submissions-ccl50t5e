class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dic = {}
        for task in tasks:
            dic[task] = 1 + dic.get(task, 0)
        order = [-val for key, val in dic.items()]
        heapq.heapify(order)
        order1 = []
        while order:
            order1.append(heapq.heappop(order))
        res = 0
        aux = []
        print(order1)
        while order1[0] != 0:
            cnt = 0
            for i in range(len(order1)):
                if order1[i] < 0 and cnt <= n:
                    res += 1
                    cnt += 1
                    order1[i] += 1
                    aux.append(order1[i])
                else :
                    break
            if order1[0] == 0:
                continue
            while cnt <= n:
                res += 1
                cnt += 1
                aux.append("iddle")
        print(aux)
        return res