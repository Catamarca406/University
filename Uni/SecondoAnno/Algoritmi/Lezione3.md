#Algoritmi 

![ 580](Pasted%20image%2020251020164904.png%20) 

# Ricerca di elementi in una lista
## Ricerca di un elemento in un array / lista non ordinata

L'algoritmo torna la posizione di <span style="color:rgb(0, 176, 240)">X</span> in <span style="color:rgb(0, 176, 240)">L</span> se <span style="color:rgb(0, 176, 240)">x</span> è presente, -1 altrimenti

>[!example]
>**algoritmo** RicercaSequenziale (array L, elem x) --> intero 
>n=lunghezza di L
>	i=1
>		**for** i=1 to n **do**
>		**if** (L[i]=x) **then return** i // ho trovato l'elemento
>		**return** -1 //non trovato


T(<span style="color:rgb(0, 176, 240)">n</span>): # elementi acceduti (linea 4) su un array di dimensione <span style="color:rgb(0, 176, 240)">n</span>

$T_{worst}$(<span style="color:rgb(0, 176, 240)">n</span>) = <span style="color:rgb(0, 176, 240)">n</span>                   x $\notin$ L oppure è in ultima posizione

$T_{avg}$ (<span style="color:rgb(0, 176, 240)">n</span>) = (<span style="color:rgb(0, 176, 240)">n</span>+1) / 2        assumendo che x $\in$ L e che si trovi con la stessa                                             probabilità in una qualsiasi posizione 


T(<span style="color:rgb(0, 176, 240)">n</span>): # operazioni RAM su un array di dimensione <span style="color:rgb(0, 176, 240)">n</span>

$T_{worst}$ (<span style="color:rgb(0, 176, 240)">n</span>) = Θ(<span style="color:rgb(0, 176, 240)">n</span>)         x $\notin$ L oppure è in ultima posizione

$T_{avg}$ (<span style="color:rgb(0, 176, 240)">n</span>) = Θ(<span style="color:rgb(0, 176, 240)">n</span>)           assumendo che x $\in$ L e che si trovi con la stessa                                              probabilità in una qualsiasi posizione


## Ricerca di un elemento in un array ordinato

Algoritmo di <span style="color:rgb(0, 176, 240)">ricerca binaria</span>: uno strumento molto potente

gli indici <span style="color:rgb(0, 176, 240)">i</span> e <span style="color:rgb(0, 176, 240)">j</span> indicano la porzione di <span style="color:rgb(0, 176, 240)">L</span> in cui cercare l'elemento <span style="color:rgb(0, 176, 240)">x</span>
	l'algoritmo torna la posizione di <span style="color:rgb(0, 176, 240)">x</span> in <span style="color:rgb(0, 176, 240)">L</span>, se <span style="color:rgb(0, 176, 240)">x</span> c'è, -1 altrimenti

>[!example]
>***algoritmo***  RicercaBinariaRic (array L, elem x, int i, int j) --> intero
>	if (i>j) **then return** -1
>	m = $\lfloor \ {(i+j)} \ \rfloor$ 
>	**if** (L[m]=x) **then return** m
>	**if** (L[m]>x)  **then return** RicercaBinariaRic (L, x, i, m-1)
>	**else return** RicercaBinariaRic (L, x, m+1, j)


T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>/2) + O(<span style="color:rgb(0, 176, 240)">1</span>) $\Rightarrow$ T(n) = O(log <span style="color:rgb(0, 176, 240)">n</span>)


# Ricorsione, tecniche di progettazione e equazioni di ricorrenza

## Sommario
- <span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)">Algoritmi ricorsivi</span></span>: come analizzarli?
- <span style="color:rgb(0, 176, 240)">Complessità</span> di algoritmi ricorsivi e <span style="color:rgb(0, 176, 240)">equazioni di ricorrenza</span> 
- Una tecnica di progettazione algoritmica: <span style="color:rgb(0, 176, 240)">divide</span> <span style="color:rgb(0, 176, 240)">et</span> <span style="color:rgb(0, 176, 240)">impera</span> 
- Metodi per risolvere equazioni di ricorrenza: 
		- <span style="color:rgb(0, 176, 240)">Iterazione</span>
		- <span style="color:rgb(0, 176, 240)">Albero</span> <span style="color:rgb(0, 176, 240)">della</span> <span style="color:rgb(0, 176, 240)">ricorsione</span>
		- <span style="color:rgb(0, 176, 240)">Sostituzione</span>
		- <span style="color:rgb(0, 176, 240)">Teorema</span> <span style="color:rgb(0, 176, 240)">Master</span>
		- <span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)">Cambiamento</span></span> <span style="color:rgb(0, 176, 240)">di</span> <span style="color:rgb(0, 176, 240)">variabile</span> 

