d={'sun':1,'sunny':2,'rain':3}
substring='sun'
print({k:v for k,v in d.items() if substring not in k})
