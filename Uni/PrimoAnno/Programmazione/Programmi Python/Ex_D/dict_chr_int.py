'''
data una lista ['a',1,2,4], char-int-int-int
trasforma in tupla gli int e assegna come chiave il char e la tupla come valore ad un dizionario

'''

def char_int(a):
    d={}
    l=[]

    for i in range(1,len(a)): 
            l.append(a[i])

    t=tuple(l)
    d[a[0]]=t
    
    return d

a=['a',1,2,3]
print(char_int(a))



'''
piccolo hint
l=[1,2,3]
t=tuple(l)
print(t)
'''
