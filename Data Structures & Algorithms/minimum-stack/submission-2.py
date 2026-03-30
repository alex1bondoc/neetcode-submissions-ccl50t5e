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
        if not self.stack:
            return
        elem = self.stack.pop()
        if elem < 0:
            self.min -= elem

    def top(self) -> int:
        if not self.stack:
            return 
        if self.stack[-1] < 0:
            return self.min
        else :
            return self.min + self.stack[-1]

    def getMin(self) -> int:
        return self.min
