'''
Si scriva una funzione, denominata mode , che prenda in input una lista di numeri e restituisca la
lista degli elementi di a che compaiono più frequentemente.
'''

def mode(a):

    d={}
    b=[]
    massimo=0

    
    for elemento in a:
        if elemento in d:
            d[elemento]+=1
        else:
            d[elemento]=1

    listTuple = list(d.items())
    listTuple = sorted(listTuple, key= lambda x: x[1], reverse=True)
    

    b = []

    maxValue = listTuple[0][1]
    i = 0
    while listTuple[i][1] == maxValue:
        b.append(listTuple[i])
        i += 1

    for elemento in a:
        if d.values is massimo:
            #b.append(elemento)
            print(elemento)
            

    return b  

a=[10,24,10,10,24,24,4,4,2,4,5]

print(a)
print(mode(a))
