#Algoritmi 

# Cammini minimi in grafi

**Cammini minimi a singola sorgente (senza pesi negativi)**

### Cammini minimi in grafi pesati

Sia G = (V,E,w) un grafo *orientato* o *non orientato* con pesi w **reali** sugli archi.
Il **costo** o **lunghezza** di un cammino $\pi$ = < $v_0$ , $v_1$ , $v_2$ , .... , $v_k$ > è : 

![[image-163.png]]

Un **cammino minimo** tra una coppia di vertici x e y è un cammino avente **costo minore o uguale** a quello di ogni altro cammino tra gli stessi vertici.

NOTA: il cammino minimo non è necessariamente unico.

![[Screenshot From 2025-12-18 13-50-38.gif]]


**Problema di Maps:**
![[image-164.png]]


### Esiste sempre un cammino minimo fra due nodi?

**No**, possiamo dividere il problema in due casi:
- Se non esiste nessun cammino da *u* a *v*  $\Rightarrow$ d(u,v) = +∞
- Se c'è un cammino che contien un **ciclo** (raggiungibile) il cui costo è *negativo* $\Rightarrow$     d(u,v) = -∞

**Oss:** se **G** non contiene cicli negativi, esistono cammini minimi che sono cammini *semplici (non contiene nodi ripetuti)*.

![[image-165.png|554x240]]

Passando per il ciclo con costo negativo *n-volte*, arriverò sicuramente ad ottenere un cammino negativo -> -∞. 

#### **Sottostruttura ottima:** 

Ogni **sottocammino** di un cammino minimo è un cammino minimo.

<span style="color:rgb(0, 176, 240)">dim:</span> tecnica *cut & paste*.

![[image-166.png]]

#### **Disuguaglianza triangolare:**

per ogni u, v, x $\in$ V, vale:
	d(u,v) $\leq$ d(u,x) + d(x,v)

![[image-167.png|519x200]]

Il **cammino** da *u* a *v* che passa per *x* è un cammino nel grafo e quindi il suo costo è almeno il costo del cammino minimo da *u* a *v*.

#### Cammini minimi a singola sorgente

![[image-168.png|578x361]]

Albero dei cammini minimi, partendo da Roma 

##### Problema del calcolo dei cammini minimi a singola sorgente

Due varianti:
- Dato **G** = (**V**, **E**, **w**), **s** $\in$ **V**, calcola le distanze di tutti i nodi da *s*, ovvero, $d_G$(s,v) per ogni **v** $\in$ **V**.
- Dato **G** = (**V**, **E**, **w**), **s** $\in$ **V**, calcola l'*albero dei cammini minimi di* **G** radicato in *s*.

### Albero dei cammini minimi / Shortest Path Tree (SPT)

T è un albero dei cammini minimi con sorgente s di un grafo G = (V,E,w) se:
- T è un albero radicato in s
- Per ogni v $\in$ V, vale:                                                                                                                           $d_T$(s,v) = $d_G$(s,v)

![[image-169.png|222x285]]



![[image-170.png]]


### Algoritmo di Dijkstra

Assunzione: tutti gli archi hanno peso non negativo, ovvero ogni arco(u,v) del grafo ha pesoo *w*(u,v) $\geq$ 0

<span style="color:rgb(255, 0, 0)">Idea</span>:
Pompare l'acqua nella sorgente

![[Screenshot From 2025-12-19 13-53-53.gif|380x308]]

- Archi come <span style="color:rgb(0, 176, 240)">tubi</span> 
- Peso degli archi come <span style="color:rgb(0, 176, 240)">lunghezza</span>
- Acqua <span style="color:rgb(0, 176, 240)">scorre</span> a <span style="color:rgb(0, 176, 240)">velocità costante</span> 

<span style="color:rgb(255, 0, 0)">Verso l'algoritmo</span>: <span style="color:rgb(0, 176, 240)">approccio</span> <span style="color:rgb(0, 176, 240)">greedy</span> (<span style="color:rgb(0, 176, 240)">goloso</span>)

1. Mantiene per ogni nodo *v* una *stima* (per eccesso) $D_{SV}$ alla distanza *d(s,v)* Inizialmente, unica stima finita $D_{SS}$ = 0.

2. Mantiene un insieme *X* di nodi per cui le stime sono *esatte*, e anche un albero *T* dei cammini minimi verso nodi in *X* (albero nero).                                                                         Inizialmente *X*={*s*}, *T* non ha archi.

3. Ad ogni passo aggiunge a *X* il nodo *u* in *V*-*X* la cui stima è minima: aggiunge a *T* uno specifico arco (arancione) entrante in *u*.

4. Aggiorna le stime guardando i nodi adiacenti a *u*.


  ![[image-171.png|411x333]]
  
I nodi da aggiungere progressivamente a X (e quindi a T) sono mantenuti in una **coda di priorità**, associati ad **un unico arco** (arco arancione) che li connette.

La stima per un nodo y $\in$ V-X è:
$D_{SY}$ = min{$D_{SX}$ + w(x,y) : (x,y) $\in$ E, x $\in$ X}
L'arco che fornisce il minimo è l'arco arancione.

Se y è in coda con arco **(x,y)** associato, e se dopo aver raggiunto <span style="color:rgb(112, 48, 160)">u</span> a T troviamo un arco <span style="color:rgb(112, 48, 160)">(u,v)</span> tale che 
$D_{SU}$ + w(x,y) < $D_{SX}$ + w(x,y), allora *rimpiazziamo* **(x,y)** con <span style="color:rgb(112, 48, 160)">(u,y)</span>, ed aggiorniamo $D_{SY}$.
  
  
![[image-172.png|300x406]]


