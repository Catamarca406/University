#Algoritmi 
### Sommario 

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
**Osservazioni:**
1.	L'albero di decisione <span style="color:rgb(0, 176, 240)">non è associato</span> ad un problema o ad un algoritmo
2.  L'albero di decisione è associato ad un <span style="color:rgb(0, 176, 240)">algoritmo</span> e a una <span style="color:rgb(0, 176, 240)">dimensione dell'istanza</span>
3.  L'albero di decisione descrive le diverse sequenze di confronti che un certo algoritmo può eseguire su istanze di una <span style="color:rgb(0, 176, 240)">data dimensione</span>
4.  L'albero di decisione è una descrizione alternativa dell'algoritmo (customizzato per istanze di una certa dimensione)

**Proprietà:**
1) Per una particolare istanza, i confronti su essa rappresentano un <span style="color:rgb(0, 176, 240)">cammino radice-foglia</span>.
2) L'algoritmo segue un cammino diverso a seconda delle caratteristiche dell'istanza: <span style="color:rgb(0, 176, 240)">Caso peggiore</span> = cammino più lungo.
3) Il numero di confronti nel caso peggiore è pari <span style="color:rgb(0, 176, 240)">all'altezza dell'albero di decisione</span>.
4) Un albero di decisione di un algoritmo (corretto) che risolve il problema dell'ordinamento di <span style="color:rgb(0, 176, 240)">n</span> elementi deve avere necessariamente <span style="color:rgb(0, 176, 240)">almeno n! foglie</span>. 


**Lemma** 
Un albero binario <span style="color:rgb(0, 176, 240)">T</span> con <span style="color:rgb(0, 176, 240)">k</span> foglie, ha altezza almeno $log_2 k$ 

<span style="color:rgb(0, 176, 240)">dim</span> (per induzione su k)
<span style="color:rgb(0, 176, 240)">caso base</span>: k=1            altezza almeno $log_2$ 1 = 0
<span style="color:rgb(0, 176, 240)">caso induttivo</span>: k>1

considera il nodo interno <span style="color:rgb(0, 176, 240)">v</span> più vicino alla radice che ha due figli (<span style="color:rgb(0, 176, 240)">v</span> potrebbe essere la radice), nota che <span style="color:rgb(0, 176, 240)">v</span> deve esistere perché <span style="color:rgb(0, 176, 240)">k</span>>1.

v ha almeno un figlio u che è radice di un (sotto)albero che ha almeno k/2 foglie e < k foglie.

T ha altezza almeno 
1 + $log_2 k/2$ = 1+$log_2 k$ - $log_2 2$ = $log_2 k$

![472x409](../../imm/image-4.png)


#### Il lower bound Ω(n log n) 
- Consideriamo l'albero di decisione di un qualsiasi algoritmo che risolve il problema dell'ordinamento di n elementiù
- L'altezza h dell'albero di decisione è almeno $log_2$ (n!) 
- Formula di Stirling: n! $\approx$ $(2\pi n)^{1/2} \cdot (n/e)^n$  

![652x320](../../imm/image-5.png)


Può un algoritmo basato su n confronti ordinare <span style="color:rgb(255, 0, 0)">n</span> interi piccoli, compresi fra 1 e k= O(<span style="color:rgb(255, 0, 0)">n</span>), in (asintoticamente) meno di <span style="color:rgb(255, 0, 0)">n</span><span style="color:rgb(255, 0, 0)"> </span>log <span style="color:rgb(255, 0, 0)">n</span> ?

.....no la dimostrazione funziona anche sotto questa ipotersi!
La grandezza non cambia il modus operandi dell'albero decisionale


### Integer Sort: fase 1

Per ordinare <span style="color:rgb(0, 176, 240)">n</span> interi con valori in [1,  k] oppure [0 , k]

Mantiene un array <span style="color:rgb(0, 176, 240)">Y</span> di<span style="color:rgb(0, 176, 240)"> </span><span style="color:rgb(0, 176, 240)">k</span> contatori tale che  <span style="color:rgb(0, 176, 240)">Y</span>[x] = numero di volte che il valore <span style="color:rgb(0, 176, 240)">x</span> compare in <span style="color:rgb(0, 176, 240)">X</span>.

![|682x247](../../imm/image-6.png)

Con il vettore X originale conto il numero di elementi in esso incrementando Y[x] di 1 ogni volta che ne trovo uno.

Se X[i] = n  $\Rightarrow$ Y[X[i]] ++

### Integer Sort: fase 2

