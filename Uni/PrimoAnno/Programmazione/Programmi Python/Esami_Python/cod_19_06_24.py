'''
Si scriva una funzione denominata deep_mean che prenda in input una lista e ritorni la media dei
numeri in essa contenuti
'''

def deep_mean(a):
    sum=0
    for i in range(len(a)):
        sum+=a[i]

    avg=sum/len(a)
    return avg


a=[10,15,5,4,6,8,1]
avg=0
avg=deep_mean(a)
print("average:",avg)

#Costo temporale: O(n)
#Costo spaziale: O(n)