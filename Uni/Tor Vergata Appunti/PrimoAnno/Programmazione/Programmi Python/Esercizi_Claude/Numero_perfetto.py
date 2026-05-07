'''
Crea una funzione che verifica se un numero è "perfetto" 
(uguale alla somma dei suoi divisori propri). 
Ad esempio: 6 è perfetto perché 1+2+3=6. 
'''

def n_perf(num):
    if num<=1:
        return False
    
    somma_divisori=0
    for i in range(1,num):
        if num%i ==0:
            somma_divisori+=1
    return somma_divisori


print(n_perf(25))
print(n_perf(10))
print(n_perf(2))
print(n_perf(1))
