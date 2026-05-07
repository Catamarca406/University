'''
Scrivi una funzione che verifica se due parole sono anagrammi l'una dell'altra 
(stesse lettere, ordine diverso).
'''

def anagram(prl,prl2):
    prl=prl.replace(" ","").lower()
    prl2=prl2.replace(" ","").lower()
    
    if len(prl) != len(prl2):
        return False
    
    return sorted(prl) == sorted(prl2)

prl="Anna"
prl2="Nana"
print(anagram(prl,prl2))
