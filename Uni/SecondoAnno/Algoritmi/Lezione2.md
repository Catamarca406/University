#Algoritmi

## E’ sensato misurare la complessità di un algoritmo contando il numero di linee di codice eseguite?


Fino ad ora abbiamo visto modelli di calcolo come la bilancia e la padella, da adesso visualizzeremo come modello di calcolo il classico elaboratore.

## Un modello storico:

### La macchina di Turing

- Problemi: è troppo di basso livello, somiglia troppo poco ai calcolatori reali su cui girano programmi
- E’ utile per parlare di calcolabilità ma meno utile per parlare di efficienza

Un modello più realistico

- Macchina a registri (RAM: random access machine)
    - un programna ma finito
    - un nastro di ingresso e uno di uscita
    - una memoria strutturata come un array
        - ogni cella può contenere un qualunque valore intero/reale
    - una CPU per eseguire istruzioni
- La RAM è un’astrazione dell’architettura di von Neumann

![ 400](Pastedimage20251017144224.png)

## Modello di calcolo: cosa posso fare

- L’analisi della complessità di un algoritmo è basata sul concetto di passo elementare
- Passi elementari su una RAM
    - istruzione ingresso/uscita (accesso nastri I/O)
    - operazione aritmetica/logica
    - accesso/modifica del contenuto della memoria

## Criteri di costo: quanto mi costa

- Criterio di costo uniforme:
    - tutte le operazioni hanno lo stesso costo
    - complessità temporale misurata come numero di passi elementari eseguiti
- Criterio di costo logaritmico:
    - Il costo di una operazione dipende dalla dimensione degli operandi dell’istruzione
        
    - Un’operazione su un operando di valore x ha costo log x
        
    - E’ un criterio di costo che modella meglio la complessità di algoritmi “numerici”
- il criterio di costo generalmente usato è quello uniforme
T(n) = 
	\begin{cases}
	a T(n/b) \ + \ f(n) &\text{se n $ \ $ $\geq$ $ \ $ 1 }\\[12pt]	
	\Theta(1)  \quad &\text{se n $ \ $ $\leq$ $ \ $ 1}
	\end{cases}## Caso peggiore e caso medio

- Misureremo il tempo di esecuzione di un algoritmo in funzione della dimensione n delle istanze
- Istanze diverse, a parità di dimensione, potrebbero però richiedere tempo diverso
- Distinguiamo quindi ulteriormente tra analisi nel caso peggiore e medio

### Caso peggiore

- Sia tempo(I) il tempo di esecuzione (numero di passi elementari sul modello RAM) di un algoritmo sull’istanza I
    
    $T_{worst}  (n) = max_{\text{istanze I di dimensione n}} \cdot {tempo(I)}$
    
- Intuitivamente, $T_{worst}(n)$ è il tempo di esecuzione sulle istanze di ingresso che comportano più lavoro per l’algoritmo
    
- rappresenta una garanzia sul tempo di esecuzione di ogni istanza
    
 

### Caso medio

- Sia P(I) la probabilità di occorrenza dell’istanza I
    
     $T_{avg} (n)$ =  $\sum_{\text{istanze I di dimensione n}}$   {P(I) tempo(I)}
    
- Intuitivamente, $T_{avg} (n)$ è il tempo di esecuzione nel caso medio, ovvero sulle istanze di ingresso “tipiche” per il problema
    
- Come faccio a conoscere la distribuzione di probabilità sulle istanze?
    
- Semplice: (di solito) non posso conoscerla
    
- —> faccio un’assunzione
    
- spesso è difficile fare assunzioni realistiche
    

![Pasted image 20251017144352](Pastedimage20251017144352.png)
## Una grande idea: Notazione Asintotica

### Notazione asintotica: intuizioni

complessità computazionale di un algoritmo espressa con una funzione T(n)

T(n): numero di **passi** elementari eseguiti su una RAM nel caso peggiore su un’istanza di dimensione n

Idea: descrivere T(n) in modo qualitativo. Ovvero: perdere un po’ in precisione (senza perdere l’essenziale) e guadagnare in semplicità

T(n): # passi elementari eseguiti su una RAM nel caso peggiore su un’istanza di dimensione n
istanze I di dimensione n
un esempio:


