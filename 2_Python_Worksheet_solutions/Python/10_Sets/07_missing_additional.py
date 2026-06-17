old_hw=['math','science','art']
new_hw=['math','history','science']
print('Missing:',set(old_hw)-set(new_hw))
print('Additional:',set(new_hw)-set(old_hw))
