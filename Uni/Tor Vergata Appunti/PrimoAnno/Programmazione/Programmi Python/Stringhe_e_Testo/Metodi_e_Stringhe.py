#ex1: Assegnare una stringa "ciao mondo" ad una variabile "stringa" e utilizzare il metodo upper() 
# per convertirla in maiuscolo in una nuova variabile.
stringa="ciao mondo"
nuova_stringa=stringa.upper()
print("vecchia stringa: "+stringa)
print("nuova stringa: "+nuova_stringa)

#ex2: Assegnare una stringa "Benvenuti a Roma" ad una variabile "stringa" e utilizzare il metodo lower() 
# per convertirla in minuscolo in una nuova variabile.
stringa="Benvenuti a Roma"
stringa_low=stringa.lower()
print("vecchia stringa: "+stringa)
print("nuova stringa: "+stringa_low)

#ex3: Assegnare una stringa "Il meglio deve ancora venire" ad una variabile "stringa" e 
# utilizzare il metodo split() per dividere la stringa in una lista di parole.
stringa="il meglio deve ancora venire"
stringa_divisa=stringa.split()
print("vecchia stringa: "+stringa)
print(type(stringa_divisa))
print("nuova stringa: "+str(stringa_divisa))

#ex4: Assegnare una stringa "Hello World" ad una variabile "stringa" e 
# utilizzare il metodo replace() per sostituire "World" con "Python".
stringa="Hello World"
stringa_rimp=stringa.replace("World","Python")
print(stringa_rimp)


#ex5: Assegnare una stringa " Ciao " ad una variabile "stringa" e 
# utilizzare il metodo strip() per rimuovere gli spazi vuoti all'inizio e alla fine della stringa..
stringa=" Ciao "
stringa_nospazi=stringa.strip()
print(stringa_nospazi)


#ex6: Assegnare una stringa "abcdefg" ad una 
# variabile "stringa" ed estrarre i primi tre caratteri.
stringa="abcdefg"
nuova_stringa=stringa[:3]
print(nuova_stringa)


#ex7: Assegnare una stringa "Python" ad una variabile "stringa" e 
# utilizzare il metodo startswith() per verificare se la stringa inizia con "Py".
stringa="Python"
nuova_stringa=stringa.startswith("Py")
print(nuova_stringa)


#ex8: Assegnare una stringa "Ciao mondo" ad una variabile "stringa" e 
#utilizzare il metodo count() per contare il numero di volte in cui la lettera "o" appare nella stringa.
stringa="Ciao mondo"
occorrenze=stringa.count("o")
print(occorrenze)


#ex9: Assegnare una stringa "Ciao mondo" ad una variabile "stringa". 
# Mandare quindi a schermo gli ultimi 5 caratteri 
# della stringa in maiuscolo, sostituendo il carattere "o" con "k".
stringa="Ciao mondo"
nuova_stringa=(stringa[5:9])
nuova_stringa=nuova_stringa.lower()
nuova_stringa=nuova_stringa.replace("o","k")
print(nuova_stringa)

