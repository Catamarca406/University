''' 
Dati due insieme A e B, di interi, scrivere un programma 
che calcola il coefficiente di jaccard definito come:

J(A,B) = (|A intersezione B|)/(|A unione B|)

Esempio: A=[2,5,6,8,7,4], B=[4,5,2,1,4,7,8], Output: |Intersezione| = 5
|Unione| = 7
'''

def intersezione(a,b):
    d1={}
    l1=len(a)
    d2={}
    l2=len(b)

    for i in range(l1):
        if a[i] not in d1:
            d1[a[i]]= 1
        else:
            d1[a[i]] +=1

    
    for i in range(l2):
        if b[i] not in d2:
            d2[b[i]]= 1
        else:
            d2[b[i]] +=1


    intersec=0

    for num in a:
        if num in d1 and num in d2:
            intersec+=1
    return intersec


def unione(a,b):
    union=0
    L=[]
    d1={}

    l1=len(a)

    for i in range(l1):
        a.append(b[i])

    
    l1=len(a)
   
    
    for i in range(l1):
        if a[i] not in d1:
            d1[a[i]]= 1
        else:
            a[i]+=1
    
    
    for elem in a:
        if (elem in d1) and (elem not in L):
            L.append(elem)
            union+=1
            
    return union




A=[2,5,6,8,7,4] 
B=[4,5,2,1,4,7,8]
intersec=intersezione(A,B)
union=unione(A,B)

if union != 0:
    jaccard= intersec/union
    print(jaccard)