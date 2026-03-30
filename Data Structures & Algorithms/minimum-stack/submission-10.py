class MinStack:

    def __init__(self):
        self.stack = []
        self.min = float("inf")
    def push(self, val: int) -> None:
        if not self.stack:
            self.min = val
            self.stack.append(0)
        else :
            self.stack.append(val - self.min)
            self.min = min(self.min, val)
    def pop(self) -> None:
        if self.stack[-1] < 0:
            self.min = self.min - self.stack[-1]
        self.stack.pop()
    def top(self) -> int:
        if self.stack[-1] > 0:
            return self.stack[-1] + self.min
        else :
            return self.min
    def getMin(self) -> int:
        return self.min
