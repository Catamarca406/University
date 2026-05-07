#ex1: Creare una lista vuota e assegnarla a una variabile
lista1=[]
lista=lista1


#ex2: Creare una lista di numeri da 1 a 5 e assegnarla ad una variabile
lista=[1,2,3,4,5]
valore_l=lista
print(valore_l)
print(valore_l[4])


#ex3: Accedere all'elemento 2 della lista precedente
lista=[1,2,3,4,5]
val_pos_2=lista[1]
print(val_pos_2)

#ex4: Aggiungere un nuovo elemento "6" alla lista precedente
lista=[1,2,3,4,5]
lista.append(6)
print(lista)

#ex5: Rimuovere l'elemento con indice 3 dalla lista precedente
lista=[1,2,3,4,5]
lista.pop(3)
print(lista)

#ex6: Creare una nuova lista che contenga solo i primi tre elementi della lista precedente
lista=[1,2,3,4,5]
n_lista=list(lista[:3])
print(n_lista)

#ex7: Creare una lista che contenga gli elementi con indici dispari nella lista precedente
lista=[1,2,3,4,5]
lista_d=lista[1::2]
print(lista_d)


#ex8: Ordinare la lista precedente in ordine crescente
lista=[4,5,2,7,9,3,1,9,0,92]
lista.sort(reverse=False) #decrescente --> crescente
print(lista)
lista.sort(reverse=True)  #crescente --> decrescente
print(lista)


#ex9: Contare quante volte l'elemento "2" compare nella lista precedente
lista=[4,5,2,7,9,3,1,9,0,92,2,2,2,2,2]
print(lista.count(2))





 