### Algoritmi ricorsivi: come analizzarli?

>[!example] 
>***algoritmo*** fibonacci2 (intero n) --> intero
>**if** (n$\leqslant$ 2 ) **then return** 1
>**else return** fibonacci2 (n-1) + fibonacci2 (n-2)

T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>-1) + T(<span style="color:rgb(0, 176, 240)">n</span>-2) + O(1)


>[!example]
>***algoritmo*** RicercaBinariaRic (array L, elem x, int i, int j)
>**if**(i>j) **then return** -1
>m=$\lfloor \ (i+j)/2 \ \rfloor$  
>**if** (L[m]=x) **then return** m
>**if** (L[m]>x) **then return** RicercaBinariaRic (L, x, i, m-1)
>**else return** RicercaBinariaRic (L, x, m+1, j)

T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>/2) + O(1) 

>[!example]
> Alg4 (X) 
> **if**  (|X| = 1) **then return** unica moneta in X
> dividi X in tre gruppi $X_1, X_2, X_3$ di dimensione bilanciata siano $X_1 e X_2$ i gruppi che hanno la stessa dimensione (ci sono sempre)
> **if** peso ($X_1$) = peso ($X_2$) **then return** Alg4($X_3$)
> **if** peso ($X_1$) > peso ($X_2$) **then return** Alg4($X_1$)
> **else return** Alg4($X_2$)

T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>/3) + O(1)


### Equazioni di ricorrenza

La <span style="color:rgb(0, 176, 240)">complessità</span> <span style="color:rgb(0, 176, 240)">computazionale</span> di un algoritmo ricorsivo può essere espressa in modo naturale attraverso una <span style="color:rgb(0, 176, 240)">equazione</span> <span style="color:rgb(0, 176, 240)">di</span> <span style="color:rgb(0, 176, 240)">ricorrenza</span>

esempi:

	 T(n) = T(n/3) + 2T(n/2) + O(n log n) 
	 	 
	 T(n) = T(n-1) + O(1)
	 
	T(n) = T(n/3) + T(2n/3) + n

Casi base: T(<span style="color:rgb(0, 176, 240)">costante</span>) = cost(a volte T(<span style="color:rgb(0, 176, 240)">1</span>) =1)
#### Metodo dell'iterazione

<span style="color:rgb(255, 0, 0)">Idea</span>: "srotolare" la ricorsione, ottenendo una sommatoria dipendente solo dalla dimensione <span style="color:rgb(0, 176, 240)">n</span> del problema iniziale

1) Esempio: T(<span style="color:rgb(0, 176, 240)">n</span>) = c + T(<span style="color:rgb(0, 176, 240)">n</span>/2)
		 T(<span style="color:rgb(0, 176, 240)">n</span>/2) = c + T(<span style="color:rgb(0, 176, 240)">n</span>/4) ..

	$\Rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = c + T(<span style="color:rgb(0, 176, 240)">n</span>/2)
		   = 2c + T(<span style="color:rgb(0, 176, 240)">n</span>/4)
		   = 2c + c + T(<span style="color:rgb(0, 176, 240)">n</span>/8)
		   = 3c + T(<span style="color:rgb(0, 176, 240)">n</span>/8)
		   ....
		   = i$\cdot$c + T(<span style="color:rgb(0, 176, 240)">n</span>/$2^i$)	
