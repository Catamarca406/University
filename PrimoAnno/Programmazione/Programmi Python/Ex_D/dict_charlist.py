'''
presa una lista di stringhe inserire in un dizionario la lista 
delle parole che iniziano per una determinata lettera
'''

def phr_occ(a):
    d={}
 
    for elemento in a:      
        if elemento[0] in d:
            d[elemento[0]].append(elemento)
        else:
            l=[]
            l.append(elemento)
            d[elemento[0]]=l
    
    return d
 
a=["ciao","commercio","rosso","tre","otto","albero","giallo","verde","rotto","casa","banale","banana"]
print(phr_occ(a))

