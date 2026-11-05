import math

def fibonacci1 (n):
    frac = 1/math.sqrt(5)
    phi = (1 + math.sqrt(5)) / 2
    phi_hat = (1 - math.sqrt(5)) / 2
    result = frac * (phi**n - phi_hat**n)
    
    return round(result)


def fibonacci2 (n):
    if n <= 2:
        return 1 
    
    return fibonacci2(n-1) + fibonacci2(n-2)


def fibonacci3 (n):
    Fib = [0] * n
    Fib[0] = 1
    Fib[1] = 1

    for i in range(2,n):
        Fib[i] = Fib[i-1] + Fib[i-2]

    return Fib[-1]


def fibonacci4 (n):
    a = 1
    b = 1
    c = 1

    for i in range(2,n):
        c = a + b
        a = b
        b = c

    return c


def fibonacci5 (n):
    F = [[1,1],
         [1,0]]

    M = [[1,0],
         [0,1]]
    
    
    for i in range(n-1):
        M = [[M[0][0] * F[0][0] + M[0][1] * F[1][0], M[0][0] * F[0][1] + M[0][1] * F[1][1]], 
             [M[1][0] * F[0][0] + M[1][1] * F[1][0], M[1][0] * F[0][1] + M[1][1] * F[1][1]]]
        
    return M[0][0] 

def moltiplica(X,Y):
    return [[X[0][0] * Y[0][0] + X[0][1] * Y[1][0], X[0][0] * Y[0][1] + X[0][1] * Y[1][1]],
            [X[1][0] * Y[0][0] + X[1][1] * Y[1][0], X[1][0] * Y[0][1] + X[1][1] * Y[1][1] ]]


def potenzaDiMatrice(A,k):
    if k == 0:
        return [[1,0],
                [0,1]]
    else:
        M = potenzaDiMatrice(A,k//2)
        M = moltiplica(M,M)
        if k%2 == 1:
            M = moltiplica(M,A)
        return M


def fibonacci6 (n):
    A = [[1,1],
         [1,0]]
    M = potenzaDiMatrice(A,n-1)
    return M[0][0]




n1 = 4
n2 = 4
n3 = 4
n4 = 4
n5 = 4
n6 = 4

print("fibonacci 1 con n =",n1,"vale:",fibonacci1(n1))
print("fibonacci 2 con n =",n2,"vale:",fibonacci2(n2))
print("fibonacci 3 con n =",n3,"vale:",fibonacci3(n3))
print("fibonacci 4 con n =",n4,"vale:",fibonacci4(n4))
print("fibonacci 5 con n =",n5,"vale:",fibonacci5(n5))
print("fibonacci 6 con n =",n6,"vale:",fibonacci6(n6))