Per i = $log_2 \ {n}$: T(<span style="color:rgb(0, 176, 240)">n</span>) = c $\cdot \ log_2 \ {n}$ + T(<span style="color:rgb(0, 176, 240)">1</span>) = Θ(log <span style="color:rgb(0, 176, 240)">n</span>)
<span style="color:rgb(0, 176, 240)"><br></span>
2) Esempio: T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>-1) + 1 
	T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>-1) + 1 
		= T(<span style="color:rgb(0, 176, 240)">n</span>-2) + 1 + 1
		= T(<span style="color:rgb(0, 176, 240)">n</span>-3) + 1 + 1 + 1
		= T(<span style="color:rgb(0, 176, 240)">n</span>-4) + 1 + 1 +1 +1 
		....
		= T(<span style="color:rgb(0, 176, 240)">n</span>-i) + i
Per i = <span style="color:rgb(0, 176, 240)">n</span>-1 : T(<span style="color:rgb(0, 176, 240)">n</span>) = T(1) + <span style="color:rgb(0, 176, 240)">n</span>-1 = Θ(<span style="color:rgb(0, 176, 240)">n</span>)


3) Esempio: T(<span style="color:rgb(0, 176, 240)">n</span>) = 2T(<span style="color:rgb(0, 176, 240)">n</span>-1) +1
	T(<span style="color:rgb(0, 176, 240)">n</span>) = 2T(<span style="color:rgb(0, 176, 240)">n</span>-1) + 1
		= 2(2T(<span style="color:rgb(0, 176, 240)">n</span>-2)+1) +1
		= 4T(<span style="color:rgb(0, 176, 240)">n</span>-2) +2 +1
		= 4(2T(<span style="color:rgb(0, 176, 240)">n</span>-3) +1)+2 +1
		= 8T(<span style="color:rgb(0, 176, 240)">n</span>-3) +4 +2 +1
		= 16T(<span style="color:rgb(0, 176, 240)">n</span>-4) +8+4+2+1
		....
		= $2^i$ T(n-1) + $\sum_{j=0}^{i-1} \ 2 \cdot j$
	per i = <span style="color:rgb(0, 176, 240)">n</span>-1
		T(<span style="color:rgb(0, 176, 240)">n</span>) = $2^{n-1}$ T(1) + $\sum_{j=0}^{n-2} \ 2\cdot j$  = Θ($2^n$)


4) Esempio: T(n) = T(n-1) + T(n-2) +1
	T(n) = T(n-1) + T(n-2) +1
		= T(n-2) + T(n-3) +1 + T(n-3) + T(n-4) +1 +1 
		= T(n-2) + 2T(n-3) + T(n-4) +3
		= T(n-3) + T(n-4) +1 +2(T(n-4) + T(n-5) +1) + T(n-5) + T(n-6)+1+3
		= T(n-3) + 3T(n-4) +3T(n-5) +T(n-6) + 7
		.....


Esercizi: 
	Esercizio 1: T(n) = T(n-1) + n, T(1) = 1
	Esercizio 2: T(n) = 9T(n/3) +n, T(1) = 1


