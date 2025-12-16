#Algoritmi 

# Il problema della coda con priorità 

![[image-93.png]]

## *Operazioni aggiuntive*

![[image-90.png]]


*Applicazioni:* gestione code in risorse condivise, gestione priorità in processi concorrenti progettazione di algoritmi efficienti per diversi problemi fondamentali (es: calcolo cammini minimi in un grafo, minimo albero ricoprente, ordinamento, ecc).

## Quattro implementazioni elementari

1. Array non ordinato
2. Array ordinato
3. Lista non ordinata
4. Lista ordinata
### Array non ordinato

Lo dimensiono sufficientemente grande e tengo traccia del numero *n* di elementi nella coda in una variabile di appoggio

- **FindMin**: $\Theta$(n)  (guardo tutti gli elementi)
- **Insert**: O(1) (inserisco in coda)
- **Delete**: O(1) (viene fornito il riferimento diretto all'elemento da cancellare, lo posso cancellare in O(1) sovracopiando l'ultimo elemento)
- **DeleteMin**: $\Theta$(n) (cerco prima il minimo in $\Theta(n)$, successivamente lo cancello in O(1))

### Array ordinato

Lo dimensiono sufficientemente grande, lo tengo *ordinato* in ordine *decrescente* e tengo traccia del numero *n* di elementi nella coda in una variabile di appoggio

- **FindMin**: O(1)
- **Insert**: O(n) (trovo in $\Theta$(log n) la giusta posizione, poi si fanno O(n) spostamenti)
- **Delete**: O(n) (bisogna fare O(n) spostamenti)
- **DeleteMin**: O(1) (l'elemento minimo è in fondo all'array, non bisogna fare spostamenti)

### Lista non ordinata

La considero **bidirezionale**:

![[image-94.png|337x55]]

