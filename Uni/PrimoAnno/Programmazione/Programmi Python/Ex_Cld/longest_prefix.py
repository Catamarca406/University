def longest_prefix_with_words(a,n):
    l=[]
    fb=-1

    if a[n] != ' ':
        for i in range(n,-1,-1):
            if a[i] == ' ':
                fb=i
                break  
    else:
        fb=n    
    
    count_sp=n-fb
    
    for i in range(fb):
        l.append(a[i])

    for i in range(count_sp):
        l.append(' ')


    risultato= "".join(l)
    
    return risultato

    
s="hello world everyone"
n=8
print(f'"{longest_prefix_with_words(s,n)}"')


#Costo spaziale: O(n)
#Costo temporale: O(n)