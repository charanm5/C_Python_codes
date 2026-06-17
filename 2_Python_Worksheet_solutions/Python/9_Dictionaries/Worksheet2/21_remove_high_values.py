d={'a':5,'b':10,'c':15,'d':'big'}
limit=10
print({k:v for k,v in d.items() if not isinstance(v,(int,float)) or v<=limit})
