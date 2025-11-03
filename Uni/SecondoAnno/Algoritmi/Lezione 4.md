#Algoritmi 

Argomenti di questa lezione:

- Algoritmi di ordinamento
	- SelectionSort
	- InsertionSort
	- BubbleSort
	- MergeSort
	- QuickSort

## Questione di ordinamento

"*Dato un insieme S di n oggetti presi da un dominio totalmente ordinato, ordinare S*" 

Esempi: 
	Ordinare una lista di nomi alfabeticamente, o un insieme di numeri, o un insieme di compiti d'esame.
Spoiler: E' possibile ordinare degli elementi in un'array in tempo O(log n)


#### Il problema dell'ordinamento

Input: un sequenza di n numeri < $a_1, a_2,..., a_n$ >
Output: una permutazione < $a_1 ', a_2 ',..., a_n '$ > della sequenza di input tale che $a_1' \leq a_2' \leq,...,\leq a_n'$ 


### Algoritmi di tempo quadratico

#### Selection Sort
Questo algoritmo sfrutta un approccio incrementale, confronta un elemento in una certa posizione k con tutti gli altri n-2 volte (k=0 , n-2 evita che ci sia il confronto con se stesso, arrivati a quel punto il vettore sarà già ordinato!)	

<span style="color:rgb(255, 0, 0)">Def</span>:
Estende l'ordinamento da k a k+1 elementi, scegliendo il minimo degli n-k elementi non ancora ordinati e mettendolo in posizione k+1 		
<span style="color:rgb(255, 255, 0)">![400](Pasted%20image%2020251026232211.png%20)</span>

##### PseudoCodice: 
> [!Example]  
> SelectionSort (A) 
> 1) **for** k=0 **to** n-2 **do**
> 2) --- m = k+1
> 3) --- **for** j= k+1 **to** n **do**
> 4) ----- **if**(A[j] < A[m] ) **then** m=j
> 5) --- scambia A[m] con A[k+1]
>  

 - Al generico passo k, A[1], ... , A[k] sono già ordinati 
 - Linee 2-4: ricerca del minimo fra gli elementi A[k+1], ... , A[n]
 - m è l'indice dell'array in cui si trova il minimo
 - Il minimo è messo in posizione k+1

<span style="color:rgb(255, 255, 0)">Corretto</span><span style="color:rgb(255, 255, 0)">?</span> 
L'algoritmo mantiene le seguenti invarianti: dopo il generico passo k (k=0, ..., n-2) abbiamo che:
	<span style="color:rgb(255, 255, 0)">i)</span> i primi k+1 elementi sono ordinati 
	<span style="color:rgb(255, 255, 0)">ii)</span> sono i k+1 elementi più piccoli dell'array

<span style="color:rgb(255, 255, 0)">Suggerimento</span>: ragionare per invarianti è uno strumento utile per dimostrare la correttezza di un algoritmo, perché permette di isolare proprietà dell'algoritmo, spiegarne il funzionamento, capire a fondo l'idea su cui si basa.

Complessità temporale (analisi): 
	T(n) = # operazioni elementari sul <span style="color:rgb(255, 255, 0)">modello RAM</span> a costi uniformi eseguite dall'algoritmo nel <span style="color:rgb(255, 255, 0)">caso peggiore</span> su istanze di <span style="color:rgb(255, 255, 0)">dimensione n</span>. 

Per ogni istruzione eseguita del ciclo esterno corrisponde un'istruzione del ciclo più interno, mentre ogni riga di codice vale O(1). 

Vale allora la seguente relazione prendendo un Upper Bound: 
	T(n) $\leq$ $5n^2$ O(1) = $\Theta(n^2)$  $\Rightarrow$ T(n) = O($n^2$) 

Calcolo la complessità in Lower Bound:
	T(n) $\geq$ $\sum_{k=0}^{n-2} (n-k-1) = \sum_{k=0}^{n-2}(k)$ =  n(n-1) / 2 = $\Theta(n^2)$                                 
	Calcolo n (len del vettore) - k(passo in cui mi trovo) - 1 (ultimo elemento che sarà già ordinato) per contare quanti confronti devo ancora fare         
	$\Rightarrow$ T(n) = $\Omega(n^2)$ $\Rightarrow$ T(n) = $\Theta(n^2)$, perché abbiamo verificato che T(n) è sia un omega che un O di $n^2$  



#### Insertion Sort
Anche qui viene utilizzato un <span style="color:rgb(255, 255, 0)">approccio incrementale</span>: estende l'ordinamento da k a k+1 elementi, posizionando l'elemento (k+1) - esimo nella posizione corretta rispetto ai primi k elementi. 

![](../../imm/Pasted%20image%2020251027155629.png%20)

##### PseudoCodice
>[!Example]
> Insertion Sort
>1) for  
>2)
>3)


#### Bubble Sort
Segue un approccio incrementale: esegue n-1 scansioni. Ad ogni scansione guarda coppie di elementi adiacenti e li scambia se non sono nell'ordine corretto.

