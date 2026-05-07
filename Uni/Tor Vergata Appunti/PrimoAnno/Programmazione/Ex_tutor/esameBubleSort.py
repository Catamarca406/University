def partial_bubble_sort(L, k):
    """
    Parametri: una lista con elementi tutti confrontabili; un intero k
    Ritorna: La lista dei k elementi più piccoli di L
    """
    
    n = len(L)
    
    # Se k è maggiore della lunghezza della lista, restituisco tutta la lista ordinata
    if k > n:
        k = n
    
    # Eseguo il ciclo esterno solo k-volte.
    # Ogni iterazione 'i' garantisce che l'i-esimo elemento più piccolo venga posizionato correttamente all'indice 'i'.
    for i in range(k):
        for j in range(n - 1, i, -1):
            if L[j] < L[j-1]:
                # Scambio se l'elemento corrente è minore del precedente
                L[j], L[j-1] = L[j-1], L[j]
    return L[:k] # Restituisco la lista contenente i primi k elementi, che sono ora i minimi ordinati.



print(partial_bubble_sort([10,4,3,1,5,89],3))

''' 
Complessità:
Temporale: O(k * n) perché:
    Il ciclo esterno viene eseguito esattamente k volte. 
    Il ciclo interno esegue scambi e confronti su una porzione della lista che va da n decrescendo fino a n-k.
    nel caso peggiore, facciamo circa k * n operazioni. Se k fosse molto piccolo l'algoritmo risulterebbe molto efficiente.
    Se k fosse circa n, la complessità diventa quella del Bubble Sort classico: O(n^2).

Spaziale: O(k) perché:
    L'ordinamento avviene modificando la lista L direttamente, 
    tuttavia, la funzione deve ritornare una nuova lista composta da k elementi, 
    quindi si utilizza O(k) di memoria per generare l'output finale.

'''
