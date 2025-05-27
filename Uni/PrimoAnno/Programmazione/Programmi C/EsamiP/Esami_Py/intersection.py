'''
Si scriva una funzione che prenda in input 2 dizionari e restituisca una lista contenente le chiavi che sono nei dizionari
'''

def intersection(d0,d1):
    listafinale=[]

    listafinale.extend(d0.keys())         #RICORDA KEYS HA LE PARENTESI TONDE QUANDO VA CHIAMATO, COSI KEYS()
                                        #Usa append se vuoi aggiungere un oggetto (ad esempio, una lista o un valore singolo) come un unico elemento.
                                        #Usa extend se vuoi aggiungere tutti gli elementi di un iterabile come elementi separati.
    
    listafinale.extend(d1.keys())
    return listafinale

dizionario0 = {
    "chiave1": "valore1",
    "chiave2": "valore2",
    "chiave3": "valore3"
}

dizionario1 = {
    "chiave4": "valore4",
    "chiave5": "valore5",
    "chiave6": "valore6"
}

lista=[]

lista=intersection(dizionario0,dizionario1)
print(lista)