Scorre <span style="color:rgb(0, 176, 240)">Y</span> da sinistra verso destra e, se <span style="color:rgb(0, 176, 240)">Y</span>[x] = <span style="color:rgb(0, 176, 240)">k</span>, scrive in <span style="color:rgb(0, 176, 240)">X</span> il valore <span style="color:rgb(0, 176, 240)">x</span> per <span style="color:rgb(0, 176, 240)">k</span> volte.

![|686x249](../../imm/image-8.png)

#### PseudoCodice 
>[!example]
>IntegerSort (X,k)
>1. Sia Y un array di dimensione k
>2. **for** i=1 **to** k **do** Y[i] = 0
>3. **for** i =1 **to** n **do** incrementa Y[X[i]]
>4. j=1
>5. **for** i=1 **to** k **do**
>6. ---------- **while**(Y[i] > 0) **do**
>7. -------------- X[j] = i
>8. -------------- incrementa j
>9. -------------- decrementa Y[i]

**Analisi**:
1.  Creo un array in tempo costante, O(<span style="color:rgb(0, 176, 240)">1</span>)
2.  Inizializzo un array con tutti zeri, ha comunque costo linerare: O(<span style="color:rgb(0, 176, 240)">k</span>)
3.  Incremento gli elementi in Y[i] che trovo passo-passo nel vettore <span style="color:rgb(0, 176, 240)">X</span>, O(<span style="color:rgb(0, 176, 240)">n</span>)
4.  Incremento l'indice di <span style="color:rgb(0, 176, 240)">X</span>, O(<span style="color:rgb(0, 176, 240)">1</span>)
5.  Scorro l'array Y, O(<span style="color:rgb(0, 176, 240)">k</span>)
Nelle righe 6. / 7. / 8. / 9. ricerco gli elementi del vettore<span style="color:rgb(0, 176, 240)"> </span><span style="color:rgb(0, 176, 240)">Y </span>e li riassegno in <span style="color:rgb(0, 176, 240)">X</span>.
Per un i fissato il # volte eseguite è al più 1 + Y[i] , $\Rightarrow$ O(<span style="color:rgb(0, 176, 240)">k</span> + <span style="color:rgb(0, 176, 240)">n</span>)


![569x158](../../imm/image-9.png)


### IntegerSort: analisi

- Tempo O(1) + O(<span style="color:rgb(0, 176, 240)">k</span>) = O(<span style="color:rgb(0, 176, 240)">k</span>) per inizializzare <span style="color:rgb(0, 176, 240)">Y</span> a 0.
- Tempo O(1) + O(<span style="color:rgb(0, 176, 240)">n</span>) = O(<span style="color:rgb(0, 176, 240)">n</span>) per calcolare i valori dei contatori.
- Tempo O(<span style="color:rgb(0, 176, 240)">n</span>+<span style="color:rgb(0, 176, 240)">k</span>) per ricostruire <span style="color:rgb(0, 176, 240)">X</span>.

$\Rightarrow$ <span style="color:rgb(0, 176, 240)">O(n+k)</span>
Tempo lineare se k=O(<span style="color:rgb(0, 176, 240)">n</span>) 

Contraddice il lower bound di Ω(<span style="color:rgb(0, 176, 240)">n</span> log <span style="color:rgb(0, 176, 240)">n</span>) ?
No, perché l' IntegerSort non è un algoritmo basato su confroniti!

![641x240](../../imm/image-10.png)



### Bucket Sort

Per ordinare n record (strutture base con cui si scrivono tabelle) con chiavi intere in [1,k]

- <span style="color:rgb(0, 176, 240)">Esempio</span>: ordinare <span style="color:rgb(0, 176, 240)">n</span> record con campi:
	-nome, cognome, anno di nascita, matricola.... 

<span style="color:rgb(0, 176, 240)">Input</span> del problema:
- <span style="color:rgb(0, 176, 240)">n</span> record mantenuti in un array
- ogni elemento dell'array è un record con: 
	-campo chiave (rispetto al quale ordinare) 
	-altri campi associati alla chiave (informazione satellite)

#### Come operare
- Si mantenie un array di liste, anziché di contatori, operando come per IntegerSort
- La lista Y[i] conterrà gli elementi con chiave uguale a <span style="color:rgb(0, 176, 240)">i</span>
- Successivamente si concatenano le liste 
	Tempo O(<span style="color:rgb(0, 176, 240)">n</span>+<span style="color:rgb(0, 176, 240)">k</span>) come per <span style="color:rgb(0, 176, 240)">IntegerSort </span>


