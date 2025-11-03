#Algoritmi 
# HeapSort

- Approccio incrementale
- Seleziona gli elementi dal più grande al più piccolo
- Utilizza una <span style="color:rgb(255, 255, 0)">struttura</span> <span style="color:rgb(255, 255, 0)">dati</span> <span style="color:rgb(255, 255, 0)">efficiente</span>
	- Estrae in tempo O(log n) del massimo

Definizioni:
	<span style="color:rgb(255, 255, 0)">Tipi di dato</span>:
		Specifica una collezione di oggetti e delle operazioni di interesse su tale collezione (Esempio: Dizionario, mantiene un insieme di elementi con chiavi soggetto a operazioni di inserimento, cancellazione, ricerca)
	<span style="color:rgb(255, 255, 0)">Struttura</span> <span style="color:rgb(255, 255, 0)">dati</span>:
		Organizzazione dei dati che permette di memorizzare la collezione e supportare le operazioni di un tipo di dato usando meno risorse di calcolo possibile
	Cruciale: 
		Progettare una struttura dati H (heap) su cui eseguire efficientemente le operazioni: 
			- Dato un array A, generare velocemente H
			- Trovare il più grande oggetto in H
			- Cancellare il più grande oggetto da H 
	<span style="color:rgb(255, 255, 0)">Tipo di dati associato</span>: coda con priorità (ci torneremo)


Albero: qualche altra definizione 

![[Pasted image 20251029151515.png |600]]

<span style="color:rgb(255, 255, 0)">Albero d-ario: albero in cui tutti i nodi interni hanno</span> (<span style="color:rgb(255, 255, 0)">al più</span>) <span style="color:rgb(255, 255, 0)">d-figli</span>
d=2 $\Rightarrow$ <span style="color:rgb(255, 255, 0)">albero binario </span>

un albero d-ario è <span style="color:rgb(255, 255, 0)">completo</span>: se tutti i nodi hanno esattamente d figli e le foglie sono tutte allo stesso livello  

![[Pasted image 20251029153022.png | 600]]


Struttura dati Heap associata ad un insieme S = albero binario radicato con le seguenti proprietà: 

1) Completo fino al penultimo livello (struttura rafforzata: foglie sull'ultimo livello tutte compatte a sinistra) 
2) Gli elementi di S sono memorizzati nei nodi dell'albero (ogni nodo v memorizza uno e un solo elemento, denotato con chiave (v))
3) chiave(padre(v)) $\geq$ chiave(v) per ogni nodo v diverso dalla radice 

L'ordinamento è presente in verticale:
![[Pasted image 20251029155158.png]]

Proprietà salienti degli Heap
1) il <span style="color:rgb(255, 255, 0)">Massimo</span> è contenuto <span style="color:rgb(255, 255, 0)">nella radice</span>
2) L'albero con n nodi ha <span style="color:rgb(255, 255, 0)">altezza O(log n)</span>
3) Gli heap con struttura rafforzata possono essere rappresentati in un <span style="color:rgb(255, 255, 0)">array di dimensione pari a n</span> 

![[Pasted image 20251029161810.png |700 ]]

L'altezza n è sicuramente $\geq$ 1 (ipotetica foglia) + sommatoria $2^i$ (altezza di un albero binario) = 1 (foglia) + $2^h$ -1  (risultato notevole della sommatoria) = $2^h$ 
$\Rightarrow$ h $\leq$ $log_2$ n


Rappresentazione tramite vettore posizionale:
sin(i) = 2i                  
des(i) = 2i +1
padre(i) = $\lfloor \ i/2 \ \rfloor$ 

![[Pasted image 20251029162615.png |500]]

nello pseudocodice il numero degli oggetti viene indicato con Heapsize[A] (a volte memorizzato nella posizione 0)

![[Pasted image 20251029162857.png |700]]

La lunghezza dell'array di appoggio è diversa dall'Heapsize

### La procedura FixHeap 
Sia v la radice di H. 
Assume che i sottoalberi radicati nel figlio sinistro e destro di v sono heap, ma la proprietà di ordinamento delle chiavi non vale per v.
Possiamo ripristinarli così:

**fixHeap** (nodo v, heap H)
	 **if** ( v non è una foglia ) **then**
		 sia *u* il figlio di *v* con chiave massima
		 **if** ( chiave (v) < chiave (u) ) **then**
			 scambia chiave (v) e chiave (u)
			 fixheap( u, H )
			 
