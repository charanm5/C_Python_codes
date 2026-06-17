from datetime import date

class Person:
    def __init__(self, name, birth_year):
        self.name = name
        self.birth_year = birth_year

    def age(self):
        return date.today().year - self.birth_year

p = Person("Alice", 2000)
print(f"{p.name} is {p.age()} years old.")
