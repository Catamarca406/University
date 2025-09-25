#ex1: Creare un set vuoto e assegnarlo a una variabile
seth={"",}
prova_seth=seth
print(type(prova_seth))

#ex2: Creare un set contenente i seguenti elementi: "mela", "banana", "kiwi","mela"
frutta={"mela", "banana", "kiwi","mela"}
print(frutta)

#ex3: Aggiungere un elemento "pesca" al set precedente
frutta={"mela", "banana", "kiwi","mela"}
frutta.add("pesca")
print(frutta)

#ex4: Rimuovere l'elemento "mela" dal set precedente 
frutta={"mela", "banana", "kiwi","mela"}
frutta.add("pesca")
frutta.remove("mela")
print(frutta)

#ex5: Verificare se l'elemento "ananas" è presente nel set precedente
frutta={"mela", "banana", "kiwi","mela"}
frutta.add("pesca")
frutta.remove("mela")
if "ananas" in frutta:
    print("L'ananas è presente")
else:
    print("L'ananas non è presente")


#ex6: Creare un nuovo set contenente gli elementi "banana", "kiwi", "arancia"
frutta2=("banana","kiwi","arancia")
print=(frutta2)

#ex7: Creare un set contentente i numeri interi da 1 a 5 ricavati da un range()
numeri= set(range(1,6))
print(numeri)


#ex8: Creare un nuovo set contenente i numeri pari del set precedente
numeri_pari = set(x for x in numeri if x % 2 == 0)

print(numeri_pari)
