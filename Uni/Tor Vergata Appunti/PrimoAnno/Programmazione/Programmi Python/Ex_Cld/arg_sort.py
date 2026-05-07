def arg_sort(a):
    l=[]

    for i in range(len(a)):
        l.append((a[i],i))
    
    l.sort(key=lambda x:x[0])

    
    l2=[]
    for i in range(len(l)):
        l2.append(l[i][1])    
   
    return l2

a=[8,1,4,3,7]
print(arg_sort(a))


#Costo spaziale: O(n)
#Costo temporale: O(n log n)