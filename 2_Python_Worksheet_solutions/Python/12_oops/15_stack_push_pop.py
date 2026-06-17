class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

s = Stack()
s.push(10)
s.push(20)
print(s.pop())