- **FindMin**: $\Theta$(n) (devo guardare tutti gli elementi)
- **Insert**: O(1) (inserisco in coda o in testa)
- **Delete**: O(1) (mi viene fornito il riferimento diretto all'elemento da cancellare, lo cancello in O(1) agendo sui puntatori)

### Lista ordinata

Tengo la lista bidirezionale *ordinata* in ordine *crescente* 

- **FindMin**: O(1) (il minimo è in testa alla lista)
- **Insert**: O(n) (trovo in O(n) la giusta posizione, e poi faccio in O(1) l'inserimento)
- **Delete**: O(1) (agisco sui puntatori)
- **DeleteMin**: O(1) (basta far puntare la testa della lista al secondo elemento della lista stessa)

### Riepilogo implementazioni elementari
![[image-95.png]]


## Tre implementazioni evolute

$\Rightarrow$ *d-heap*: generalizzazione degli heap binari visti per l'ordinamento
$\Rightarrow$ *Heap Binomiali*
$\Rightarrow$ *Heap di Fibonacci* (cenni)


### d-heap

#### Definizione

Un d-heap è un albero radicato d-ario con le seguenti proprietà:
1. **Struttura**: è completo almeno fino al penultimo livello, e tutte le foglie sull'ultimo livello sono compattate verso sinistra.
2. **Contenuto informativo**: ogni nodo v contiene un elemento *elem(v)* ed una chiave *chiave(v)* presa da un dominio ordinato.
3. *Ordinamento parziale (inverso) dell'heap (min-heap)*: chiave(v) $\geq$ chiave(parent(v)) per ogni nodo v diverso dalla radice.

#### Esempio

![[image-96.png]]

#### Proprietà

1. Un d-heap con n nodi ha **altezza** $\Theta(log_d n)$ dove *d* è il numero di sottorami della radice
2. La **radice** contiene l'**elemento con chiave minima** (per via della proprietà di ordinamento a heap).
3. Può essere **rappresentato implicitamente** tramite vettore posizionale grazie alla proprietà di struttura.

#### Procedure Ausiliarie
Utili per ripristinare la proprietà di ordinamento a heap su un nodo v che non la soddisfi.

![[image-97.png|642x266]]

##### findMin
![[image-98.png|575x105]]

**T(n) = O(1)**

##### insert(elem e, chiave k)


-> *insert(e,8)*

![[ezgif.com-animated-gif-maker (1).gif]]

Insert permette di creare un nuovo nodo *v* con elemento *e* e chiave *k*, in modo che diventi una foglia sull'ultimo livello di *T*. La proprietà dell'ordinamento a heap viene ripristinata spingendo il nodo *v* verso l'alto tramite ripetuti scambi di nodi.

**Costo:** T(n)=O($\log_d$ n) per l'esecuzione di *muoviAlto*

##### delete(elem e) e deleteMin

![[ezgif.com-animated-gif-maker.gif]]

Delete scambia il nodo *v* contenente l'elemento *e* con una qualunque foglia *u* sull'ultimo livello di *T*, e poi elimina *v*. Ripristina infine la proprietà dell'ordinamento a heap spingendo il nodo *u* verso la sua posizione corretta scambiandolo ripetutamente con il proprio padre o con il proprio figlio contenente la chiave più piccola.

**Costo:** O($\log_d$ n) o O(d $\log_d$ n) per l'esecuzione di *muoviAlto* o *muoviBasso* 

Può essere utilizzata anche per implementare la cancellazione del minimo, con costo 
O(d $log_d$ n)

##### decreaseKey(elem e, chiave d)
![[ezgif.com-animated-gif-maker (2).gif]]

DecreaseKey decrementa il valore della chiave nel nodo *v* contenente l'elemento *e* della qualità richiesta *d*. Ripristina poi la proprietà dell'ordinamento a heap spingendo il nodo *v* verso l'alto tramite ripetuti scambi di nodi.

**Costo:** T(n) = O($log_d$ n) per l'esecuzione di *muoviAlto* 

##### increaseKey(elem e, chiave d)

![[ezgif.com-animated-gif-maker (3).gif]]

IncreaseKey aumenta il valore della chiave nel nodo contenente l'elemento *e* della quantità richiesta *d*. Ripristina poi la proprietà dell'ordinamento a heap spingendo il nodo *v* verso il basso tramite ripetuti scambi di nodi.

**Costo:** O(d $\log_d$ n) per l'esecuzione di *muoviBasso* 

##### merge(CodaPriorità $c_1$ , CodaPriorità $c_2$)

Due modi: 
1. **Costruire da zero:** si distruggono le due code e se ne crea una nuova contenente l'unione degli elementi.
2. **Inserimenti ripetuti:** si inseriscono ripetutamente gli elementi della coda più piccola in quella più grande.

**Osservaz**

#### Costruzione da zero

**Idea:** 
Genero un nuovo heap d-ario contenente tutti gli elementi in $c_1$ e $c_2$ 

**Come:**
- Generalizzazione della procedura **heapify**.
- Rendo i d sottoalberi della radice heap ricorsivamente e chiamo *muoviBasso* sulla radice.

**Complessità** (d costante):
T(**n**) = d T(*n*/d) + O(d $\log_d$ **n**)                           dove n = |$c_1$| + |$c_2$| 

Teorema Master (*caso 1*) $\Rightarrow$ T(**n**) = $\Theta$(**n**) 

#### Inserimenti ripetuti

Inseriamo ad uno ad uno tutti gli elementi della coda più piccola nella coda più grande.

Sia **k = min { |$c_1$| , |$c_2$| }** e **n = |$c_1$| + |$c_2$|**.
Eseguiamo quindi k inserimenti nella coda più grande.

Costo: O(k $\log$ n), dove **n = |$c_1$| + |$c_2$|**.

L'approccio conviene quindi per **k log n = o(n), cioè per ** 
				k = o(n / log n)**


#### Riepilogo 

![[image-103.png]]

$\Rightarrow$ L'obiettivo è implementare una coda di priorità con una struttura dati che non comporti **costi lineari** ! 


### Heap Binomiali

#### Alberi binomiali

Un **albero binomiali** $B_i$ è definito ricorsivamente come segue:
1. $B_0$ consiste di un *unico* nodo.
2. Per i > 0, $B_{i+1}$ è ottenuto fondendo due alberi binomiali $B_i$ ponendo la radice dell'uno come figlia della radice dell'altro.  

![[image-104.png]]

#### Proprietà strutturali 

Un albero binomiale $B_h$ gode delle seguenti proprietà:
1. Numero di nodi ( |$B_h$| ) : n = $2^h$.
2. Grado della radice: D(n) = $\log_2$ n.
3. Altezza: H(n) = h = $\log_2$ n. 
4. Figli della radice: i sottoalberi radicati nei figli della radice di $B_h$ sono $B_0$ , $B_1$ ,..., $B_{h-1}$

	**Dimostrazione per induzione su *h***

#### Definizione di heap binomiale

Un heap binomiale è una **foresta (collezione) di alberi binomiali** che gode delle seguenti proprietà: 
1. **Unicità:** per ogni intero i $\geq$ 0 , esiste al più un $B_i$ nella foresta.
2. **Contenuto informativo:** ogni nodo *v* contiene un elemento *elem(v)* ed una chiave *chiave(v)* presa da un dominio totalmente ordinato.
3. **Ordinamento a heap:** chiave(v) $\geq$ chiave(parent(v)) per ogni nodo v diverso da una delle radici.


![[image-105.png|580x429]]

![[image-106.png|579x415]]

#### Proprietà topologiche
- Dalla proprietà di unicità degli alberi binomiali che lo costituiscono, ne deriva che un heap binomiale di *n* elementi è formato dagli alberi binomiali $B_{i_0}$ , $B_{i_1}$ ,...., $B_{i_h}$ , dove $i_0$ , $i_1$ ,..., $i_h$ corrispondono alle posizioni degli *1* nella rappresentazione in base *2* di *n*.

 $\Rightarrow$ Ne consegue che in un heap binomiale con *n* nodi, vi sono al più $\lceil \log n \rceil$  *alberi binomiali*, ciascuno con *grado ed altezza O(log n)*.

#### Procedura ausiliaria

Utile per ripristinare la proprietà di unicità in un heap binomiale (ipotizziamo di scorrere la lista delle radici da sinistra verso destra, in ordine crescente rispetto all'indice degli alberi binomiali)

![[image-107.png]]

**T(n): lineare nel numero di alberi binomiali in input**
Ogni fusione diminuisce di uno il numero di alberi binomiali.


![[image-108.png|604x448]]


#### Realizzazione 

![[image-109.png|674x385]]
![[image-110.png|672x417]]
![[image-111.png|672x222]]

**Tutte le operazioni richiedono tempo T(n) = O(log n)** 
Durante l'esecuzione della procedura ristruttura esistono infatti al più tre $B_i$ , per ogni i $\geq$ 0


#### Operazioni viste graficamente

**DeleteMin(H)**
![[ezgif.com-animated-gif-maker (4).gif]]



**DecreaseMin(H)**
![[ezgif.com-animated-gif-maker (5).gif]]


**Merge(H)**
![[image-114.png|566x425]]

### Heap di Fibonacci

**Heap binomiale rilassato:** si ottiene da un heap binomiale rilassando la proprietà di *unicità* di $B_i$ ed utilizzando un atteggiamento più "pigro" durante l'operazione insert (potremmo ristrutturare la foresta dopo).

**Heap di fibonacci:** si ottiene da un *heap binomiale rilassato* indebolendo la proprietà di **struttura** dei $B_i$ che non sono più necessariamente alberi binomiali.

Analisi sofisticata: i tempi di esecuzione sono **ammortizzati** su sequenze di operazioni, cioè dividendo il **costo complessivo** della sequenza di operazioni per il numero di operazioni della sequenza.

#### Conclusioni

![[image-115.png]]

L'analisi per d-Heap e Heap Binomiali è nel caso peggiore, mentre quella per gli Heap di Fibonacci è ammortizzata (per le operazioni *asteriscate*).

#### Analisi ammortizzata
- Il *costo ammortizzato* di un'operazione è il costo "*medio*" rispetto a una *sequenza* qualsasi di operazioni.
- *Esempio:* se un'operazione ha costo ammortizzato costante e eseguo una sequenza (qualsiasi) di *k* operazioni è possibile che il costo di una singola operazione può non essere costante, ma l'intera sequenza costerà **O(k)**.
- Diverso dal **costo medio:** non c'è nessuna distribuzione di probabilità (sulla sequenza da eseguire) e l'algoritmo è un algoritmo deterministico.
- Molto utile quando si vogliono **buone prestazioni sull'intera sequenza** e non garanzie sulla singola operazione.
	- esempio: progettare algoritmi veloci attraverso strutture dati efficienti.

Per esempio, nel nostro caso:

**Teorema**
![[image-116.png]]
