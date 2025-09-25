
lista1=[2,4,1]
lista2=[0,3,5]
lista3=[6,1,3]

matrix_l=[ lista1,
           lista2,
           lista3]

#calcolo la media di tutta la lista
def mediaValori(matrix_l): 
    somma=0
    righe = len(matrix_l)
    colonne = len(matrix_l[0])
    for riga in matrix_l:
        for elemento in riga:
            somma+=elemento
    media = somma/(righe*colonne)
    return media

media = mediaValori(matrix_l)
def sostituzioneElemMagg(matrix_l, media):
    ultimo_minore = 0
    conta_minori = 0

    # Trova ultimo elemento < media e contali
    for riga in matrix_l:
        for elemento in riga:
            if elemento < media:
                conta_minori += 1

    # Sostituisci gli elementi > media con l'ultimo < media
    for i in range(len(matrix_l)):
        for j in range(len(matrix_l[0])):
            if matrix_l[i][j] > media:
                matrix_l[i][j] = ultimo_minore
            else:
                ultimo_minore = matrix_l[i][j]

    print("Matrice modificata:", matrix_l)
    return conta_minori
print(sostituzioneElemMagg(matrix_l,media))
            




