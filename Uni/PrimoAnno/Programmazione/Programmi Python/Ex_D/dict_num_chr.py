'''
data una stringa, restituire un dizionario che conta le occorrenze di ogni carattere
'''

def occ_char(a):
    occorrenze=0
    d={}
    b=[]
    for elemento in a:              #itero in base all'elemento
       if elemento in d:            #verifico le occorenze nella stringa
            d[elemento]+=1
       else:
           d[elemento]=1
    
    b=list(d.items())
    return b


a="bbbolp4rrrmmff44pp"
print(occ_char(a))