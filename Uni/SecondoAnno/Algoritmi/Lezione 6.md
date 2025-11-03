#Algoritmi 
### Sommario pt1

- Delimitazioni inferiori e superiori (di <span style="color:rgb(0, 176, 240)">algoritmi</span> e <span style="color:rgb(0, 176, 240)">programmi</span>)
- Quanto velocemente si possono ordinare <span style="color:rgb(0, 176, 240)">n</span> elementi? 
	- Una soglia (asintotica) di velocità sotto la quale non si può scendere: un <span style="color:rgb(0, 176, 240)">lower bound </span> 
		- per una classe di algoritmi "ragionevoli" --> quelli basati su confronti
	- Una tecnica elegante che usa gli <span style="color:rgb(0, 176, 240)">alberi di decisione</span>
- E se si esce da questa classe di algoritmi? 
	- <span style="color:rgb(0, 176, 240)">integer sort </span>e <span style="color:rgb(0, 176, 240)">bucket sort</span> (per interi "piccoli")
	- <span style="color:rgb(0, 176, 240)">radix sort</span> (per interi più grandi)
### Delimitazioni inferiori e superiori (di algoritmi e problemi)

**Delimitazioni <span style="color:rgb(0, 176, 240)">superiori</span> (upper bound) <span style="color:rgb(0, 176, 240)">inferiori</span> (lower bound) di un <span style="color:rgb(0, 176, 240)">Algoritmo</span>:**

<span style="color:rgb(255, 0, 0)">Definizione per Upper Bound</span> 
Un algoritmo A ha complessità (costo di esecuzione) <span style="color:rgb(0, 176, 240)">O(f(n))</span> rispetto ad una certa risorsa di calcolo, se la quantità r(n) di risorda utilizzata da <span style="color:rgb(0, 176, 240)">A</span> nel caso peggiore su istanze di dimenione n verifica la relazione r(n)=O(f(<span style="color:rgb(0, 176, 240)">n</span>)).

<span style="color:rgb(255, 0, 0)">Definizione per Lower Bound</span> 
Un algoritmo A ha complessità (costo di esecuzione) <span style="color:rgb(0, 176, 240)">Ω(f(n))</span><span style="color:rgb(0, 176, 240)"> </span> rispetto ad una certa risorsa di calcolo, se la quantità <span style="color:rgb(0, 176, 240)">r(n)</span> di risorsa usata da A nel caso peggiore su istanze di dimensione n verifica la relazione<span style="color:rgb(0, 176, 240)"> r(n)=Ω(f(n))</span>.


**Delimitazioni <span style="color:rgb(0, 176, 240)">superiori</span> (upper bound) <span style="color:rgb(0, 176, 240)">inferiori</span> (lower bound) di un <span style="color:rgb(0, 176, 240)">Problema</span>:**

<span style="color:rgb(255, 0, 0)">Definizione per Upper Bound</span> 
Un problema <span style="color:rgb(0, 176, 240)">P</span> ha complessità <span style="color:rgb(0, 176, 240)">O(f(n))</span> rispetto ad una risorsa di calcolo se <span style="color:rgb(255, 0, 0)">esiste</span> un algoritmo che risolve <span style="color:rgb(0, 176, 240)">P</span> il cui costo di esecuzione rispetto quella risorsa è <span style="color:rgb(0, 176, 240)">O(f(n))</span>.

<span style="color:rgb(255, 0, 0)">Definizione per Lower Bound</span> 
Un problema <span style="color:rgb(0, 176, 240)">P</span> ha complessità Ω(f(n)) rispetto ad una risorsa di calcolo se <span style="color:rgb(255, 0, 0)">ogni algoritmo</span> che risolve <span style="color:rgb(0, 176, 240)">P</span> ha costo di esecuzione nel caso peggiore <span style="color:rgb(0, 176, 240)">Ω(f(n))</span> rispetto quella risorsa.

#### Ottimalità di un algoritmo 

<span style="color:rgb(255, 0, 0)">Definizione</span> 
Dato un problema <span style="color:rgb(0, 176, 240)">P</span> con complessità <span style="color:rgb(0, 176, 240)">Ω(f(n))</span> rispetto ad una risorsa di calcolo, un algoritmo che risolve <span style="color:rgb(0, 176, 240)">P</span> è (asintoticamente) <span style="color:rgb(255, 0, 0)">ottimo</span> se ha costo di esecuzione <span style="color:rgb(0, 176, 240)">O(f(n))</span> rispetto a quella risorsa.

#### Complessità temporale del problema dell'ordinamento 

- Upper Bound: O($n^2$)
	-Insertion Sort, Selection Sort, Quick Sort, Bubble Sort
	
- Un upper Bound migliore: O(log n) 
	-Merge Sort, Heap Sort 
