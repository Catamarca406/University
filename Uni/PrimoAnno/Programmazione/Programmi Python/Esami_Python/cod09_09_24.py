'''Si scriva una funzione chiamata arg_sort che prenda in input una lista di numeri a e ritorni la lista
degli indici che ordinano a . 
Più precisamente se b è l'output della funzione allora
a[b[0]] <= a[b[1]] <= a[b[2]] <= ...'''


def arg_sort(a):
    a_sorted=[]
    a_sorted=sorted(a)  #Costo temporale O(nlog(n))
    a_index=[]
    t=()

    '''
    for i in range(len(a)):
        for j in range(len(a)):
            if a_sorted[i] == a[j]:
                a_index.append(j)
    print(a_index)

    #Costo temporale: O(n^2)
    #Costo spaziale: O(n)
    '''
    
    
    for i in range(len(a)):
        t=(i,a[i])
        a_index.append(t)
    
    a_index.sort(key=lambda x:x[1]) #Costo temporale: O(nlog(n))
    z=[]

    for i in range(len(a)):
        z.append(a_index[i][0])
    return(z)
    


a=[10,5,3,10.2,-1,8]
print(arg_sort(a))

#Costo temporale: O(nlog(n))
#Costo spaziale: O(n)