#### **Pseudocodice:**
![[image-173.png|439x400]]

**Nota**: $\hat T$  è un albero che contiene tutti i nodi in X *più* i nodi correntemente contenuti nella coda di priorità (nodi arancioni), è composto cioè dagli archi di T (albero dei cammini minimi ristretto ai nodi in X) più gli archi arancioni (potenziali archi da aggiungere a T).

![[Screenshot From 2025-12-19 15-54-44.gif|359x298]]


#### **Correttezza:**

*Lemma:* 
Quando il nodo *v* viene estratto dalla coda con priorità vale:
- $D_{SV}$ = d(*s*,*v*)                                                                                      (*stima esatta*)
- Il cammino da *s* a *v* nell'albero corrente ha costo d(*s*,*v*)               (*camm. min in G*)

<span style="color:rgb(0, 176, 240)">dim</span> (per assurdo)
Sia v il primo nodo per cui l'alg sbaglia
Sia (u,v) l'arco aggiunto all'albero corrente (arco arancione)

(x,y): primo arco del cammino t.c. x $\in$ T e y $\notin$ T

![[Screenshot From 2025-12-19 16-17-02.gif]]


$\Rightarrow$ $D_{sy}$ $\leq$ d(s,x) + w(x,y) < d(s,u) + w(u,v)
	**assurdo**: l'algoritmo avrebbe estratto y e non v                                                                                    (se y=v, v avrebbe avuto una stima più piccola)  

#### **Analisi della complessità**:
Se si escludono le operazioni sulla coda con priorità: 
*tempo: O(m+n)*
Quanto costano le operazioni sulla coda con priorità?

(inserimenti $\leq$ n , estrazione del minimo $\leq$ n , decremento chiave $\leq$ n ) $\Rightarrow$ Il costo dipende dalla struttura dati.

#### **Tempo di esecuzione: implementazioni elementari**

Supponendo che il grafo **G** sia rappresentato tramite liste di adiacenza, e supponendo che tutti i nodi siano connessi ad *s*, avremo **n insert**, <span style="color:rgb(255, 192, 0)">n deleteMin</span> e al più <span style="color:rgb(0, 176, 240)">m decreaseKey</span> nella coda di priorità, al costo di: 

![[image-174.png|660x255]]

- **n $\cdot$ O(1)** + <span style="color:rgb(255, 192, 0)">n</span> $\cdot$ <span style="color:rgb(255, 192, 0)">O(n)</span> + <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(1)</span> = <span style="color:rgb(255, 192, 0)">O(</span>$n^2$<span style="color:rgb(255, 192, 0)">)</span> con array non ordinati
- **n $\cdot$ O(n)**+ <span style="color:rgb(255, 192, 0)">n</span> $\cdot$ <span style="color:rgb(255, 192, 0)">O(1)</span> + <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(n) </span>= <span style="color:rgb(0, 176, 240)">O(m</span> $\cdot$ <span style="color:rgb(0, 176, 240)">n)</span> con array ordinati
- **n $\cdot$ O(1)** + <span style="color:rgb(255, 192, 0)">n</span> $\cdot$ <span style="color:rgb(255, 192, 0)">O(n)</span> + <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(1)</span> = <span style="color:rgb(255, 192, 0)">O(</span>$n^2$<span style="color:rgb(255, 192, 0)"> )</span> con liste non ordinate 
- **n $\cdot$ O(n)** + <span style="color:rgb(255, 192, 0)">n</span> $\cdot$ <span style="color:rgb(255, 192, 0)">O(1)</span> + <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(n) </span>= <span style="color:rgb(0, 176, 240)">O(m</span> $\cdot$ <span style="color:rgb(0, 176, 240)">n)</span> con liste ordinate



![[image-175.png]]

- **n $\cdot$ O(log n)** + <span style="color:rgb(255, 192, 0)">n</span> $\cdot$<span style="color:rgb(255, 192, 0)"> O(log n) </span>+ <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(log n) </span>= <span style="color:rgb(0, 176, 240)">O(m</span> $\cdot$ <span style="color:rgb(0, 176, 240)">log n)</span> utilizzando heap binari o binomiali
- **n $\cdot$ O(1)** + <span style="color:rgb(255, 192, 0)">n</span> $\cdot$ <span style="color:rgb(255, 192, 0)">O(log n)*</span> + <span style="color:rgb(0, 176, 240)">O(m)</span> $\cdot$ <span style="color:rgb(0, 176, 240)">O(1)*</span> = O(<span style="color:rgb(0, 176, 240)">m</span> +n $\cdot$ log n) utilizzando heap di Fibonacci

Utilizzando la seconda soluzione, implementando gli Heap di Fibonacci, si ottiene la soluzione migliore.

**Tempo di esecuzione:** O(m +n $\cdot$ log n)

**Osservazione sulla DecreaseKey**
- Ricordiamo che le complessità computazionali esposte per la decreaseKey sono valide supponendo di avere un *puntatore diretto* all'elemento su cui eseguire l'operazione. 
$\Rightarrow$ Possiamo garantire tale condizione:
- Semplicemente mantenendo un puntatore tra il nodo *v* nell'array dei nodi della lista di adiacenza del grafo e l'elemento nella coda di priorità associato al nodo *v*, tale puntatore viene inizializzato nella fase di inserimento di quest'ultimo all'interno della coda.