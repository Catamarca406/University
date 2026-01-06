def remove_duplicates(a):
  
    seen=set()          #set impiega O(1) per ricercare un valore al suo interno, non contiene copie
    l=[]

    for elem in a:
        if elem not in seen:
            seen.add(elem)
            l.append(elem)
      
    return l

a=[5,2,5,1,2,8,1]
print(remove_duplicates(a))

#Costo spaziale: O(n)
#Costo temporale: O(n)