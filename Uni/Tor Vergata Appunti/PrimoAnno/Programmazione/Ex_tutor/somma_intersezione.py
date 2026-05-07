'''
Date due liste A e B, restituire la somma degli elementi 
che fanno parte dell'intersezione delle due liste 
Esempio:
A=[1,2,3,4,5]
B=[4,5,7,8,9]
Output: C=9 (4+5)
'''

def inter_sum(a,b,c):
    l1=len(a)
    l2=len(b)

    for i in range(l1):
        for j in range(l2):
            if a[i] + b[j] == c:
                return (a[i],a[j])





A=[1,2,3,4,5]
B=[4,5,7,8,9]
c=9
print(inter_sum(A,B,c))
