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
            if val < self.min:
                self.min = val


    def pop(self) -> None:
        if not self.stack:
            return
        top = self.stack.pop()
        if top < 0:
            self.min = self.min - top
        

    def top(self) -> int:
        if not self.stack:
            return 
        top = self.stack[-1]
        if top <= 0:
            return self.min
        return top + self.min

    def getMin(self) -> int:
        return self.min
