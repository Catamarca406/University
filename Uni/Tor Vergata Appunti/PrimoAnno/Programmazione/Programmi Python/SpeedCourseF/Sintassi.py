# Python non tipizzato
# Sintassi di base

# Commenti
# Questo è un commento su una riga
"""
Questo è un commento
su più righe
"""

# Variabili
nome = "Mario"
età = 30
pi = 3.14

print("Nome:", nome)
print(f"Età: {età}, Pi: {pi}, Nome: {nome}")
print("Età:", età)
print("Pi:{},Nome:{},Età:{}".format(pi, nome, età))

print("-" * 20)

# Operatori
a = 10
b = 5
somma = a + b
differenza = a - b
prodotto = a * b
quoziente = a / b
quoziente2 = a // b  # Divisione intera
modulo = a % b  # a /b con resto (modulo)
esponente = a**b  # a^b

print("Somma:", somma)
print("Differenza:", differenza)
print("Prodotto:", prodotto)
print("Quoziente:", quoziente)
print("Quoziente2:", quoziente2)
print("Modulo:", modulo)
print("Esponente:", esponente)

print("-" * 20)

print("-" + str(10))  # Il + concatena due oggetti dello stesso tipo
print("10" + "20")  # Concatena due stringhe
i10 = int("5")  # converte una stringa in un intero
print("Intero:", i10)
print("-" * 20)

# Strutture dati base (liste, tuple, dizionari)
liste = [3, False, "Ciao", 3.14]
n = len(liste)
print("Lunghezza:", n)

print("Lista vuota:", liste)
liste.append(10)  # Aggiunge un elemento alla lista
print("Lista aggiornata:", liste)
liste.remove(liste[1])  # Rimuove un elemento dalla lista
print("Lista dopo rimozione:", liste)
liste[-2] = 100  # Modifica un elemento della lista
print("Lista dopo modifica:", liste)
liste[1] = len  # Sostituisce un elemento con una lista
print("Lista dopo modifica:", liste)
n1 = liste[1](
    "cia00o"
)  # Chiama la funzione len sulla stringa "ciao" liste[1]("ciao") == len("ciao")
print('MAGIA - len("ciao")', n1)
print("-" * 20)

# Tuple
tupla = (1, "Ciao", (2, (3, 4)), 3.14, True)  # Le tuple sono immutabili
print("Tupla:", tupla)
print("Primo elemento della tupla:", tupla[0])
print("Lunghezza della tupla:", len(tupla))

tupla1 = tupla + tupla  # Concatenazione di tuple
print("Tupla dopo concatenazione:", tupla1)
print(tupla)
# tuple.remove(tupla1[0])  # Rimuove un elemento dalla tupla (non funziona, le tuple sono immutabili)
# print("Tupla dopo rimozione:", tupla1)
tupla_to_arr = list(tupla)  # Converte una tupla in una lista
print("Tupla convertita in lista:", tupla_to_arr)
print(tupla_to_arr[2][1][0])
tupla_to_arr.append(100)  # Aggiunge un elemento alla lista
print("Lista dopo aggiunta:", tupla_to_arr)
tupla_to_arr.remove(tupla_to_arr[0])  # Rimuove un elemento dalla lista
print("Lista dopo rimozione:", tupla_to_arr)
tupla_to_arr[-2] = 100  # Modifica un elemento della lista
print("Lista dopo modifica:", tupla_to_arr)

tupla = tuple(tupla_to_arr)  # Converte la lista in una tupla
print("Lista convertita in tupla:", tupla)
print("-" * 20)

# Dizionari
dizionario = {}
dizionario1 = dict()

print("Dizionario vuoto:", dizionario)
print("Dizionario1 vuoto:", dizionario1)

dizionario[(1, 2)] = "Ciao"
dizionario["nome"] = {"Mario": "Ciao", "Luigi": "Salve"}
dizionario["età"] = [30, 25, 40]
dizionario["pi"] = (3.14, 3.14159, 3.141592653589793)
dizionario[1] = True
print("Dizionario aggiornato:", dizionario)

print(dizionario["nome"])
dizionario2 = {
    "nome": "Mario",
    "età": 30,
    "pi": 3.14,
    "lista": [1, 2, 3],
    "tupla": (1, 2, 3),
    "dizionario": {"a": 1, "b": 2},
    "booleano": True,
    True: "vero",
}
print("Dizionario2:", dizionario2)
print("\n")
for chiave, valore in dizionario2.items():
    print("Chiave,Valore: {}-{}".format(chiave, valore))
print("\n")
for chiave in dizionario2:
    print("Chiave:", chiave, "Valore:", dizionario2[chiave])
print("\n")
print("Quali sono le chiavi del dizionario2?", dizionario2.keys())
print("Quali sono i valori del dizionario2?", dizionario2.values())

dizionario3 = dict()

for i in range(10):
    dizionario3[i] = i * 2
print("Dizionario3:", dizionario3)
print("\n")
array = [1, 2, 3, 4, 5, 2, 4, 5, 6, 3]
d = dict()
for i in array:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
print("Dizionario con conteggio degli elementi:", d)
print("-"*20)
print("\n")

lista = [1, 2, 6, 4, 5]
print("Lista:", lista)
range = lista[2:3]  # Slicing della lista dell'intervallo [2,3) (inclusivo 2, esclusivo 3)
print("Slicing della lista:", range)

range = lista[2:]  # Slicing della lista dell'intervallo [2,\infty) da 2 a fine lista
print("Slicing della lista:", range)

range = lista[:3]  # Slicing della lista dell'intervallo (\infty,3) da inizio lista a 3 (esclusivo)
print("Slicing della lista:", range)

range = lista[::-1]  # Slicing della lista invertendo la lista
print("Slicing della lista:", range)

lista.sort()  # Ordina la lista in modo crescente
print("Lista ordinata:", lista)

lista_diliste = [[6,2,7], [1, 3, 4], [8, 9,-14]]

lista_sorted = sorted(lista_diliste, key=lambda x: x[2])  # Ordina la lista di liste in base all' elemento in posizione 2 di ogni sottolista
print("Lista di liste ordinata con sorted:", lista_sorted)

lista_diliste.sort(key=lambda x:x[2])  # Ordina la lista di liste in base all' elemento in posizione 2 di ogni sottolista
print("Lista di liste ordinata:", lista_diliste)

a = [1, 2, 3, 4, 5]
n=len(a)
k=47
for i in range(n):
    for j in range(k):
            print("Elemento in posizione", i, ":", a[i])

for i in range(n):
    print("Elemento in posizione", i, ":", a[i])

for i in range(k):
    print("Elemento in posizione", j, ":", a[j])