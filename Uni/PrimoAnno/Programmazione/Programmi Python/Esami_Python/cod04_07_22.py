"""Sia a una lista che contiene k elementi di tipo int, k elementi di tipo float e k
elementi di tipo str. Si scriva un frammento di codice Python che stampi k
righe tali che la prima contienga il primo int seguito dalla prima str seguita
dal primo float; la seconda riga mostri il secondo int, la seconda str e il
secondo float… e così via fino alla k-esima riga che elenchi l’ultimo int,
l'ultima str e l'ultimo float."""

def ord_types(a):
    
    ord_ints=[]
    ord_floats=[]
    ord_strs=[]

    for elem in a:
        if type(elem) == int:
            ord_ints.append(elem)
        if type(elem) == float:
            ord_floats.append(elem)
        if type(elem) == str:
            ord_strs.append(elem)

    ord_tps=[]
    l=[]

    for i in range(len(ord_ints)):

        l.append(ord_ints[i])
        l.append(ord_strs[i])
        l.append(ord_floats[i])
        ord_tps.append(l)
        print(f'i seguenti elemnti sono : {l[0]}, {l[1]}, {l[2]}')
        l = []

    return ord_tps




a=[2,3.3,"diario",5.6,7,"sud0",1.3,"prova","int",5]
print(ord_types(a))