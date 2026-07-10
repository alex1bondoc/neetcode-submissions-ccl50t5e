class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.size = 0
        self.cache = {}
        self.list = deque()
    def get(self, key: int) -> int:
        return self.cache.get(key, -1)

    def put(self, key: int, value: int) -> None:
        if key not in self.cache:
            if self.size == self.capacity:
                k = self.list[0]
                self.list.popleft()
                self.cache.pop(k)
                self.size -= 1
        self.list.append(key)
        self.cache[key] = value
        self.size += 1
