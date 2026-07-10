L= [1,25,4,3,-1,13,87,10]
print("Lista prima di MergeSort",L)
i=0
f=len(L)-1

def Merge(L,i,f1,f2):
    X=[] 
    k1=i
    k2=f1+1

    while k1<=f1 and k2<=f2:
        if L[k1]<L[k2]:
            X.append(L[k1])
            k1+=1
        else:
            X.append(L[k2])
            k2+=1


    while k1<=f1:
        X.append(L[k1])
        k1+=1


    while k2<=f2:
        X.append(L[k2])
        k2+=1
    h=0
    for j in range(i,f2+1):
        
        L[j]=X[h]
        h+=1

    return L

# Merge costa O(n) perché ad ogni iterazione consuma uno e un solo elemento di 
# una delle due sottoliste di L, costo preciso: O(n+m), prendo il maggiore quindi O(n).

def MergeSort(L, i, f):
    if(i < f):
        m = (i+f)//2
        MergeSort(L,i,m)
        MergeSort(L,m+1,f)
        Merge(L,i,m,f)

MergeSort(L,i,f)

print("Lista dopo MergeSort",L)



def RicercaBinariaA(L,i,j,a):
    if(i>j):
        return -1

    m=(i+j)//2

    if(L[m]==a):
        return m
    
    if(L[m]>a):
        if(L[m-1]<a):
            
            return m
        else:
            return RicercaBinariaA(L,i,m-1,a)
            
    else:
        return RicercaBinariaA(L,m+1,j,a)

    

def RicercaBinariaB(L,i,j,b):
    if(i>j):
        return -1

    m=(i+j)//2
    
    if(L[m]==b):
        return m
    
    if(L[m]< b):
        if(L[m+1]> b):
            return m
        else:
            
            return RicercaBinariaB(L,m+1,j,b)
    else:
        return RicercaBinariaB(L,i,m-1,b)


a=5         #inizio intervallo
b=10        #fine intervallo

i=0
j=len(L)-1


A=RicercaBinariaA(L,i,j,a)
B=RicercaBinariaB(L,i,j,b)

X= (B-A)+1

print(f"Gli elementi compresi tra:{B} e {A} sono: {X}")

