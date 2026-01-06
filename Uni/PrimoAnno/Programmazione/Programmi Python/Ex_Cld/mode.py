def mode(a):

    d={}
    seen=set()

    if a == []:
        return None
     
    for elem in a:
        if elem not in d:
            d[elem]=1
        else:
            d[elem]+=1

    abs_max=max(d.values())

    l=[]
    for elem in a:
        if (d[elem]==abs_max) and (d[elem]not in seen):
            seen.add(elem)
            l.append(elem)
    
    return l

a=[10, 24, 10, 10, 24, 24, 4, 4, 2, 4, 5]
print(mode(a))  


#Costo spaziale: O(n)
#Costo temporale: O(n)