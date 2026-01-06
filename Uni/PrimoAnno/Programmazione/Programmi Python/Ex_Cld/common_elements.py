def common_elements(a,b):
    
    l=[]
    seen=set()

    for elem in a:
        if (elem in b) and (elem not in seen):
            l.append(elem)
            seen.add(elem)


    return l    



a=[1,2,3,4] 
b=[3,4,5,6]
print(common_elements(a,b))

#Costo spaziale: O(n*m)
#Costo temporale: O(n)