$$
T(n) =
\begin{cases}
	71\ n^2 \ + \ 100 \ \lfloor n/4 \rfloor \ + \ 7 &\text{se n è pari}\\[12pt] 
	70\ n^2 + 150\ \lceil \ (n+1)/\ 4 \ \rceil\ +\ 5 \quad &\text{se n è dispari}
\end{cases}
$$
scriveremo: T(n) = Θ($n^2$) 

intuitivamente vuol dire: T(n) è proporzionale a $n^2$

cioè ignoro:

- costanti moltiplicative
- termini di ordine inferiore (che crescono più lentamente)

Nota:

l’assunzione implicita è che guardo come si comporta l’algoritmo su istanze grandi … una vecchia tabella: numero asintotico di pesate

assunzione: ogni pesata richiede un minuto

![Pasted image 20251017152028](Pastedimage20251017152028.png)
## TIpologie di notazioni asintotiche:

### **O-grande**

Notazione asintotica “ O “ , letta come O-grande

definizione formale:

- f(n) = O(g(n)) se esistono: una costante c > 0 e un certo punto $n_0$ ≥ 0 tali che 0 ≤ f(n) ≤ c g(n) per ogni n ≥ $n_0$

![Pasted image 20251017161850](Pastedimage20251017161850.png)

Esempi:
sia f(n) = 2n^2 + 3n, allora

- f(n) = O($n^3$) (per c=1, $n_0$=3)
- f(n) =O($n^2$) (per c=3, $n_0$=3)
- f(n) ≠ O(n)

la relazione fra f(n) e g(n) si può scrivere come:

lim n→inf $f(n)/g(n)$ = 0 allora f(n) = O(g(n))

### **Ω-grande**

Notazione asintotica “ Ω ” , letta come Omega - grande

definizione formale:

- f(n) = Ω(g(n)) se esistono: una costante c>0 e un certo punto $n_0$ ≥ 0 tali che f(n) ≥ c g(n) ≥ 0 per ogni n ≥ $n_0$

![Pasted image 20251017162005](Pastedimage20251017162005.png)

Esempi:
Sia f(n) = 2$n^2$ -3n, allora

- f(n) = Ω(n) ( per c=1, $n_0$=2)
- f(n) = Ω(n^2) ( per c=1, $n_0$=3)
- f(n) ≠ Ω(n^3)

la relazione fra f(n) e g(n) si può scrivere come:

lim n→inf $f(n)/g(n)$ = inf allora f(n) = Ω(g(n))

### **Θ-grande**

Notazione asintotica “ Θ “ , letta come theta-grande

definizione formale:

f(n) = Θ(g(n)) se esistono: due costanti $c_1$, $c_2$ > 0 e un certo punto $n_0$ ≥ 0 tali che $c_1$g(n) ≤ f(n) ≤ $c_2$g(n) per ogni n≥ $n_0$

![Pasted image 20251017162023](Pastedimage20251017162023.png)

Esempi:

Sia f(n) = 2$n^2$ - 3n, allora

- f(n) = Θ($n^2$) ( per c_1 = 1, $c_2$ = 2, $n_0$ = 3 )
- f(n) ≠ Θ(n)

la relazione fra f(n) e g(n) si può scrivere come:

f(n) = Θ(g(n)) allora posso dire che f(n) = O(g(n)) e se f(n) = Θ(n) allora f(n) = Ω(g(n))

### **o-piccolo**

Notazione asintotica “ o “, letta come o-piccolo

definizione formale:

f(n) = o(g(n)) se esistono: una costante c > 0 e un certo punto $n_0$ ≥ 0 tali che 0 ≤ f(n) < cg(n) per ogni n ≥ $n_0$

si può notare che o(g(n)) è contenuto in O(g(n))

la relazione fra f(n) e g(n) si può scrivere come:

f(n) = o(g(n)) se e solo se il lim n→inf f(n)/g(n) = 0

### **ω-piccolo**

Notazione asintotica “ ω “ , letta come omega-piccolo

definizione formale:

f(n) = ω(g(n)) se esistono: una costante c > 0 e un certo punto $n_0$ ≥ 0 tali che 0 ≤ cω(g(n)) < f(n) per ogni n ≥ $n_0$

