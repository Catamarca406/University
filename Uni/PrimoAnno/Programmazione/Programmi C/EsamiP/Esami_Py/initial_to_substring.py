#prenda in input una stringa a e restituisca in output un dizionario che mappi ogni carattere c di a nella sottostringa più lunga di a che inizia per c
a="ciaoiaoiaoc"
def initial_to_substring(stringa):
    dizionario = {}
    lunghezza = len(stringa)
    for x in range(lunghezza):
        if stringa[x] not in dizionario:
            dizionario[stringa[x]] = stringa[x:]
    return dizionario
print(initial_to_substring(a))
