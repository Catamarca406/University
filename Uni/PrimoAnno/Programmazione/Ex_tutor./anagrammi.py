
#Scrivere un programma che ragruppi le parole che sono anagrammi tra loro


def anagrammi (parole):
    d={}

    for i in range(len(parole)):
        elem = parole[i]            #prendo l'elemento originale
        prl = elem
        prl=sorted(prl)             #ordino l'elemento
        prl="".join(prl)            
        if prl in d:                #controllo se l'elemento ordinato è presente nel dizionario, in caso positivo inserisco il l'elemento originale 
            d[prl].append(elem) 

        else:                       #se non trovo l'elemento ordinato lo creo
            d[prl] =[elem]

    return d


parole = ["roma","taso","amor","sato","ramo","mora","osat","ciao"]
print(anagrammi(parole))
