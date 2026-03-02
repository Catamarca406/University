def deep_mean(a):

    k=0
    sum=0
    for i in range(len(a)):
        if type(a[i]) == int or type(a[i]) == float:
            sum+=a[i]
            k+=1
        elif type(a[i]) == list:
            sum+=deep_mean(a[i])[0]
            k+=deep_mean(a[i])[1]
    

    return (sum,k)


a=[10,3,5,"a",[3,5,1]]
print(deep_mean(a)[0]/deep_mean(a)[1])

#Costo spaziale:O(1)
#Costo temporale: O(n*s)

