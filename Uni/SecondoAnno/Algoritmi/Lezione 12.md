#Algoritmi 

### Usi meno scontati della visita DFS

#### Tenere il tempo 

**Pseudocodice:**
![561x326](../../imm/image-144.png)



**Quando non tutti i nodi sono raggiungibili dal punto di partenza:**
![449x345](../../imm/image-145.png) 

*Costo:* O(n+m) n -> (numero di vertici), m -> (numero di archi)

**Esempio:**
![434x284](../../imm/image-146.png)

Parto dal *pre(v)* minimo, *se* il successivo non è marcato $\Rightarrow$ elem precedente ++

**Proprietà:**

Per ogni coppia di nodi u e v, gli intervalli [pre(u),post(u)] e [pre(v),post(v)] o sono disgiunti o l'uno è contenuto nell'altro.

u è un antenato di v nell'albero DFS, se pre(u) < pre(v) < post(v) < post(u) condizione che rappresentiamo così:

[ u    [ v   v ]   u]

**Riconoscere i tipi di arco:**
![363x232](../../imm/image-147.png)

![296x355](../../imm/image-148.png)


### Cicli, DAG e ordinamenti topologici

**Riconoscere la presenza di un ciclo in un grafo diretto**

<span style="color:rgb(255, 0, 0)">Algoritmo:</span>
Fare una visita DFS e controllare se c'è un arco all'indietro

<span style="color:rgb(0, 176, 240)">Proprietà:</span> 
Un grafo diretto <span style="color:rgb(0, 176, 240)">G</span> ha un ciclo se e solo se la visita DFS rivela un arco all'indietro.

($\Leftarrow$): se c'è un arco all'indietro, chiaramente <span style="color:rgb(0, 176, 240)">G</span> ha un ciclo.
($\Rightarrow$): se c'è ciclo < $v_0$ , $v_1$ , .... , $v_k$ =$v_0$ >
	sia $v_i$ il primo nodo scoperto nella visita
	poiché $v_{i-1}$ è raggiungibile da $v_i$ , visito $v_{i-1}$ prima di terminare la visita di $v_i$ 
    allora ($v_{i-1}$ , $v_i$) è un arco all'indietro.

![169x159](../../imm/image-149.png)



**Definizione:** 
Un grafo diretto aciclico (DAG) è un grafo diretto G che non contiene cicli (diretti).

**Definizione:**
Un ordinamento topologico di un grafo diretto G = (V,E) è una funzione biettiva $\sigma$ : V -> {1,2,...,n} tale che per ogni arco (u,v) $\in$ E, $\sigma$(u) < $\sigma$(v)

![[image-150.png|604x212]]

#### Reti delle dipendenze

![[image-151.png|298x205]]

<span style="color:rgb(0, 176, 240)">nodi:</span> compiti da svolgere
<span style="color:rgb(0, 176, 240)">arco (u,v): </span>u deve essere eseguito prima di v

<span style="color:rgb(0, 176, 240)">Problema:</span>
Trovare un ordine in cui eseguire i compiti in modo da rispettare le dipendenze.

![[image-152.png|580x189]]

#### Dag che ammettono ordine topologico

**Teorema:**
Un grafo diretto <span style="color:rgb(0, 176, 240)">G</span> ammette un ordinamento topologico se e solo se <span style="color:rgb(0, 176, 240)">G</span> è un DAG.

<span style="color:rgb(0, 176, 240)">dim.</span> 
($\Rightarrow$):
per assurdo: sia $\sigma$ un ordinamento topologico di <span style="color:rgb(0, 176, 240)">G</span> 

e sia < $v_0$ , $v_1$ , .... , $v_k$ = $v_0$ > un ciclo
allora $\sigma$($v_0$) < $\sigma$($v_1$) < ... < $\sigma$($v_{k-1}$) < $\sigma$($v_k$)=$\sigma$($v_0$)

($\Leftarrow$): 

<span style="color:rgb(255, 0, 0)">Algoritmo:</span> 
Fare una visita DFS e restituisci i nodi in ordine decrescente rispetto ai tempi di fine visita post(v).

![[image-153.png]]

**Complessità temporale:**
Se G è rappresentato con *liste di adiacenza* $\Theta$(n +m)

