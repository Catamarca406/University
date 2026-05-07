def second_max(a):
    
    if(len(a)<2):
        return None    
    
    check_equals=0
    eq=a[0]
    
    for i in range(1,len(a)):
        if eq==a[i]:
            check_equals=1
        else:
            check_equals=0

    if check_equals==1:
        return None
    
    
    act_max=0

    for elem in a:
        if act_max<=elem:
            act_max=elem
    
    scn_max=0

    for elem in a:
        if (scn_max<= elem) and (elem != act_max):
            scn_max=elem

    
    
    return scn_max


a=[10,5,2,5,8,20]
print(second_max(a))


#Costo spaziale: O(1)
#Costo temporale: O(n)