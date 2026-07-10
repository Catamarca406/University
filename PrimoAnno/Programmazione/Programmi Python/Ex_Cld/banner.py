def banner(n,row):
    s=[]
    for x in range(n):
        if (x == row) or (x == (n-row-1)):
            s.append('*')
        else:
            s.append('.')

    print(''.join(s))
    
banner(7,2)