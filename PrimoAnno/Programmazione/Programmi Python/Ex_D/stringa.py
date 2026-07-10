#data una stringa con len n e un carattere 'c'ordinare tutte le parole che iniziano per c
#in ordine lessicografico

def ord_char(a,c):
    
    l=[]
    l2=[]

    for i in range(len(a)):
        if (a[i] == c) and (a[i-1] ==' ' or i == 0):
            while a[i] != ' ':
                l.append(a[i])
                i+=1
            l2.append(l)
            l=[] 
    
    print("prima:",l2)

    l2.sort()
    print("dopo:",l2)

    s=""
    for i in range(len(l2)):
        for j in range(len(l2[i])):
            s.join(l2[i][j])
            s = s.join(' ')
    
    print("stringa ordinata:",s)

    
    return s

    

a="ciao ciao a tutti casa come state!"
c='c'

print(ord_char(a,c))

#Costo spaziale: O(n)
#Costo temporale: O(n*n)

