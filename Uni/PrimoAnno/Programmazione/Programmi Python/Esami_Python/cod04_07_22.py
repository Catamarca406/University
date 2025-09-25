"""Sia a una lista che contiene k elementi di tipo int, k elementi di tipo float e k
elementi di tipo str. Si scriva un frammento di codice Python che stampi k
righe tali che la prima contienga il primo int seguito dalla prima str seguita
dal primo float; la seconda riga mostri il secondo int, la seconda str e il
secondo float… e così via fino alla k-esima riga che elenchi l’ultimo int,
l'ultima str e l'ultimo float."""

a=[30.5,"int",5,21.2,10,"prv"]

int_list=[]
float_list=[]
str_list=[]


for elem in a:
    if type(elem) is int:
        int_list.append(elem)
    elif type(elem) is float:
        float_list.append(elem)
    elif type(elem) is str:
        str_list.append(elem)


rows_list=[]


for pos in range(len(int_list)):
    rows_list.append(int_list[pos])
    rows_list.append(float_list[pos])
    rows_list.append(str_list[pos])
    

print(rows_list)


#Costo temporale: O(n)
#Costo spaziale: O(n)