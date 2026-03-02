def deep(a):

    total=0
    j=0
    
    for i in range(len(a)):
        if type(a[i]) == int or type(a[i]) == float:       
            total+=a[i]
            j+=1

        elif type(a[i]) == list:
            t=deep(a[i])
            total+=t[0]
            j+=t[1]
            
    
    return (total,j)

def deep_mean(a):
    somma,conto = deep(a)
    return somma/conto

a=[1,2,3,'a',[4,1],0,[0,[7],0],['a','b','c'],[1.3]]
print(deep_mean(a))

#Costo spaziale: O(n)
#Costo temporale: O(n)