![400](../../imm/Pasted%20image%2020251027160739.png%20)

##### PseudoCodice
>[!Example] 


### Ordinare in tempo meno che quadratico
#### Merge Sort
Questo algoritmo utilizza la tecnica del Divide et Impera

1) <span style="color:rgb(255, 255, 0)">Divide</span>: dividi l'array a metà
2) Risolvere i due sottoproblemi ricorsivamente
3) <span style="color:rgb(255, 255, 0)">Impera</span>: fondi le due sottosequenze ordinate

##### PseudoCodice 
>[!Example]
>MergeSort (A,i,f)
>1) **if**( i < f ) **then**
>2)   --- m = $\lfloor \ ( i +f )/2 \ \rfloor$  
>3)   --- MergeSort ( A, i, m )
>4)   --- MergeSort ( A, m+1, f )
>5)   --- Merge ( A, i, m, f )

<span style="color:rgb(255, 255, 0)">Idea</span>: 
Divido il vettore a metà, da i (inizio) fino a m (divisione perfetta a metà) , e da m+1 (elemento successivo alla metà) fino a f (fine vettore).

<span style="color:rgb(255, 0, 0)">Esempio</span> <span style="color:rgb(255, 0, 0)">di</span>  <span style="color:rgb(255, 0, 0)">esecuzione</span><span style="color:rgb(255, 0, 0)">:</span> 

![480](../../imm/Pasted%20image%2020251028144319.png%20)


##### Procedura Merge

Due array ordinati A e B possono essere fusi rapidamente:
- Estrai ripetutamente il minimo di A e B e copialo nell'array di output, finché A oppure B non diventa vuoto
- Copia gli elementi dell'array non vuoto alla fine dell'array di output

##### PseudoCodice Merge
>[!Example]
>Merge (A, i, $f_1$, $f_2$)
>1) Sia X un array ausiliario di lunghezza $f_2 -i_1 +1$
>2) i = 1 , $k_1  = i_1$ <span style="color:rgb(0, 176, 240)">// inizio prima metà</span>
>3) $k_2 = f_1 +1$  <span style="color:rgb(0, 176, 240)">// inizio seconda metà</span> 
>4) **while** ($k_1 \leq f_1$ e $k_2 \leq f_2$) **do**
>5) --- **if**(A[$k_1$] $\leq$ A[$k_2$])
>6) --- **then** X[i] = A[$k_1$]
>7)   --- incrementa i e $k_1$
>8) --- **else** X[i] = A[$k_2$]
>9)   --- incrementa i e $k_2$
>10) **if**($k_1 \leq f_1$) **then** copia A[$k_1;f_1$] alla fine di X
>11) **else** copia A[$k_2;f_2$] alla fine di X
>12) copia X in A[$i_1;f_2$]

Osservazione: stiamo utilizzando un array ausiliario

<span style="color:rgb(255, 255, 0)">Corretto?</span>
	Si 
	- Chiamate ricorsive ordinano le due metà 
	- Il Merge le fonde correttamente 

<span style="color:rgb(255, 255, 0)">Complessità?</span>

Tempo di esecuzione
- La complessità temporale del MergeSort è descritto dalla seguente relazione di ricorrenza: 
			<span style="color:rgb(255, 255, 0)">T(n) = 2 T(n/2) + O(n)</span> 

- Usando il teorema Master si ottiene:
		T(n) = O( n log n )
${n^{log_2(2)}}$ vs O(n)
= n vs n 

##### Quanta memoria (ausiliaria) usiamo ?
- La complessità spaziale del MergeSort è $\Theta$(n) 
	- La procedura Merge usa memoria ausiliaria pari alla dimensione di porzione da fondere
	- Non sono mai attive due procedure di Merge contemporaneamente
	- Ogni chiamata di MergeSort usa memoria costante (esclusa quella usata dalla procedura Merge)
	- Numero di chiamate di MergeSort attive contemporaneamente sono O(log n)
	Il <span style="color:rgb(255, 255, 0)">mergeSort</span> non ordina <span style="color:rgb(255, 255, 0)">in</span> <span style="color:rgb(255, 255, 0)">loco</span>
		-Occupazione di memoria ausiliaria (oltre input) pari a $\Theta$ (n) 


#### Quick Sort

Anche il Quick Sort utilizza la tecnica del <span style="color:rgb(255, 255, 0)">Divide et Impera</span> 

1) <span style="color:rgb(255, 255, 0)">Divide</span>: sceglie un elemento x della sequenza (perno) e partiziona la sequenza in elementi $\leq$ x ed elementi > x
2) Risolvi i due sottoproblemi ricorsivamente 
3) <span style="color:rgb(255, 255, 0)">Impera</span>: restituisci la concatenazione delle due sottosequenze ordinate

Rispetto al MergeSort divide è complesso mentre impera è semplice


Partizione (in loco) 
- Scelgo il perno 
- Scorro l'array in parallelo, da sinistra --> destra e da destra -->sinistra
	- Da sinistra verso destra, ci si ferma su un elemento maggiore del perno
	- Da destra verso sinistra, ci si ferma su un elemento minore del perno
