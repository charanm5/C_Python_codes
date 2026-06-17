def string_stats(s):
    vow=0
    conso=0
    nums=0
    for i in range(len(s)):
        if(s[i].lower() in "aeiou"):
            vow+=1
        elif(s[i].isdigit()):
            nums+=1
        else:
            conso+=1
    return vow,nums,conso
    
vow, nums, conso = string_stats("Hel2lo9world")
print(vow, nums, conso)
