def find_sublist(a,b):
    
    if len(b)==0:
        return False

    if len(b)>len(a):
        return False

    j = 0
    

    for i in range(len(a)-len(b)+1):
        
        check=True

        for j in range(len(b)):
        
            if a[i+j] != b[j]:
        
                check=False
                break
        if check:
            return True

    return False


a=[1,2,3,4,5]
b=[2,3,4]
print(find_sublist(a,b))

#Costo spaziale: O(1) 
#Costo temporale: O(n*m)