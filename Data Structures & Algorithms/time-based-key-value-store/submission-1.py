class TimeMap:
    def __init__(self):
        self.dic = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.dic:
            self.dic[key] = []
        self.dic[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        v = self.dic.get(key, [])
        l = 0
        r = len(v) - 1
        res = ""
        while l <= r:
            mid = (l + r) // 2
            if v[mid][1] > timestamp:
                r = mid - 1
            else : 
                res = v[mid][0]
                l = mid + 1
        return res