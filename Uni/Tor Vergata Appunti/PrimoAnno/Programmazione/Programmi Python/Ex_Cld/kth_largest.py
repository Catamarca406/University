def kth_largest(a,k):
    
    if k > len(a):
        return None 
    elif k<= 0:
        return None
    
    a.sort(reverse=True)
    lrg=a[k-1]
    
    return lrg


a=[10,5,20,8,15]
k=5

print(kth_largest(a,k))

#Costo spaziale: O(n)       #Sort() utilizza l'algoritmo Timsort che nel caso peggiore ordina in O(n) spazio ausiliario
#Costo temporale: O(n log n)      # Sort() utilizza l'algoritmo Timsort con tale costo  
