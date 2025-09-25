def char_int_2_0(a):
    d={}
    l=[]
    j=1

    for i in range(len(a)):
        for j in range(1,len(a)):
            l.append(a[i][j])
            if j == 3:
                t=tuple(l)
                l=[]  #oppure l.clear()
                d[a[i][0]]=t
    return d
                
                
a=[['a',1,2,3],['b',4,5,6],['c',7,8,9],['d',10,11,12]]
print(char_int_2_0(a))