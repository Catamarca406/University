def sort_by_occurences(a):
    d={}
    lenA=len(a)

    for elem in a:              #conto le occorrenze
        if elem not in d:
            d[elem]=1
        else:
            d[elem]+=1

    l=list(d)              # "casto" il dizionario in lista
    
    l.sort(reverse=True)   # ordino gli elementi del dizionario
    
    result =''.join(l)     # unisco i singoli caratteri della lista in una stringa

    return result

a=')-:))-'
print(sort_by_occurences(a))
