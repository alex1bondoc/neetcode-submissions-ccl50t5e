class StockSpanner:

    def __init__(self):
        self.stack = []
        self.cnt = 0

    def next(self, price: int) -> int:
        cnt = 0
        while self.stack and self.stack[-1][1] <= price:
            cnt = self.stack[-1][0]
            self.stack.pop()
        print(self.stack)
        res = self.stack[-1][0] if self.stack else 0
        self.cnt += 1
        self.stack.append((self.cnt, price))
        return self.cnt - res


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)