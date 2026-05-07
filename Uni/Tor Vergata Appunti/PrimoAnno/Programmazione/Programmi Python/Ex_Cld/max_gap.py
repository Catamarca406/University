def max_gap(a):
    
    a.sort(key=lambda x:x[1])
    find_max=[]

    for i in range(1,len(a)):
        find_max.append(a[i][1]-a[i-1][1])
        
    mx_gap=max(find_max)
    return mx_gap



a=[
    ("Caianello", 230),
    ("Caserta", 250),
    ("Casilina", 40),
    ("Cassino Sud", 115),
    ("Frascati", 20),
    ("La Macchia", 30),
    ("San Nicola", 90),
    ("San Vittore", 80),
    ("Teano", 210)]

print(max_gap(a))

#Costo spaziale: O(n)
#Costo temporale: O(n log n)