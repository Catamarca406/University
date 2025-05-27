
n=7
i=0

def banner_x(n,i):
    stringa=""
    for x in range(n):
        if x==i or x==n-1-i:
            stringa+='*'
        else:
            stringa+=' '
    return stringa
print(banner_x(7,0))
