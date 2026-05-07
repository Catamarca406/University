# 🎮 Memory Game (Gioco di Memoria)

Un semplice gioco del memory scritto in **C** con output colorato in terminale.  
Il giocatore deve scoprire coppie di carte uguali entro un numero limitato di tentativi.

---

## 🃏 Regole del gioco
- Il tabellone è una griglia quadrata (dimensione scelta dal giocatore).
- Ogni casella contiene una carta rappresentata da una lettera.
- Ogni lettera compare **esattamente due volte**.
- Le carte coperte sono indicate con la lettera **X** rossa.
- Le carte già indovinate vengono eliminate (spazio vuoto).

---

## 🎯 Obiettivo
- Indovinare tutte le coppie prima che i tentativi finiscano.

---

## 📖 Svolgimento
1. Inserisci le coordinate della prima carta (`riga.colonna`).
2. Inserisci le coordinate della seconda carta.
3. Se le carte sono uguali ➝ vengono eliminate.
4. Se sono diverse ➝ perdi un tentativo.

---

## 🏆 Vittoria
- Vinci se elimini tutte le coppie di carte.

## 💀 Sconfitta
- Perdi se i tentativi finiscono.

---

## 🔢 Numero tentativi disponibili
La quantità di tentativi dipende dalla dimensione scelta:

| Dimensione | Tentativi |
|------------|-----------|
| 2x2        | 5         |
| 4x4        | 6         |
| 6x6        | 9         |
| 8x8        | 12        |

---

## ⚙️ Compilazione ed esecuzione
Compila il programma con:
```bash
gcc memory.c -o memory