si può notare che ω(g((n)) è contenuto in Ω(g(n))

la relazione fra f(n) e g(n) si può scrivere come:

f(n) = ω(g(n)) se e solo se il lim n→inf f(n)/g(n) = inf

## Proprietà della notazione asintotica

**Transitività**:

Se <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">Θ(g(n))</span> e <span style="color:rgb(0, 176, 240)">g(n)</span> = <span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)">Θ(h(n)</span><span style="color:rgb(0, 176, 240)">)</span></span></span> allora <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)"><span style="color:rgb(0, 176, 240)">Θ(h(n)</span><span style="color:rgb(0, 176, 240)">)</span></span></span>

Se <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">O(g(n))</span> e <span style="color:rgb(0, 176, 240)">g(n</span><span style="color:rgb(0, 176, 240)">)</span> = <span style="color:rgb(0, 176, 240)">O(h(n))</span> allora <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">O(h(n))</span>

Se <span style="color:rgb(0, 176, 240)">f(n</span><span style="color:rgb(0, 176, 240)">)</span> = <span style="color:rgb(0, 176, 240)">Ω(g(n))</span> e <span style="color:rgb(0, 176, 240)">g(n)</span> = <span style="color:rgb(0, 176, 240)">Ω(h(n))</span> allora <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">Ω(h(n))</span>

Se <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">o(g(n))</span> e <span style="color:rgb(0, 176, 240)">g(n)</span> = <span style="color:rgb(0, 176, 240)">o(<span style="color:rgb(0, 176, 240)">h(n)</span>)</span> allora <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">o(h(n))</span>

Se <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">ω(g(n)</span><span style="color:rgb(0, 176, 240)">)</span> e <span style="color:rgb(0, 176, 240)">g(n)</span> = <span style="color:rgb(0, 176, 240)">ω(h(n))</span> allora <span style="color:rgb(0, 176, 240)">f(n)</span> = <span style="color:rgb(0, 176, 240)">ω(h(n))</span>

