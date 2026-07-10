'''
Si scriva una funzione, denominata second_max , che prenda in input una lista di numeri e restituisca il
secondo numero in ordine di grandezza tra quelli in a . Se a non contiene questo numero (ad
esempio se la lista contiene meno di due elementi, o gli elementi della lista sono tutti uguali), la
funzione restituisca None .
'''

def second_max(a):
    max=a[0]
    pos_2max=0
    second_max=a[0]
    flag=1
    j=1
    i=0

    while j<len(a):
        if a[i]!=a[j]:
            flag=0
            j+=1
            i+=1
        else:
            j+=1
            i+=1
        

    if flag==1:
        return None 

    if len(a)<2:
        return None
    else:
        for i in range(len(a)):     #calcolo il primo max
            if max<=a[i]:
                max=a[i]
        
        for i in range(len(a)):             #calcolo il secondo max, ignorando il primo 
            if second_max<=a[i] and a[i]!=max:
                second_max=a[i]
                pos_2max=i
            else:
                i+=1

        return a[pos_2max]
    


a=[-1,15,10,25,3,7,5]
first_max=second_max(a)

print("secondo max:",first_max)
