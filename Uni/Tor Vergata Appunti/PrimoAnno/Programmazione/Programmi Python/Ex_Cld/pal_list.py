def is_palindrome_list(a):
    i=0
    j=len(a)-1

    while(i<j):
        if a[i] == a[j]:
            i+=1
            j-=1
        else:
            return False
    return True

a=[1,2,3,2,1]
print(is_palindrome_list(a))

#Costo spaziale: O(1)
#Costo temporale: O(n)