class Note:
    def __init__(self, title, content):
        self.title = title
        self.content = content

n1 = Note("Meeting Notes", "Discuss project status with team.")
n2 = Note("Grocery List", "Eggs, Milk, Bread")

print(n1.title, ":", n1.content)
print(n2.title, ":", n2.content)
