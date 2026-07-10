'''
Scrivi una funzione che prende una stringa e 
restituisce il numero di vocali e consonanti (ignora spazi e caratteri speciali)
'''

def contaC_V(s):
    vocali="aeiouAEIOU"
    conta_vocali=0
    conta_cons=0

    for char in s:
        codice=ord(char)

        if (65<=codice <= 90) or (97<=codice<=122):
            if char in vocali:
                conta_vocali+=1
            else:
                conta_cons+=1
    return conta_cons,conta_vocali

a="A65Bl@trmnOtto"
cons,voc=contaC_V(a)

print("Cons",cons)
print("Vocali:",voc)