Tempo di esecuzione: <span style="color:rgb(255, 255, 0)">O(log n) </span> 

Confronto la radice con il massimo dei figli e li scambio, se radice < figlio
![[Pasted image 20251029164728.png |400]]

PseudoCodice di FixHeap più dettagliato (l'heap è mantenuto attraverso un vettore posizionale)

>[!Example]
>fixHeap (i, A)
>1)  s=sin( i )
>2) d=des( i )
>3) **if** (s $\leq$ heapsize[A] e A[s] > A[i])
>4) **then** massimo = s
>5) **else** massimo = i
>6) **if** (d $\leq$ heapsize[A] e A[d] > A[massimo])
>7) **then** massimo = d
>8) **if** ( massimo $\neq$ i )
>9) **then** scambia A[i] e A[massimo]
>10) ---- fixHeap(massimo, A)
>

### Estrazione del massimo

- Copia nella radice la chiave contenuta nella foglia più a destra dell'ultimo livello
	- <span style="color:rgb(255, 255, 0)">nota</span>: l'elemento in posizione heap size
- Rimuovi la foglia 
	- Decrementando HeapSize
- Ripristina la proprietà di ordinamento a heap richiamando fixHeap sulla radice

Tempo di esecuzione: <span style="color:rgb(255, 255, 0)">O(log n)</span> 

### Costruzione dell'heap

Algoritmo ricorsivo basato sulla tecnica del *divide et impera*

<span style="color:rgb(255, 255, 0)">heapify</span> (heap H)
	**if** (H non vuoto) **then** 
		heapify (sottoalbero sinistro di H)
		heapify (sottoalbero destro di H)
		fixHeap (radice di H, H)

<span style="color:rgb(255, 255, 0)">Complessità</span><span style="color:rgb(255, 255, 0)"> </span><span style="color:rgb(255, 255, 0)">heapify</span>
Sia h l'altezza di un heap con *n* elementi
Sia n' $\geq$ *n* l'intero tale che un heap con n' elementi ha 
	1. altezza h
	2. è completo fino all'ultimo livello 
Vale: T(n) $\leq$ T(n') e n' $\leq$ 2n

Tempo di esecuzione: T(n') = 2 T( (n'-1)/2 ) + O(log n')
						$\leq$  2 T(n'/2) + O(log n')
$\Rightarrow$ T(n') = O(n')         dal Teorema Master
Quindi: T(n) $\leq$ T(n') = O(n') = O(2n) = O(n)


### Max-Heap e Min-Heap

Se costruissimo una struttura dati che estragga il minimo velocemente al posto del massimo? 
	Costruisco un <span style="color:rgb(255, 255, 0)">min-heap</span>  invertendo la proprietà delle chiavi:
				chiave (padre(<span style="color:rgb(255, 0, 0)">v</span>) $\leq$ chiave(<span style="color:rgb(255, 0, 0)">v</span>)) per ogni <span style="color:rgb(255, 0, 0)">v</span> (diverso dalla radice) 

### L'algoritmo HeapSort
- Costruisce un heap tramite heapify (ricorsivamente prendendo ramo dx e sx fino ad arrivare alle foglie, ordina fino ad ottenere un heap ordinato)
- Estrae ripetutamente il massimo per n-1 volte 
	- ad ogni estrazione memorizza il massimo nella posizione dell'array che si è appena liberata 

![[Pasted image 20251102215255.png |600]]


Lo pseudo codice dell'heap sort:
1)  Richiama Heapify(A), cerca di creare un Heap, ha costo O(n) poiché bisogna scorrere tutto l'array.
2) Si fissa l'Heapsize[A] ad n, costo costante.
3) Il ciclo for permette di scorrere l'array e di estrarre ogni volta il massimo, ha costo O(log n), visualizzo tutto l'albero, il caso peggiore è l'intera altezza, O(log n).


<span style="color:rgb(255, 255, 0)">Perché non abbiamo utilizzato un min-heap?</span>
l'utilizzo di un max-heap, implementato con un vettore posizionale, permette di utilizzare solo memoria ausiliare memoria costante.

**Teorema** 
L'algoritmo HeapSort ordina in *loco*  un array di lunghezza *n* in tempo O( n log n) nel caso peggiore.

