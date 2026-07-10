#ex1: Creare due variabili "nome" e "cognome" e concatenarle a schermo.
nome="Arturo"
cognome="Duro"
print(nome+" "+cognome)


#ex2: Utilizzare la formattazione delle stringhe per ottenere "Il numero è: 42".
numero=42
stringa= "Il numero è: {}".format(numero)
print(stringa)


#ex3: Utilizzare la formattazione delle stringhe per ottenere
# "Il numero binario di 42 è 0b101010". Per il binario utilizzare bin(numero)
binario="0b101010"
stringa="il numero binario è:{}".format(binario)
print(stringa)


#ex4: Partendo dalla variabile "numero" uguale a 5,
# utilizzare le f-strings (interpolazione) per ottenere "Il quadrato di 5 è 25".
numero=5
stringa=f"Il quadrato di {numero} é {numero**2}"       #modo simile al .format per mettere variabili in una stringa
print(stringa)


#ex5: Partendo da "nome" e "cognome" utilizzare la formattazione 
# strighe per ottenere "Il mio nome è {nome} ed il cognome è {cognome}". 
# Come da esempio dovete fare riferimento al nome delle variabili e non alla posizione usata dentro format.
nome="Luca"
cognome="Rossi"
stringa="Il mio nome é {nome} ed il cognome è {cognome}".format(nome=nome, cognome=cognome)
print(stringa)


#ex6: Facendo riferimento all'esercizio precedente ottenere il 
# seguente risultato modificando i valori nel format(): 
# "Il mio nome è LUCA ed il cognome è RoKKi"
nome="Luca"
cognome="Rossi"
stringa="Il mio nome é {nome} ed il cognome è {cognome}".format(nome=nome.upper, cognome=cognome.replace("s","k"))
print(stringa)
