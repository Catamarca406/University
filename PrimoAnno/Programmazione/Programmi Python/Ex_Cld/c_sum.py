def cumulative_sum(a):
    current_sum=0           #creo una variabile per mantenere le somme correnti
    l=[]            #creo una lista per contenere le somme
    for i in a:
        current_sum+=i
        l.append(current_sum)
    return l

a=[1,2,3,4]
print(cumulative_sum(a))

#Costo spaziale: O(n)
#Costo temporale: O(n)