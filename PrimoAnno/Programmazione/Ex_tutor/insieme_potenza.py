'''
Avete in input una lista di elementi, ad esempio: elementi = ["A","B","C"]

Scrivere un programma ricorsivo che stampi tutti i sottoinsiemi 
degli elementi dati in input (ovvero stampare l' Insieme Potenza degli elementi in input)

'''

def insieme_potenza(elem,i):
    n = len(elem)
    

    
    if i==0:
        print([])
        i+=1
    
    if i==1:
        print(elem[0],elem[1])
        i+=1
    
    insieme_potenza(elem,i)





elementi= ["A","B","C"]
i=0
insieme_potenza(elementi,i)