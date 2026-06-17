codes={'alpha':'ok','beta':'wait'}
new_labels={'alpha':'red','beta':'blue'}
print({new_labels[k]:v for k,v in codes.items()})
