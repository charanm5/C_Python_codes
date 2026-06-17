from itertools import combinations
kids={'Amy','Bob','Cara','Dan','Eva'}
for team in combinations(kids,3):
    print(team)
