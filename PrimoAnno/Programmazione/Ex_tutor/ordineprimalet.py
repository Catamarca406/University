'''
Progettare una funzione che rimuove da una stringa a in input tutti i caratteri che non sono in ordine
lessicografico con i precedenti a partire dal primo simbolo. Dopo l'operazione a risulterà ordinata
lessicograficamente.

Esempio: Sia a = "ddabeceffgfh", la funzione deve modificare a in modo che essa rappresenti la
stringa "ddeeffgh".
'''

def ordLes(a):

    n=len(a)
    i=1
    max=a[0]
    a=list(a)

    for i in range(1,n):
        if a[i] < max:
            a[i] = None
            i+=1
        else:
            max=a[i]

    a=a.replace(None,"")
    return a 


a="ddabeceffgfh"
print(ordLes(a))