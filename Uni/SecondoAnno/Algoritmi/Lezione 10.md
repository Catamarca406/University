#Algoritmi 
# Grafi e visite di grafi 

### Origine storiche
Nel 1736, il matematico Eulero, affrontò l'annoso problema dei 7 ponti di Königsberg (Prussia):

![421x332](../../imm/image-117.png)

E' possibile o meno fare una passeggiata che parta da un *qualsiasi* punto della città e percorra *una ed una* sola volta ciascuno dei 7 ponti?

Eulero affrontò il problema schematizzando *topologicamente* la pianta della città, epurando così l'istanza da insignificanti dettagli *topografici*.

![670x169](../../imm/image-118.png)

e così Königsberg venne rappresentata con un insieme di **4 punti** (uno per ciascuna zona della città), opportunatamente uniti da *7 linee* (una per ciascun ponte).


### Definizione di Grafo (non orientato)

Un **grafo G = (V,E)** consiste in:
- un insieme **V** di vertici (o *nodi*).
- un insieme **E** di coppie (non ordinate) di vertici, chiamati **archi**.

#### Esempio
Grafo di Eulero associato alla città di Königsberg:
**V = {A,B,C,D}**
**E = { (A,B),(A,B),(A,D), (B,C), (B,C), (B,D), (B,D), (C,D) }**

![373x282](../../imm/image-119.png)

Nota: E' più propriamente detto *multigrafo*, in quanto contiene *archi paralleli*.

![362x233](image-120.png)


#### Terminologia
**G = (V,E)** grafo non diretto
**n** = |V| numero di vertici
**m** = |E| numero di archi
**u** ed **v** sono *adiacenti* (*vicini*)
**(u,v)** è *incidente* a *u* e a *v* (detti *estremi*)
**δ(u): grado** di *u:* # numero di archi incidenti a *u* 
**grado** di **G** = $max_{v \in V}$ {δ(v)}

![221x206](../../imm/image-122.png) 



### Definizione di Grafo Diretto

Un **grafo diretto D = (V,A)** consiste in:
- un insieme **V** di **vertici** (o *nodi*).
- un insieme **A** di coppie **ordinate** di vertici, detti **archi diretti**.

#### Esempio

![326x218](../../imm/image-121.png)

#### Terminologia

**G = (V,E)** grafo diretto
**n** = |V| numero di vertici
**m** = |E| numero di archi
**u** ed **v** sono *adiacenti* (*vicini*)
**(u,v)** è **uscente** da *u* ed **entrante** in *v*
$δ_{out}$(u): **grado uscente** di *u:* # archi uscenti da *u* 
$δ_{in}$(u): **grado entrante** di *u:* # archi entranti da *u*

**grado entrante** di **G** = $max_{v \in V}$ {$δ_{in}$(v)}
**grado uscente** di **G** = $max_{v \in V}$ {$δ_{out}$(v)}

![221x206](../../imm/image-123.png)


### Relazione fra grado dei nodi e numero di archi

Una semplice proprietà:

![189x103](../../imm/image-126.png)

- **δ(u): grado** di *u:* # numero di archi incidenti a *u*
- **m** = |E| numero di archi

![435x138](../../imm/image-124.png)

Il *grado di un nodo* (numero di collegamenti con altri nodi) è doppiamente più grande rispetto al *numero di archi* (collegamenti totali dei nodi in un grafo) all'interno di un grafo.

$\Rightarrow$ in ogni grafo # nodi di grado dispari è pari



![189x103](../../imm/image-127.png)

Cosa ottengo se sommo i gradi: 

![435x137](../../imm/image-128.png)



### Terminologia

![135x295](../../imm/image-129.png)

- **Cammino:** sequenza di nodi connessi da archi. $\Rightarrow$ (L,A)
- **Lunghezza** di un cammino: # archi del cammino $\Rightarrow$ (L,A) = 5
- **Distanza:** La lunghezza del più corto cammino tra due vertici si dice *distanza* tra i due vertici. $\Rightarrow$ (L,A) = 4

in un grafo *orientato*, il cammino deve rispettare il verso di orientamento degli archi.


![135x293](../../imm/image-130.png)

- **G** è **connesso** se esiste un cammino per ogni coppia di vertici.
- **Ciclo:** un cammino **chiuso**, ovvero un cammino da un vertice a se stesso. 
- **Diametro** è la massima distanza fra due nodi:
	- $max_{u,v \in V}$  dist(u,v)
	- il diametro di un grafo non connesso è ∞


- **Grafo Pesato:** è un grafo **G = (V,E,w)** in cui ad ogni arco viene associato un valore definito dalla funzione peso **w** (definita su un opportuno insieme, di solito reali).

![315x186](../../imm/image-131.png) 



![279x272](../../imm/image-132.png)


### # Archi che può avere un grafo di n nodi

![109x105](../../imm/image-133.png)

**Grafo totalmente sconnesso**: è un grafo G = (V,E) tale che V $\notin$ ∅ ed E $\notin$ ∅.

**Grafo completo**: per ogni coppia di nodi  esiste un arco che li congiunge.
![k_5][image-134.png]
Il grafo completo con *n* vertici verrà indicato con $k_n$ 
*m* = |E| = n $\cdot$ $\frac{(n-1)}{2}$  

$\Rightarrow$ un grafo (senza archi paralleli) può avere un numero di archi *m* compreso tra *0* e
*n* $\cdot$ $\frac{(n-1)}{2}$ = $\Theta(n^2)$


### Grafo connesso con numero minimo di archi

#### Definizione
Un albero è un grafo connesso ed aciclico.

![372x183](../../imm/image-135.png)

#### Teorema
Sia T = (V,E) un albero $\Rightarrow$ |E| = |V| -1

![625x376](../../imm/image-136.png)


### Problema dei 7 ponti

#### Definizione
Dato un grafo G, un *ciclo* (rispettivamente un *cammino*) *Euleriano* è un ciclo (rispettivamente un *cammino* non chiuso) di G che passa per tutti gli archi di G una e una sola volta.

### Teorema (di Eulero)
Un grafo G ammette un *ciclo Euleriano* se e solo se tutti i nodi hanno grado pari. Inoltre, ammette un *cammino Euleriano* se e solo se tutti i nodi hanno grado pari tranne due (i due nodi di grado dispari sono gli estremi del cammino).

![image-137](../../imm/image-137.png)

Il problema dei 7 ponti non ammette soluzione! 