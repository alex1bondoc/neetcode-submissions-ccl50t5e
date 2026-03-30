class MinStack:

    def __init__(self):
        self.list = []
        self.mini = []
    def push(self, val: int) -> None:
        if len(self.list) == 0:
            self.list.append(val)
            self.mini.append(val)
        else:
            self.list.append(val)
            self.mini.append(min(val, self.getMin()))
        

    def pop(self) -> None:
        self.list.pop()
        self.mini.pop()
    def top(self) -> int:
        return self.list[ - 1]

    def getMin(self) -> int:
        return self.mini[ - 1]
