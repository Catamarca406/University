'''
Data un lista di stringhe (nomi), ordinarla lessicograficamente.
Se la prima lettera uguale --> vedo seconda lettera.
'''

def lessicograf (l):
    l.sort()
    return l
    

    



l = ["Crhis","Paolo","Carla","Pablo","Adriano","Giorgia"] 
print(lessicograf(l))