**Esempio:**
![[image-154.png]]


**Correttezza**
Per ogni coppia di nodi *u* e *v*, gli intervalli [pre(u),post(u)] e [pre(v),post(v)]
o sono disgiunti o l'uno è contenuto nell'altro

![[image-155.png]]

Non ci possono essere archi all'indietro

Un **algoritmo alternativo**

![[image-156.png]]


![[Screenshot From 2025-12-17 16-43-11.gif]]


#### Componenti fortemente connesse 

Una <span style="color:rgb(0, 176, 240)">componente fortemente connessa</span> di un grafo <span style="color:rgb(0, 176, 240)">G = (V,E)</span> è un insieme <span style="color:rgb(255, 0, 0)">massimale</span> di vertici <span style="color:rgb(0, 176, 240)">C</span> $\subseteq$ <span style="color:rgb(0, 176, 240)">V</span> tale che per ogni coppia di nodi <span style="color:rgb(0, 176, 240)">u</span> e <span style="color:rgb(0, 176, 240)">v</span> in <span style="color:rgb(0, 176, 240)">C</span>, u è raggiungibile da <span style="color:rgb(0, 176, 240)">v</span> e <span style="color:rgb(0, 176, 240)">v</span> è raggiungibile da<span style="color:rgb(0, 176, 240)"> </span><span style="color:rgb(0, 176, 240)">u</span>. 

![[image-157.png]]

<span style="color:rgb(255, 0, 0)">Massimale</span>: se si aggiunge un qualsiasi vertice a <span style="color:rgb(0, 176, 240)">C</span> la proprietà non è più vera.

![Grafo delle componenti fortemente connesse di G][image-158.png]

E' sempre un <span style="color:rgb(0, 176, 240)">DAG</span>


#### Come calcolare le componenti fortemente connesse di un grafo diretto

![[image-157.png]]

<span style="color:rgb(255, 0, 0)">Proprietà 1</span>: Se si esegue la procedura *visitaDFSricorsiva* a partire da un nodo <span style="color:rgb(0, 176, 240)">u</span> la procedura termina dopo che tutti i nodi raggiungibili da <span style="color:rgb(0, 176, 240)">u</span> sono stati visitati.

<span style="color:rgb(255, 0, 0)">Idea</span>: Eseguire una visita a partire da un nodo di una *componente pozzo*, "eliminare" la componente e ripetere.

![][image-158.png]






**Come trovo una componente pozzo?**

![[image-159.png]]

<span style="color:rgb(255, 0, 0)">Proprietà 2</span>: Se <span style="color:rgb(0, 176, 240)">C</span> e <span style="color:rgb(0, 176, 240)">C' </span>sono due componenti e c'è un arco da un nodo in C verso uno in <span style="color:rgb(0, 176, 240)">C'</span>, allora il più grande valore post() in <span style="color:rgb(0, 176, 240)">C</span> è maggiore del più alto valore di post() di <span style="color:rgb(0, 176, 240)">C'</span>. 

<span style="color:rgb(0, 176, 240)">dim</span> : se la DFS visita prima <span style="color:rgb(0, 176, 240)">C'</span> di <span style="color:rgb(0, 176, 240)">C</span>: banale. 
Se visita prima <span style="color:rgb(0, 176, 240)">C</span>, allora si ferma dopo che ha raggiunto tutti i nodi di <span style="color:rgb(0, 176, 240)">C</span> e <span style="color:rgb(0, 176, 240)">C'</span> e termina su un nodo di <span style="color:rgb(0, 176, 240)">C</span>.

$\Rightarrow$ <span style="color:rgb(255, 0, 0)">Proprietà 3</span> : il nodo che riceve da una visita DFS il valore più grande di post() appartiene a una componente sorgente.
![[image-160.png]]

Avevamo bisogno di una componente pozzo?

<span style="color:rgb(255, 0, 0)">idea</span>: invertiamo gli archi!

![[image-161.png]]


**Pseudocodice:**
![[image-162.png]]

**Complessità temporale:** 
Se G è rappresentato con liste di adiacenza -> $\Theta$(n+m)


![[Screenshot From 2025-12-18 10-53-57.gif]]