A={'abc','defg','xyz'}
B={'mnopq','rstuv','wxyz'}
for a in A:
    for b in B:
        if len(set(a+b))==26:
            print((a,b))
