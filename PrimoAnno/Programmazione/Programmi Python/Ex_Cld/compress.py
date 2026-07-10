def compress(a):
    d={}
    l=[]

    for elem in range(len(a)):
        if (a[elem] not in d) or (a[elem] != a[elem+1]):
            d[a[elem]]=1
            
        else:
            d[a[elem]]+=1
            
          
    for elem in range(len(d)):
        l.append((elem,d[a[elem]]))

    return l

a=[1,1,1,2,2,3,1,1]
print(compress(a))