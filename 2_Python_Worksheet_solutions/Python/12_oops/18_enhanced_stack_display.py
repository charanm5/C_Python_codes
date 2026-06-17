class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def display(self):
        print(self.items)

s = Stack()
s.push(1)
s.push(2)
s.display()