- Lower Bound: Ω(n)
   -banale: ogni algoritmo che ordina n elementi li deve almeno leggere tutti 
   
Abbiamo un gap di log n tra upper bound e lower bound!


![687x200](../../imm/Pastedimage20251102233059.png)

Notare: Tutti gli algoritmi citati prima sono algoritmi di ordinamento per confronto.

**Teorema**
<span style="color:rgb(0, 176, 240)">Ogni</span> algoritmo basato su confronti che ordina <span style="color:rgb(0, 176, 240)">n</span> elementi deve fare nel caso peggiore Ω(<span style="color:rgb(0, 176, 240)">n</span> log <span style="color:rgb(0, 176, 240)">n</span>) confronti.

<span style="color:rgb(255, 0, 0)">Nota</span>: Il <span style="color:rgb(0, 176, 240)"># di confronti</span> che un algoritmo esegue è un <span style="color:rgb(255, 0, 0)">lower bound</span> al # di <span style="color:rgb(0, 176, 240)">passi elementari </span>che esegue.

**Corollario**
Il <span style="color:rgb(0, 176, 240)">Merge Sort</span> e l'<span style="color:rgb(0, 176, 240)">Heap Sort</span> sono algoritmi <span style="color:rgb(0, 176, 240)">ottimi</span>  (almeno dentro la classe di algoritmi basati su confronti).


### Albero di decisione
Gli algoritmi di ordinamento per confronto possono essere descritti in modo astratto in termini di <span style="color:rgb(0, 176, 240)">alberi di decisione</span>.

Un generico algoritmo di confronto lavora nel modo seguente:
	- confronta due elementi $a_i$ ed $a_j$  (ad esempio effettua il test $a_i \leq a_j$).
	- a seconda del risultato - riordina e/o decide il confronto successivo da eseguire.

Albero di decisione - Descrive i confronti che l'algoritmo esegue quando opera su un input di una <span style="color:rgb(0, 176, 240)">determinata dimensione</span>. I movimenti dei dati e tutti gli altri aspetti dell'algoritmo vengono ignorati.

#### Alberi di decisione
- Descrive le  diverse sequenze di confronti che <span style="color:rgb(0, 176, 240)">A</span> potrebbe fare su istanze di dimensione <span style="color:rgb(0, 176, 240)">n</span>
- Nodo interno (non foglia): <span style="color:rgb(0, 176, 240)">i : j</span>
	-modella il <span style="color:rgb(0, 176, 240)">confronto</span> tra $a_i$ e $a_j$
	 
- Nodo foglia: 
	-modella una risposta (output) dell'algoritmo: <span style="color:rgb(0, 176, 240)">permutazione degli elementi</span> 

![693x264](../../imm/Pastedimage20251103145356.png)

I numeri segnati nell'albero corrispondono ai pedici dell'input.
Osservazioni:
1.	L'albero di decisione <span style="color:rgb(0, 176, 240)">non è associato</span> ad un problema o ad un algoritmo
2.  L'albero di decisione è associato ad un <span style="color:rgb(0, 176, 240)">algoritmo</span> e a una <span style="color:rgb(0, 176, 240)">dimensione dell'istanza</span>
3.  L'albero di decisione descrive le diverse sequenze di confronti che un certo algoritmo può eseguire su istanze di una <span style="color:rgb(0, 176, 240)">data dimensione</span>
4.  L'albero di decisione è una descrizione alternativa dell'algoritmo (customizzato per istanze di una certa dimensione)

Proprietà:
1) Per una particolare istanza, i confronti su essa rappresentano un <span style="color:rgb(0, 176, 240)">cammino radice-foglia</span>.
2) L'algoritmo segue un cammino diverso a seconda delle caratteristiche dell'istanza: <span style="color:rgb(0, 176, 240)">Caso peggiore</span> = cammino più lungo.
3) Il numero di confronti nel caso peggiore è pari <span style="color:rgb(0, 176, 240)">all'altezza dell'albero di decisione</span>.
4) Un albero di decisione di un algoritmo (corretto) che risolve il problema dell'ordinamento di <span style="color:rgb(0, 176, 240)">n</span> elementi deve avere necessariamente <span style="color:rgb(0, 176, 240)">almeno n! foglie</span>. 


Lemma 
Un albero binario T con k foglie, ha altezza almeno $log_2 k$ 

dim (per induzione su k)
caso base: k=1            altezza almeno $log_2$ 1 = 0
caso induttivo: k>1

considera il nodo interno <span style="color:rgb(0, 176, 240)">v</span> più vicino alla radice che ha due figli (<span style="color:rgb(0, 176, 240)">v</span> potrebbe essere la radice), nota che <span style="color:rgb(0, 176, 240)">v</span> deve esistere perché <span style="color:rgb(0, 176, 240)">k</span>>1.



