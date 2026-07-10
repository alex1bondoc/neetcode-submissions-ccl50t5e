class MinStack:

    def __init__(self):
        self.stack = []
        self.mini = float("inf")

    def push(self, val: int) -> None:
        if not self.stack:
            self.mini = val
            self.stack.append(val - self.mini)
        else :
            self.stack.append(val - self.mini)
            if val < self.mini:
                self.mini = val        

    def pop(self) -> None:
        if not self.stack:
            return
        pop = self.stack.pop()
        if pop < 0:
            self.mini = self.mini - pop

    def top(self) -> int:
        return self.stack[-1] + self.mini

    def getMin(self) -> int:
        return self.mini
