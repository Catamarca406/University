def unique(a):
    l=[]
    d={}
    seen=set()
    for elem in a:                          #inserisco ogni elemento e le sue occorrenze in un dizionario
        if elem not in d:
            d[elem]=1
        else:
            d[elem]+=1
    
    for elem in a:
        if d[elem]==1 and elem not in seen:         #ho bisogno di seen per mantenere l'ordine originale della lista
            seen.add(elem)
            l.append(elem)
            
    return l

a=[1,2,2,3,4,4,5]
print(unique(a))

#Costo spaziale: O(n)
#Costo temporale: O(n)