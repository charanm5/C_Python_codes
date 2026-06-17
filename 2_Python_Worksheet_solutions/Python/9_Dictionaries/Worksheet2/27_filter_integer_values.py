d={'x':100,'y':'hello','z':200}
print({k:v for k,v in d.items() if isinstance(v,int)})
