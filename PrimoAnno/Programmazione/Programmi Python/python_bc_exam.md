#programmazione
# 🧠 Python – Complessità (VERSIONE SOLO ESAME)

## 📌 Regole d’oro
- `O(1)*` = **tempo medio**, **worst O(n)**
- **list** → accesso veloce, inserimenti costosi
- **set/dict** → membership veloce
- **str** immutabili → ogni modifica copia

---

## 🔧 Built-in principali

| Funzione | Costo |
|--------|------|
| `len(x)` | O(1) |
| `type(x)` | O(1) |
| `abs(x)` | O(1) |
| `sum(x)` | O(n) |
| `max(x)` | O(n) |
| `min(x)` | O(n) |
| `sorted(x)` | O(n log n) |
| `any(x)` | O(n) |
| `all(x)` | O(n) |

---

## 📋 list

| Operazione | Costo |
|----------|------|
| `x[i]` | O(1) |
| `append()` | O(1)* |
| `pop()` | O(1) |
| `insert(i,v)` | O(n) |
| `remove(v)` | O(n) |
| `v in x` | O(n) |
| `sort()` | O(n log n) |

---

## 📦 tuple

| Operazione | Costo |
|----------|------|
| `t[i]` | O(1) |
| `v in t` | O(n) |
| `len(t)` | O(1) |

---

## ✏️ str

| Operazione | Costo |
|----------|------|
| `s[i]` | O(1) |
| `s + t` | O(n) |
| `'x' in s` | O(n) |
| `split()` | O(n) |
| `join()` | O(n) |

---

## ⚙️ set

| Operazione | Costo |
|----------|------|
| `add(v)` | O(1)* |
| `remove(v)` | O(1)* |
| `v in s` | O(1)* |
| `intersection()` | O(min(n,m)) |

---

## 🗝️ dict

| Operazione | Costo |
|----------|------|
| `d[k]` | O(1)* |
| `d[k]=v` | O(1)* |
| `del d[k]` | O(1)* |
| `k in d` | O(1)* |

---

## 🔄 Iteratori

| Operazione | Costo |
|----------|------|
| `range(n)` | O(1) |
| `for x in range(n)` | O(n) |
| `enumerate()` | O(n) |
| `zip(a,b)` | O(min(n,m)) |

---

## 🎯 Tipiche domande da esame

- Ricerca veloce? → **set / dict**
- Ordinamento? → **O(n log n)**
- Concatenazioni ripetute di stringhe? → ❌  
- Membership in lista? → **O(n)**
- Accesso per indice? → **O(1)**

---

## 🏁 Tabella finale (da ricordare)

| Struttura | Accesso | Inserimento | Membership |
|---------|--------|------------|-----------|
| list | O(1) | O(n) | O(n) |
| tuple | O(1) | ❌ | O(n) |
| set | ❌ | O(1)* | O(1)* |
| dict | O(1)* | O(1)* | O(1)* |

