#che prenda in input una lista di numeri e che restituisca gli elementi di a che compaiono più frequentemente
#riassunto, boh non so cosa intenda, ma i comandi che potrebbero servire stanno tutti qua
def mode(lista):
    dizionario = {}
    frequenti=[]
    if len(lista_numeri)==0:
        return "non ci sono elementi"
    
    for x in lista:
        if x not in dizionario:
            dizionario[x]=1
        else:
            dizionario[x]+=1
    
    comparizioni=0

    for x in lista:

        if dizionario.get(x)>comparizioni:

            if(comparizioni>1):
                if(x not in frequenti):
                    frequenti.append(x)

            else:
                comparizioni=dizionario.get(x)
                frequenti.append(x)


    if(comparizioni!=1):       
        return frequenti
    else:
        return "tutti gli elementi compaiono lo stesso numero di volte, non ci sono numeri più frequenti di altri" 



lista_numeri = [1,2,3,4,23,3242,34,234,23,412,2,2,1,2,2,34,34,34,5,6,7,8,8,9]
print(mode(lista_numeri))
