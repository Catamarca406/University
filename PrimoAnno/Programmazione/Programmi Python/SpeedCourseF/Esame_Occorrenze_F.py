def contaOccorrenze(lista):
    d = {} # creo dizionario vuoto
    for i in lista:
        if i in d: #appartenenza al dizionario ha costo O(1)
            d[i] += 1 # se l'elemento è già presente, incrementa il conteggio
        else:
            d[i] = 1 # altrimenti, lo aggiunge con conteggio 1
    return d

def ordinaListaPerOccorrenze(d):
    # Ordina la lista in base al numero di occorrenze (valore del dizionario)
    return sorted(d.items(),key=lambda x: x[1])

def eliminaOccorrenze(dict_ord):
    # Elimina i doppioni dalla lista e ordina in base alle occorrenze, return la lista
    list = []
    for x in dict_ord:
        list.append(x[0]) # aggiunge solo la chiave alla lista finale
    return list

a = list("jhgkjhgkhjgkhjgjggjhghdddds")
dict_occorrenze = contaOccorrenze(a)
print(f"Occorrenze: {dict_occorrenze}")

lista_occorrenze_ordinate = ordinaListaPerOccorrenze(dict_occorrenze)
print("Lista ordinata per occorrenze:", lista_occorrenze_ordinate)

lista_finale = eliminaOccorrenze(lista_occorrenze_ordinate)
print("Lista finale senza doppioni:", lista_finale)
