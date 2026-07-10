class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        dic = {}
        for task in tasks:
            dic[task] = 1 + dic.get(task, 0)
        order = [-val for key, val in dic.items()]
        heapq.heapify(order)
        res = 0
        aux = []
        while order[0] != 0:
            cnt = 0
            for i in range(len(order)):
                if order[i] < 0:
                    res += 1
                    cnt += 1
                    order[i] += 1
                    aux.append("da")
                else :
                    break
            if order[0] == 0:
                continue
            while cnt <= n:
                res += 1
                cnt += 1
                aux.append("iddle")
        print(aux)
        return res