![416x389](../../imm/image-13.png)

Si opera come per l' IntegerSort, ad ogni chiave della lista di record corrisponde un'indice della lista Y[]. 
Inserisco fino a terminare tutti i record. 

Caso importante, <span style="color:rgb(0, 176, 240)">molteplicità di una chiave</span>:

![573x314](../../imm/image-16.png)


#### PseudoCodice
>[!example]
>BucketSort (X, k)
>1. --Sia Y un array di dimensione k
>2. --**for** i=1 **to** k **do** Y[i] = lista vuota    --*inizializzo*
>3. --**for** i=1 **to** n **do**
>4. ----appendi il record X[i] alla lista Y[chiave(X[i])]  -- *//preparo Y con pos=chiavi di X*
>5. --**for** i=1 **to** k **do**
>6. ----copia ordinatamente in X gli elementi della lista Y[i]

#### Stabilità 
- Un algoritmo è stabile se preserva l'ordine iniziale tra elementi con la stessa chiave
- Il <span style="color:rgb(0, 176, 240)">BucketSort</span> è stabile se si appendendo gli elementi di <span style="color:rgb(0, 176, 240)">X</span> <span style="color:rgb(255, 0, 0)">in coda</span> alla opportuna lista Y[i]

### RadixSort 

- Ordina n interi con valori in [1,k]
- Rappresentiamo gli elementi in base b, ed eseguiamo una serie di BucketSort
- Partiamo dalla cifra meno significativa verso quella più significativa:
	 -Ordiniamo per l'i-sima cifra con una passata di BucketSort 
	 -L' i-sima cifra è la chiave, il numero informazione satellite
	 -L' i-sima cifra è un intero in [0,b-1]


![image-17](../../imm/image-17.png)


#### Correttezza

- Se <span style="color:rgb(0, 176, 240)">x</span> e <span style="color:rgb(0, 176, 240)">y</span> hanno una diversa <span style="color:rgb(0, 176, 240)">t</span>-esima cifra, la<span style="color:rgb(0, 176, 240)"> </span><span style="color:rgb(0, 176, 240)">t</span>-esima passata di <span style="color:rgb(0, 176, 240)">BucketSort</span> li ordina
- Se <span style="color:rgb(0, 176, 240)">x</span> e <span style="color:rgb(0, 176, 240)">y</span> hanno la stessa t-esima cifra, la proprietà di stabilità del <span style="color:rgb(0, 176, 240)">BucketSort</span> li mantiene ordinati correttamente
Dopo la <span style="color:rgb(0, 176, 240)">t</span>-esima passata di <span style="color:rgb(0, 176, 240)">BucketSort</span>, i numeri sono correttamente ordinati rispetto alle t cifre meno significative

Esempio:    <span style="color:rgb(255, 255, 0)">2</span>397
		   <span style="color:rgb(255, 255, 0)">4</span>368
		   <span style="color:rgb(255, 255, 0)">5</span>924 
	le cifre meno significative sono ordinate


#### Tempo di correttezza

- O($log_b$ k) passate di BucketSort
  -# di cifre per rappresentare il valore massimo k in base b: O($log_b$ k)
- Ciascuna passata richiede tempo O(n + b)
	-in ogni passata la chiave è un intero in [0, b-1]

	O( (n+b) ($log_b$ k) )

Se b = Θ(n), si ha O(n $log_n$ k) = * O ( <span style="color:rgb(0, 176, 240)">n</span> ( log <span style="color:rgb(0, 176, 240)">k</span>/log <span style="color:rgb(0, 176, 240)">n</span>) )

* $log_2$ <span style="color:rgb(0, 176, 240)">k</span> = $log_n$ <span style="color:rgb(0, 176, 240)">k</span> $\cdot$ $log_2$ <span style="color:rgb(0, 176, 240)">n</span>

$\Rightarrow$ Tempo lineare se <span style="color:rgb(0, 176, 240)">k</span> = O($n^c$), <span style="color:rgb(0, 176, 240)">c</span> costante

<span style="color:rgb(255, 0, 0)">Esempio:</span>

- Si supponga di voler ordinare $10^6$ numeri da 32 bit
- Come scelgo la base b ?
- $10^6$ è compreso fra $2^{19}$ e $2^{20}$ 
- Scegliendo b = $2^{16}$ si ha:
	-sono sufficienti 2 passate di BucketSort
    -ogni passata richiede tempo lineare 