**Riflessività**:
f(n) = Θ(f(n)
f(n) = O(f(n))
f(n) = Ω(f(n))

**Simmetria**: 
f(n) = Θ(g(n)) $\ \ \Leftrightarrow$  g(n) = Θ(f(n))

**Simmetria trasposta**: 
f(n) = O(g(n)) $\ \ \Leftrightarrow$  g(n) = Ω(f(n))
f(n) = o(g(n)) $\ \ \Leftrightarrow$   g(n) = ω(f(n))

## Ancora una convenzione 
Un insieme in una formula rappresenta un'anonima funzione dell'insieme
<span style="color:rgb(0, 176, 240)">E</span><span style="color:rgb(0, 176, 240)">sempio 1</span>: 
- f(n) = $n^3$ + O($n^2$)
	 sta per: c'è una funzione h(n) $\in$ O($n^2$) tale che
	f(n) = $n^3$ + h(n)
	
<span style="color:rgb(0, 176, 240)">Esempio 2</span>:
- $n^2$ + O(n) = O($n^2$) 
	 sta per: per ogni funzione f(n) $\in$ O(n), c'è una funzione h(n) $\in$ O($n^2$) tale che 
	 $n^2$ + f(n) = h(n)
In sostanza: in questi esempi viene mostrato come possiamo ridurre le notazioni asintotiche come delle semplici "costanti" quando abbiamo un termine più veloce 

Un'altra semplice proprietà per capire la velocità di una funzione è:
	Se lim  f(n)/g(n) = <span style="color:rgb(0, 176, 240)">c</span> > 0
		allora f(n) = Θ(g(n))
   Infatti:
	   <span style="color:rgb(0, 176, 240)">c</span>/2 < f(n)/g(n) < 2<span style="color:rgb(0, 176, 240)">c</span> 
	   per un <span style="color:rgb(0, 176, 240)">n</span> suff. grande 
	   
<span style="color:rgb(255, 0, 0)"><span style="color:rgb(255, 0, 0)">Esempio</span>:</span> 

>[!example] Esempio
>Se $T(n)$ = $a_{d} \ \cdot n^d \ a_{d-1} \ \cdot n^{d-1}+...+a_0$ è un polinomio di grado d (con $a_d$>0), allora T(n) = Θ($n^d$) 
>
>Infatti:
>$T(n)$ / $n^d$ = $a_d$ + $a_{d-1} \ \cdot n^{-1}+...+ a_0 \ \cdot n^{-d}$
>che tende a $a_d$ quando n--> $\infty$:




![Pasted image 20251018181637](Pastedimage20251018181637.png)

## Velocità asintotica di funzioni composte
date f(n) e g(n) 
		la velocità di andare a infinito della funzione f(n) + g(n) è la velocità della più veloce fra f(n) e g(n)

Esempi:
$n^3 + n = Θ($$n^3$)
n + $log^{10}$ n = Θ(n)

date f(n) e g(n), 
			La velocità ad andare a infinito della funzione f(n) e g(n) e la velocità di f(n) "più" la velocità di g(n)
			La velocità ad andare a infinito della funzione f(n)/g(n) e la velocità di f(n) "meno" la velocità di g(n)
	Esempio:
				![Pasted image 20251018202518](Pastedimage20251018202518.png)


## Usare la notazione asintotica nelle analisi 
### Analisi di complessità fibonacci3: un Upper Bound

algoritmo fibonacci3(intero n) --> intero 
	sia Fib un array di interi 
	Fib[1] <-- Fib[2] <--1
	 for i = 3 to n do
		 Fib[i] <-- Fib[i-1] + Fib[i-2]
	 return Fib[n]
	
T(<span style="color:rgb(0, 176, 240)">n</span>): complessità computazionale nel caso peggiore con input <span style="color:rgb(0, 176, 240)">n </span>

$c_j$ : # passi elementari eseguiti su una RAM quando è eseguita la linea di codice <span style="color:rgb(0, 176, 240)">j</span> 

- linea 1, 2 ,5 eseguite una volta
- linea 3, 4 eseguite al più n volte
T(<span style="color:rgb(0, 176, 240)">n</span>) : $c_1$ + $c_2$ + $c_3$ + ($c_4 + c_5$)<span style="color:rgb(0, 176, 240)">n</span> =  Θ(<span style="color:rgb(0, 176, 240)">n</span>)
	$\Rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = O(<span style="color:rgb(0, 176, 240)">n</span>)



### Analisi di complessità fibonacci3: un Lower Bound 

algoritmo fibonacci3(intero n) --> intero 
	sia Fib un array di interi 
	Fib[1] <-- Fib[2] <--1
	 for i = 3 to n do
		 Fib[i] <-- Fib[i-1] + Fib[i-2]
	 return Fib[n]

T(<span style="color:rgb(0, 176, 240)">n</span>): complessità computazionale nel caso peggiore con input <span style="color:rgb(0, 176, 240)">n </span>

$c_j$ : # passi elementari eseguiti su una RAM quando è eseguita la linea di codice <span style="color:rgb(0, 176, 240)">j</span> 

- linea 4 è eseguita almeno n-3 volte (definizione di Omega grande, parto dal caso "base")
T(<span style="color:rgb(0, 176, 240)">n</span>) $\geq$  $c_4$ (<span style="color:rgb(0, 176, 240)">n</span>-3) = $c_4$<span style="color:rgb(0, 176, 240)">n</span> -3$c_4$ = Θ(<span style="color:rgb(0, 176, 240)">n</span>)
	$\Rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = Ω(<span style="color:rgb(0, 176, 240)">n</span>)
		$\Rightarrow$ T(<span style="color:rgb(0, 176, 240)">n</span>) = Θ(<span style="color:rgb(0, 176, 240)">n</span>)



## Notazione asintotica: Perché è una grande idea 

- <span style="color:rgb(0, 176, 240)">Misura indipendente</span> dall'implementazione dell'algoritmo e dalla macchina reale su cui è eseguito 
- I "dettagli" nascosti (costanti moltiplicative e termini di ordine inferiore) sono <span style="color:rgb(0, 176, 240)">poco rilevanti</span> quando <span style="color:rgb(0, 176, 240)">n</span> è grande per funzioni asintoticamente diverse (guarda tabella)
- <span style="color:rgb(0, 176, 240)">analisi dettagliata</span> del numero di passi realmente eseguiti sarebbe difficile, noiosa e <span style="color:rgb(0, 176, 240)">non direbbe molto di più</span> (come si possono conoscere per esempio i costi reali di un'istruzione di alto livello?)
- si è visto che descrive bene <span style="color:rgb(0, 176, 240)">in pratica</span> la velocità degli algoritmi 