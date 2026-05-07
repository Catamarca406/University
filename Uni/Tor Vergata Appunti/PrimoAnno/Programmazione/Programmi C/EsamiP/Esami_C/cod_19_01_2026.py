def partial_bubble_sort( L, k ):

    if len(L) == 0:
         return None


    temp = 0
    #Implemento l'algoritmo BubbleSort
    for i in range(len(L)-1):       #conto fino a len(L)-1 per non sforare con l'indice (j+1)
       for j in range(len(L)-1):
                if L[j] > L[j+1]:       #confronto gli elementi e li scambio 
                    temp = L[j+1]     
                    L[j+1] = L[j]
                    L[j] = temp

    #Creo una lista ausiliaria per inserire i primi k-minimi
    L_min = []

    #inserisco gli elementi in lista
    for i in range(k):
        L_min.append(L[i])

    return L_min

L = [10,5,8,12,13,2]
k=3
print(partial_bubble_sort(L,k))

'''
Complessità: Spaziale -> O(n), non lavoro in place, utilizzo 
             una lista ausiliaria per salvare i primi k - minimi 

             Temporale -> O(n*n), è il costo di BubbleSort, ordina una lista confrontando
             ogni elemento con i successivi
'''