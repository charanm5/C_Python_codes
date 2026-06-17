stock={'apples':14,'bananas':22,'rice':12}
query='apples'
print(f'Yes, {query} are in stock!' if query in stock else 'Not in stock')