- Scambia gli elementi e riprendi la scansione
- Fermati quando i due indici si sono incrociati


##### PseudoCodice Partition
>[!Example]
> Partition (A, i, f)
> 1) x = A[i]
> 2) inf = i
> 3) sup = f +1 
> 4) **while** (true) **do** 
> 5) --- **do** (inf = inf + 1) **while** (inf $\leq$ f e A[inf] $\leq$ x) 
> 6) --- **do** (sup = sup - 1) **while** (A[sup] > x)
> 7) --- **if** (inf < sup) **then** scambia A[inf] e A[sup]
> 8) --- **else break**
> 9) scambia A[i] e A[sup]
> 10) **return** sup

X è il perno, inf e sup sono gli estremi del vettore , nei due "do" incremento inf se inf non è ancora arrivato alla fine del vettore ( f ) e A[inf] è $\leq$ del perno, parallelamente anche sup farà lo stesso: decrementa se A[sup] > perno.
Mi fermo su inf e sup quando: inf è > perno e sup < perno.
Se inf < sup scambio i valori, solo quando i due "do" di prima si saranno fermati, quindi nel caso in cui abbiamo trovato un elemento a sinistra > perno e un elemento a destra < perno, a tal punto sapremo che bisognerà scambiare i valori.
Quando inf $\geq$ sup scambio il perno con l'elemento in "posizione sup".


##### PseudoCodice QuickSort
>[!Example]
>QuickSort ( A, i, f )                             //Ordina A[i;f]
>1) **if** ( i < f ) **then**
>2) --- m = Partition ( A, i,  f )
>3) --- QuickSort (A, i , m-1) 
>4) --- QuickSort (A, m+1, f)
 
Esempio di Esecuzione
![480](../../imm/Pasted%20image%2020251028234853.png%20)

Correttezza: 
L'algoritmo dopo aver chiamato Partition è corretto perché: A[ i: m-1 ] contiene elem $\leq$ del perno, A[m] il perno, A[ m+1, f ] elem > del perno.
Le chiamate ricorsive ordinano A[ i:f ]

##### Complessità?

- <span style="color:rgb(255, 255, 0)">Analisi del caso peggiore</span>

Ogni invocazione di Partition posiziona almeno un elemento in modo corretto (il perno), dopo *n* invocazioni di Partition, ognuna di costo O(n) ho il vettore ordinato.
Il costo complessivo è di O($n^2$) 

Il caso peggiore si verifica quando il perno scelto ad ogni passo è il minimo o il massimo degli elementi nell'array.
La complessità in questo caso è: 
	T(n) = T(n-1) + T(0) + O(n)
		= T(n-1) +O(1)  + O(n)
		= T(n-1) + O(n)
		= T(n ) = O($n^2$) 

- <span style="color:rgb(255, 255, 0)">Complessità nel caso migliore</span> 
 O(n log n), partizionamento sempre bilanciato: 
	 Ogni livello costa n, per arrivare fino alle foglie dell'albero impiego tempo logaritmico.
	 
![600](../../imm/Pasted%20image%2020251029135540.png%20)


Intuizioni sul caso medie ... (istanze equiprobabili)

- Problema: la partizione può essere sbilanciata 
- la probabilità che ad ogni passo si presenti la partizione è molto bene
- Per partizioni che non sono "troppo sbilanciate" l'algoritmo è veloce
- Domanda: qual'è la complessità dell'algoritmo supponendo che l'algoritmo di partizionamento produca sempre una partizione proporzionale 9 a 1?
- E se la partizione fosse sempre proporzionale 99 a 1?
- Nota: sembrano partizioni piuttosto sbilanciate...

![image](../../imm/Pasted%20image%2020251029142342.png%20)
La complessità rimane O(n log n)

Se le istanze non sono equiprobabili: 
	<span style="color:rgb(255, 255, 0)">Versione randomizzata</span>: scegli il perno X a caso fra gli elementi da ordinare

<span style="color:rgb(255, 255, 0)">Teorema</span>: 
L'algoritmo <span style="color:rgb(255, 255, 0)">QuickSort</span> randomizzato ordina in loco un array di lunghezza *n* in tempo O($n^2$) nel caso peggiore e O(n log n) tempo atteso

<span style="color:rgb(255, 255, 0)">Teorema</span>:
L'algoritmo <span style="color:rgb(255, 255, 0)">QuickSort</span> randomizzato ordina in loco un array di lunghezza *n* in tempo O($n^2$) nel caso peggiore e O(n log n) con alta probabilità, ovvero con probabilità almeno 1-1/n

QuickSort randomizzato (randomizzazione $\neq$ caso medio)
- Nessuna assunzione sulla distribuzione di probabilità delle istanze
- Nessun input specifico per il quale si verifica il caso peggiore
- Il caso peggiore determinato solo dal generatore di numeri casuali


![image](../../imm/image.png)

