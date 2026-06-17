orders=['latte','espresso','latte','tea','espresso','latte']
count={}
for o in orders: count[o]=count.get(o,0)+1
print(count)
