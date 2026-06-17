class ShoppingCart:
    def __init__(self):
        self.total_price = 0

    def add(self, qty, price):
        self.total_price += qty * price

    def total(self):
        return self.total_price

cart = ShoppingCart()
cart.add(2, 200)
cart.add(5, 20)
print(cart.total())
