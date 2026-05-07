'''
data una lista di persone, (nome,cognome), 
deve ritornare: 
un primo dizionario in cui le chiavi sono i nomi e i valori sono liste di cognomi
un secondo dizionario con i cognomi, dove i cognomi sono le chiavi e i valori sono liste di nomi
'''

def match(a):
    d={}
 

    for i in range(len(a)):
       if a[i][0] in d:
            d[a[i][0]].append(a[i][1])
            
       else:
           d[a[i][0]]=[a[i][1]]
           
    return d
           
           

a=[("mario","rossi"),("luigi","bianchi"),("lorenzo","ferrari"),("mario","galli")]
print(match(a))