#date due liste A e B, restituire la somma dell'insieme 
# di elementi che rappresenta l'intersezione delle due liste

a=[1,2,3,4,5]
b=[4,5,6,7,8]
c=[]
somma=0

for elemento in a:
    if elemento in b:
        c.append(elemento)
        somma+=elemento

print(c)
print(somma)

    
