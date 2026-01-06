def bit_shift(a):
    
    r= len(a)
    c= len(a[0])


    lenA=len(a)
    cntr=(lenA//2)-1
   
    count=0
    l=[]
    

    for i in range(r):
        for j in range(c):
            if a[i][j] == 1:
                count+=1
                l.append(count)
    return a
            

a=[
    [1,1,0,0,0],
    [1,0,0,1,0],
    [1,1,1,0,0],
    [1,1,0,0,1],
    [1,1,1,1,0],
    [1,1,1,1,1] ]

print(bit_shift(a))