d={'a':100,'b':200,'c':300}
lst=['b','c','d']
print({k:d[k] for k in lst if k in d})
