#Si scriva una funzione denominata deep_mean che prenda 
# in input una lista e ritorni la media dei
#numeri in essa contenuti.


#iddu = input dato da utente, ossia la lista

def deep_mean(lista):
    somma =0
    for x in lista:
        if type(x)!=float and type(x)!=int and type(x)!=list:
            return "torna indietro gringo"
        elif (type(x) == list):
            somma = somma + deep_mean(x)
        else:
            somma=somma+x
    somma = somma/len(lista)
    return somma

lista_input=[3,[3,6,9],9]
print (deep_mean(lista_input))