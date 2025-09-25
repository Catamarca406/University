#ex1: Creare una tupla vuota e assegnarla ad una variabile
tupla=()
tup_vuota=tupla
print(tupla)

#ex2: Creare una tupla con i seguenti elementi: "mela","banana","kiwi"
frutta=("mela","banana","kiwi")
print(frutta)

#ex3: Accedere all'elemento "banana" della tupla precedente
frutta=("mela","banana","kiwi")
print(frutta[1])

#ex4: Creare una nuova tupla che contenga solo i primi due elementi della tupla precedente
frutta=("mela","banana","kiwi")
nuova_frutta=frutta[:2]
print(nuova_frutta)

#ex5: Verificare se l'elemento "ananas" è presente nella tupla precedente.
frutta=("mela","banana","kiwi")
if("ananas" in frutta):
    print("True")
else: 
    print("False")

#ex6: Creare una nuova tupla concatenando la tupla precedente con la tupla ("pesca","arancia")
frutta=("mela","banana","kiwi")
arancio=("pesca","arancia")
print(frutta+arancio)

#ex7: Verificare la lunghezza della tupla precedente 
frutta=("mela","banana","kiwi")
arancio=("pesca","arancia")
frutta2=frutta+arancio
len_frutta2=len(frutta2)
print(len_frutta2)


#ex8: Creare una tupla contenente i numeri interi da 1 a 5
tupla=(1,2,3,4,5)
print(tupla)


#ex9 Creare una tupla contenente il quadrato dei numeri interi da 1 a 5
tupla=(1,2,3,4,5)
numeri_quadrati = tuple(x ** 2 for x in range(1, 6))

print(numeri_quadrati)


#ex10: Contare il numero di occorrenze dell'elemento "mela" nella tupla precedente
frutta=("mela","banana","ananas","mela")
occorenze=frutta.count("mela")
print(occorenze)


