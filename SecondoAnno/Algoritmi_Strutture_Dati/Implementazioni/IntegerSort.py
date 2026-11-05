def IntegerSort(n,X):
    
    k = max(X)
    Y = [0] * (k+1)
    

    for i in range(n):
        Y[X[i]]+=1

    j = 0

    for i in range(k+1):
        while(Y[i]>0):
            X[j] = i
            j += 1
            Y[i] -= 1

    return X
    
n = 6
X = [3,2,4,4,9,1]

print(IntegerSort(n,X))