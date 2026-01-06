def rotate_list(a,k):
   
    l1=[]
    l2=[]

    if len(a) == 0:
        return []

    k= k % len(a)   #normalizzo k per gestire k > len(a)

    if k>0:
        for i in range(len(a)):
            if i < len(a)-k:        #appendo i primi elementi 
                l1.append(a[i])
                
            else:
                l2.append(a[i])     #appendo gli ultimi k-elementi

        return l2+l1
                
    elif k<0:
        k=-k
        for i in range(len(a)):
            if i < k:
               l1.append(a[i])
            else:
               l2.append(a[i])

        return l2+l1
    

a=[1,2,3,4,5]
k=-2
print(rotate_list(a,k))

#Costo spaziale: O(n)
#Costo temporale: O(n)