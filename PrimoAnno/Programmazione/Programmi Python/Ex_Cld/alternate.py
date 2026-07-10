def merge_alternate(a,b):
    lenAB=len(a)
    c=[]
    j=1
    for i in range(lenAB):
        c.append(a[i])   
        c.append(b[i])
    return c


a=[1,3,5,9]
b=[2,4,6,8]

print(merge_alternate(a,b))


#Costo spaziale: O(n)
#Costo temporale: O(n)