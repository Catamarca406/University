def group_by_length(words):
    
    # NON utilizzo il set, perché non devo fare controlli sui duplicati
    d={}
    l=[]
    for elem in words:
        if len(elem) not in d:
            l.append(elem)                  #inserisco la stringa in lista
            d[len(elem)]=l                  #alla len(chiave) inserisco elem(valore)
            l=[]                            #svuoto la lista
        else:
            d[len(elem)].append(elem)

    return d


ls=["prova","numero","mela","perfavore","lota"]
print(group_by_length(ls))

#Costo spaziale: O(n)
#Costo temporale: O(n)