#### Analisi dell'albero della ricorsione
<span style="color:rgb(255, 0, 0)">(Un modo grafico di pensare il metodo dell'iterazione)</span> 

<span style="color:rgb(0, 176, 240)">Idea: </span>
	- Disegnare l'albero delle chiamate ricorsive indicando la dimensione di ogni nodo
	- Stimare il tempo speso da ogni nodo dell'albero
	- Stimare il tempo complessivo "sommando" il tempo speso da ogni nodo
<span style="color:rgb(255, 0, 0)">Svolgimento</span> <span style="color:rgb(255, 0, 0)">1:</span> se il tempo speso da ogni nodo è costante, T(n) è proporzionale al numero di nodi
<span style="color:rgb(255, 0, 0)">Svolgimento 2:</span> a volte conviene analizzare l'albero per livelli:
 - analizzare il tempo speso su ogni livello (fornendo upper bound)
 - stimare il numero di livelli

##### Tecnica albero della ricorsione

![Pasted image 20251022152506](../../imm/Pasted%20image%2020251022152506.png)

<span style="color:rgb(0, 176, 240)">Quanto mi costa un nodo?</span> ---> uno
<span style="color:rgb(0, 176, 240)">Quanti nodi ha un albero?</span>  ---> <span style="color:rgb(0, 176, 240)">n</span>

$\Rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = $\Theta$(<span style="color:rgb(0, 176, 240)">n</span>) 

Stesso esempio ma con il costo di ogni singolo nodo pari a n:
![Pasted image 20251022152802](../../imm/Pasted%20image%2020251022152802.png)

<span style="color:rgb(0, 176, 240)">Quanto mi costa un nodo?</span> ---> al più n
<span style="color:rgb(0, 176, 240)">Quanti nodi ha un albero?</span>  ---> <span style="color:rgb(0, 176, 240)">n</span>

Allora il prodotto tra l'altezza dell'albero e il loro singolo peso vale:
	T(n) = O($n^2$)
	Impostando un Upper Bound, so che il massimo a cui posso arrivare è $n^2$
 	sapendo questo vale T(n) =  $\Theta$($n^2$) ? 
	

Verifichiamo: 
	T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>-1) + <span style="color:rgb(0, 176, 240)">n</span>
	T(<span style="color:rgb(0, 176, 240)">1</span>) = 1
		n
		$\downarrow$
	    <span style="color:rgb(0, 176, 240)">n</span>-1
		$\downarrow$
		n-2
		$\downarrow$
		...
		$\downarrow$
		n-i                                               - Fino a qui il numero di nodi è n/2,                                                        il loro singolo costo è $\geq$ n/2 
		$\downarrow$
		2
		$\downarrow$
		1

 Non è immediato, cerchiamo di fare un Lower Bound: 
	 Prendendo la metà superiore della formula sappiamo che il numero di nodi è pari a n/2 ed ogni nodo costa sicuramente più di n/2,quindi il costo è pari a: 
		 T(n) $\geq$ n/2 $\cdot$ n/2 = $n^2/4$
		 $\Rightarrow$ T(n) = $\Omega$ ($n^2$)

Allora sicuramente possiamo dire che T(n) è sia un O($n^2$) che un $\Omega (n^2)$ allora T(n) = $\Theta (n^2)$ 


T(<span style="color:rgb(0, 176, 240)">n</span>) = 2T(<span style="color:rgb(0, 176, 240)">n</span>-1) + 1
T(<span style="color:rgb(0, 176, 240)">1</span>) = 1 

![Pasted image 20251021182931](../../imm/Pasted%20image%2020251021182931.png)



T(<span style="color:rgb(0, 176, 240)">n</span>) = 2T(<span style="color:rgb(0, 176, 240)">n</span>-1) + <span style="color:rgb(0, 176, 240)">n</span> 
T(<span style="color:rgb(0, 176, 240)">1</span>) = 1 

![Pasted image 20251022113826](../../imm/Pasted%20image%2020251022113826.png)


##### Analisi dell'albero della ricorsione 

<span style="color:rgb(0, 176, 240)">due esempi</span>: 
	 Esempio 1:   T(<span style="color:rgb(0, 176, 240)">n</span>) = T(<span style="color:rgb(0, 176, 240)">n</span>/3) + T(2<span style="color:rgb(0, 176, 240)">n</span>/3) + <span style="color:rgb(0, 176, 240)">n</span>
				T(<span style="color:rgb(0, 176, 240)">1</span>) = 1
	 Esempio 2:   T(<span style="color:rgb(0, 176, 240)">n</span>) = 2T(<span style="color:rgb(0, 176, 240)">n</span>-2) + 1  
				 T(<span style="color:rgb(0, 176, 240)">1</span>) = 1


![600](Pasted%20image%2020251022145623.png%20)

In questo caso vogliamo dire che l' equazione T(n) = T(n/3) + T(2/3n) +n sia un $\Theta$(n), però per far ciò dobbiamo prima verificare che sia un O e un $\Omega$.
$\Rightarrow$ Applico un Upper Bound.
	Sapendo che T(n) non possa mai andare oltre O( $log_{3/2} \ (n)$ ) calcoliamo O quindi ho $log_{3/2} \ (n)$ nodi con costo n allora: T(n) = O(n log n) 

![ 600](Pasted%20image%2020251022150806.png%20)

