def parole_punteggiatura(frase):
    for carattere in frase:
        if not ((carattere in "ABCDEFGHIJKLMNOPQRSTUVWXYZ") or (carattere in"abcdefghijklmnopqrstuvwxyz")) and  (carattere != " "):
            frase=frase.replace(carattere,"")

    
    nuova_frase=frase.lower()
    n_frase=nuova_frase.split()

    return n_frase



def conta_occorrenze(frase):
    d={}

    for parola in frase:
        if parola not in d:
            d[parola] = 1
        else:
            d[parola] += 1

    return d



def ordine_frequenze(d):
    
    l = []
    
    for elemento in d:
        l.append((elemento,d[elemento]))
    
    l.sort(key=lambda x:x[0], reverse=True)
    
    return l


def ordine_freq_alfab(d):
    l = []
    
    for elemento in d:
        l.append((elemento,d[elemento]))
    
    
    l.sort(key=lambda x:x[0])
    l.sort(key=lambda x:x[1],reverse=True)
    
    return l


frase="ciao, sto provando il codice. Cerco cerco di TOGLIERE la PUNTEGGIATURA.."
nuova_frase=parole_punteggiatura(frase)
d=conta_occorrenze(nuova_frase)
print(ordine_frequenze(d))
print("------------------------------------------------------------")
print(ordine_freq_alfab(d))


