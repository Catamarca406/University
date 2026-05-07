# Interpretato (legge riga per riga, più lento rispetto al compilatore), non tipizzato (non serve attribuire i tipi alle variabili)

#commento
'''commento
su più 
righe'''

#variabili
nome="mario"
età=30
pi=3.14

#stampa
print("Nome:",nome)
print(f"Età:{età},Nome:{nome}")
print("Pi:{},Nome:{},Età:{}".format(pi,nome,età))
print("-"*20)  #stampa 20 volte -
print("10"+"20") #concateno due stringhe
print("10"+str(10)) #concateno stringa e un intero castando


#Operatori
a=10
b=5
somma=a+b
differenza=a-b
prodotto=a*b
quoziente=a/b
resto_intero=a//b
elevazione_a_potenza=a**b
resto=a%b

#Strutture dati (Liste,Tuple,Dizionari)
lista_vuota=[]
lista=[10,20,30,40]
lista_varia=[10,"25",3.14,True]     #gli elementi partono da 0
lista_valori_ripetuti=[10]*10

print(len(lista))   #stampo la lunghezza della lista, len stampa n+1 elementi, parto da 0 

#modifico una lista: aggiungo, rimuovo, modifico elementi 

lista.append("ultimo")  #aggiungo alla coda della lista "ultimo", costo: O(n)
lista.remove("ultimo")  #rimuovo l'elemento "ultimo" e la funzione remove poi shifta tutto, costo: O(n)
lista[0]=100  #modifico l'elemento in lista
lista[-1]=100 #modifico l'ultimo elemento


#funzioni built-in sono standard in python
lista[1]=len
n1=lista[1]("ciao")     #restituisce la len di "ciao", posso utilizzare le funzioni built-in dentro una lista


#Tupla, immutabile

tupla=(10,"25",3.14)
tupla1=(20,"abc")
tupla2 =tupla+tupla1
print(tupla2)   #posso concatenare, ma in realta sto creando una nuova tupla

#dizionari 
dizionario={}
dizionario1 = dict()

print("Dizionario vuoto",dizionario)
print("Dizionario vuoto",dizionario1)

dizionario["nome"] = {"Mario": "Ciao", "Luigi":"Salve"}
dizionario["età"] = {30,15,40}
dizionario["pi"] = {3.14, 3.1415, 3.141517}

#non si possono utilizzare valori modificabili come chiavi di dizionari, 
# perderei i valori attribuiti a quella chiave modificando la chiave

for chiave,valore in dizionario.items():
    print("Chiave, Valore",chiave,valore)

for chiave in dizionario.items():
    print("Chiave,Valore",chiave,dizionario[valore])

#posso aggiungere valori con:
dizionario[True]="Vero"     #prende il dizionario precedente e inserisce al suo interno key=True con valore "Vero"


#contare le occorrenze di un dato elemento in un dizionario
array=[1,2,3,4,5,6,7,1,3,2,4,5]
d=dict()

for i in array:     #i itera le chiavi del dizionario
    if i in d:
        d[i] += 1       #d[i] aumenta di 1 il valore del dizionario in posizione i
    else:
        d[i] = 1
print("DIzionario con conteggio degli elementi: ", d)


#range 
lista=[1,23,4,5,6]
print("Lista:",lista)
range = lista[2:3]
range2 = lista[:2]
range3 = lista[:]    #così range diventa una copia di lista
range4 = lista[::-1]    #reverso la lista
range5 = lista[:-1]     #prendo tutti i valori della lista meno che l'ultimo


#funzione di ordinamento
lista.sort()

lista_di_liste = [[1,2,3],[4,2,7],[6,1,3]]

lista_di_liste.sorted(lista_di_liste, key=lambda x:x[0], reverse=True) # creo una nuova lista e ordino come prima

lista_di_liste.sort()   #ordina in base al primo elemento
lista_di_liste.sort(key=lambda x:x[0])  #ordino la lista in base alla pos 2 di ogni sotto-lista
lista_di_liste.sort(key=lambda x:x[0], reverse=True)    #ordino in maniera decrescente la lista in base al elemento nella sottolista in pos 2

#sort modifica la lista inziale , viene utilizzato il trin sort costo O(nlog(n))
#sorted crea una nuova lista, copia la lista ordinata