$\Rightarrow$ Caso opposto, ora dobbiamo controllare che la nostra equazione sia un $\Omega$: 
	Poniamo T(<span style="color:rgb(0, 176, 240)">n</span>) $\geq$ $log_3 (n)$, come prima, so che ho $log_3 (n)$ nodi con costo singolo pari a n.
	Allora T(<span style="color:rgb(0, 176, 240)">n</span>) = $\Omega$(<span style="color:rgb(0, 176, 240)">n</span> log <span style="color:rgb(0, 176, 240)">n</span>) 
	Perché l'altezza dei rami sinistri è pari a $\log_3(n)$? 
		Perché ad ogni passo successivo dividiamo di 1/3 rispetto al precedente, con un ritmo logaritmico, quindi possiamo definire la base del logaritmo come ciò che divide la nostra <span style="color:rgb(0, 176, 240)">n</span> 

$\Rightarrow$ Possiamo concludere T(n) = $\Theta$(<span style="color:rgb(0, 176, 240)">n</span> log <span style="color:rgb(0, 176, 240)">n</span>) poiché sappiamo che l'equazione iniziale è sia un O che un $\Omega$.



### Metodo della sostituzione 

Idea: 
1) Indovinare la forma della soluzione
2) Usare induzione matematica per provare la soluzione
3) Risolvere rispetto alle costanti

![600](Pasted%20image%2020251022180434.png%20)

Esercizi 
		risolvere utilizzando il metodo della sostituzione:
		T(n) = 4T(n/2) +n, T(1) = 1
![600](Pasted%20image%2020251024162855.png%20)
![600](Pasted%20image%2020251024162944.png%20)

### Tecnica del divide et impera 
Ci sono algoritmi basati sulla tecnica del divide et impera:
 - Dividiamo il problema (di dimensione <span style="color:rgb(0, 176, 240)">n</span>) in <span style="color:rgb(0, 176, 240)">a</span> sottoproblemi di dimensione <span style="color:rgb(0, 176, 240)">n</span>/<span style="color:rgb(0, 176, 240)">b</span>
 - Risolviamo i sottoproblemi ricorsivamente
 - Ricombiniamo le soluzioni
 SIa <span style="color:rgb(0, 176, 240)">f</span><span style="color:rgb(0, 176, 240)">(n)</span> il tempo per dividere e ricombinare istanze di dimensione <span style="color:rgb(0, 176, 240)">n</span>.
 La relazione di ricorrenza è data da:
	$$ 
	T(n) = 
	\begin{cases}
	a T(n/b) \ + \ f(n) &\text{se n $ \ $ $\geq$ $ \ $ 1 }\\[12pt]	
	\Theta(1)  \quad &\text{se n $ \ $ $\leq$ $ \ $ 1}
	\end{cases}
	$$

Possiamo verificare tale tecnica tramite algoritmi visti in precedenza:

![ 600](Pasted%20image%2020251023233713.png%20)





![ 600](Pasted%20image%2020251023233734.png%20)


#### Teorema Master: enunciato informale

Possiamo generalizzare ciò detto in precedenza tramite il Teo. Master, abbiamo: 
			![ 300](Pasted%20image%2020251023234131.png%20)
Dobbiamo chiederci, quale va più velocemente a infinito?
	Stesso ordine asintotico $\rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = $\Theta$(<span style="color:rgb(0, 176, 240)">f(n) log n</span>) 
	Se una delle due è "polinomialmente" più veloce 
		$\rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) ha l'ordine asintotico della più veloce 

#### Teorema Master: regole

La relazione di ricorrenza:

$$
T(n) = 
	\begin{cases}
	a T(n/b) \ + \ f(n) &\text{se n $ \ $ $\geq$ $ \ $ 1 }\\[12pt]	
	\Theta(1)  \quad &\text{se n $ \ $ $\leq$ $ \ $ 1}
	\end{cases}
$$

ha soluzione: 
1) T(n) = Θ($n^{log_b (a)}$)  se f(n) = O( $n^{log_b(a - \xi)}$ ) per $\xi \geq 0$ 
2) T(n) = Θ($n^{log_b (a)} \cdot log (n)$)  se f(n) = Θ($log_b(a)$)
3) T(n) = Θ(f(n)) se f(n) = Ω( $n ^{log_b(a)+\xi}$ ) per $\xi$ $\geq$ 0 e a$\cdot$ f(n/b) $\leq$ c$\cdot$ f(n) per c<1 e n sufficientemente grande


Esempi delle tre soluzioni applicate a determinate equazioni di ricorrenza:

![480](Pasted%20image%2020251023235719.png%20)
![480](Pasted%20image%2020251023235855.png%20)
