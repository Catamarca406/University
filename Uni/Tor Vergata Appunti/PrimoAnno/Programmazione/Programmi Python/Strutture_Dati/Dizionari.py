#ex1: Creare un dizionario vuoto e assegnarlo a una variabile
dict={}
diz=dict
print(diz)

#ex2:Creare un dizionario con le seguenti chiavi e valori: 
# "nome" : "Mario", "cognome" : "Rossi", "età" : 30.
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
print(dict)

#ex3: Accedere all'elemento con chiave "età" dal dizionario precedente
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
print(dict["Età"])


#ex4: Aggiungere un nuovo elemento "email" con valore "mario.rossi@email.com"
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
print(dict)


#ex5: Rimuovere l'elemento con chiave "cognome" dal dizionario precedente
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
dict.pop("Cognome")
print(dict)


#ex6: Creare una nuova lista che contenga solo le chiavi del dizionario precedente
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
lista=list(dict.keys())
print(lista)


#ex7: Creare una nuova lista che contenga solo i valori del dizionario precedente
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
lista=list(dict.values())
print(lista)


#ex8: Aggiornare il valore dell'elemento con chiave "età" del dizionario precedente a 35
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
dict["Età"]="35"
print(dict)


#ex9: Contare il numero di elementi del dizionario precedente
dict={"Nome":"Nic","Cognome":"Bar","Età":"2006"}
dict["Email"]= "mario.rossi@email.com"
dict["Età"]="35"
num_elem=len(dict)
print(num_elem)