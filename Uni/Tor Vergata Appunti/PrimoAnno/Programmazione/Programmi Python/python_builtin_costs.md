#programmazione 
# 🐍 Python Built-in Functions & Data Structures  
## ⏱️ Costi computazionali (Big-O)

> File pensato per Visual Studio Code  
> ✔ leggibile  
> ✔ stampabile  
> ✔ perfetto per ripasso ed esame  

---

## 📌 LEGENDA

- ⚡ **O(1)** → tempo costante  
- 🔁 **O(n)** → lineare  
- 🌲 **O(log n)** → logaritmico  
- 🔥 **O(n log n)** → ordinamento  
- ⚠️ `*` → tempo medio (worst case peggiore)

---

# 🔧 FUNZIONI BUILT-IN GENERICHE

| Funzione | Costo | Note |
|--------|------|------|
| ⚡ `len(x)` | O(1) | Lunghezza memorizzata |
| ⚡ `type(x)` | O(1) | |
| ⚡ `id(x)` | O(1) | |
| ⚡ `abs(x)` | O(1) | |
| ⚡ `round(x)` | O(1) | |
| 🔁 `sum(iter)` | O(n) | |
| 🔁 `max(iter)` | O(n) | |
| 🔁 `min(iter)` | O(n) | |
| 🔁 `any(iter)` | O(n) | Best case O(1) |
| 🔁 `all(iter)` | O(n) | Best case O(1) |
| 🔥 `sorted(iter)` | O(n log n) | Crea nuova lista |

---

# 📋 LIST (`list`) 🧱

| Operazione | Costo | |
|----------|------|--|
| ⚡ `x[i]` | O(1) | Accesso |
| ⚡ `x[i] = v` | O(1) | |
| ⚡ `append(v)` | O(1)* | Amortizzato |
| ⚡ `pop()` | O(1) | Ultimo |
| 🔁 `pop(i)` | O(n) | Shift |
| 🔁 `insert(i,v)` | O(n) | |
| 🔁 `remove(v)` | O(n) | |
| 🔁 `v in x` | O(n) | |
| 🔥 `sort()` | O(n log n) | Timsort |
| 🔁 `reverse()` | O(n) | |
| 🔁 `x + y` | O(n) | Copia |

---

# 📚 TUPLE (`tuple`) 📦

| Operazione | Costo |
|----------|------|
| ⚡ `t[i]` | O(1) |
| 🔁 `v in t` | O(n) |
| ⚡ `len(t)` | O(1) |

---

# 🔤 STRINGHE (`str`) ✏️

| Operazione | Costo | |
|----------|------|--|
| ⚡ `s[i]` | O(1) | |
| ⚡ `len(s)` | O(1) | |
| 🔁 `s + t` | O(n) | Copia |
| 🔁 `'x' in s` | O(n) | |
| 🔁 `replace()` | O(n) | |
| 🔁 `split()` | O(n) | |
| 🔁 `join()` | O(n) | |

⚠️ **Stringhe immutabili** → ogni modifica crea una nuova stringa

---

# 🧠 SET (`set`) ⚙️

| Operazione | Costo |
|----------|------|
| ⚡ `add(v)` | O(1)* |
| ⚡ `remove(v)` | O(1)* |
| ⚡ `v in s` | O(1)* |
| 🔁 `union()` | O(n) |
| 🔁 `intersection()` | O(min(n,m)) |

---

# 🗂 DICT (`dict`) 🗝️

| Operazione | Costo |
|----------|------|
| ⚡ `d[k]` | O(1)* |
| ⚡ `d[k]=v` | O(1)* |
| ⚡ `del d[k]` | O(1)* |
| ⚡ `k in d` | O(1)* |
| ⚡ `keys()` | O(1) |
| ⚡ `values()` | O(1) |
| ⚡ `items()` | O(1) |

---

# 🧮 FUNZIONI MATEMATICHE (`math`) 📐

| Funzione | Costo |
|--------|------|
| ⚡ `sqrt(x)` | O(1) |
| ⚡ `log(x)` | O(1) |
| ⚡ `sin(x)` | O(1) |
| ⚡ `cos(x)` | O(1) |
| ⚡ `factorial(n)` | O(n) |

---

# 🧪 ITERATORI & RANGE 🔄

| Operazione | Costo |
|----------|------|
| ⚡ `range(n)` | O(1) |
| 🔁 `for x in range(n)` | O(n) |
| 🔁 `enumerate()` | O(n) |
| 🔁 `zip()` | O(min(n,m)) |

---

# 🎯 TRUCCHI DA ESAME

✅ Accesso rapido → **list, tuple, str**  
✅ Membership veloce → **set, dict**  
❌ Inserimenti centrali → **list**  
❌ Stringhe concatenate in loop → usa `join()`  
⚠️ Hash → medio O(1), worst O(n)

---

# 🏁 RIASSUNTO FINALE

| Struttura | Accesso | Inserimento | Membership |
|---------|--------|------------|-----------|
| list | ⚡ O(1) | 🔁 O(n) | 🔁 O(n) |
| tuple | ⚡ O(1) | ❌ | 🔁 O(n) |
| set | ❌ | ⚡ O(1)* | ⚡ O(1)* |
| dict | ⚡ O(1)* | ⚡ O(1)* | ⚡ O(1)* |

---

📌 **Suggerimento**:  
Apri il file in VS Code → `Ctrl + Shift + V` (Preview Markdown)

