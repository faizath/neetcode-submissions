class Deque:
    
    def __init__(self):
        self.size = 0
        self.values = []

    def isEmpty(self) -> bool:
        return self.size == 0

    def append(self, value: int) -> None:
        self.values.append(value)
        self.size += 1

    def appendleft(self, value: int) -> None:
        self.values = [value] + self.values
        self.size += 1

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        else:
            self.size -= 1
            value = self.values[self.size]
            self.values = self.values[0:-1]
            return value

    def popleft(self) -> int:
        if self.isEmpty():
            return -1
        else:
            value = self.values[0]
            self.values = self.values[1:]
            self.size -= 1
            return value
