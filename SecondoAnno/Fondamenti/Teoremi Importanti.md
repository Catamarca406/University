#fondamenti 

## Calcolabilità 

>[!definition]- Teorema 3.1: 
> Un linguaggio $L$  $\subseteq \Sigma^*$  è Decidibile $\iff$ $L$ e $L^c$ sono Accettabili     

$dim.$

$(\Rightarrow)$ 

Se $L$ è Decidibile, allora esiste una m.T. che $\forall \ \ x \in \Sigma^*$ , con input x termina in $q_A$  se $x \in L$
e termina nello stato $q_R$ se $x \in L^c$.
Dunque $O_t(x) = q_A \iff x \in L$ , ossia T Accetta $L$.  

Deriviamo da T una nuova macchina T'. 
Gli stati di T' sono gli stessi di T più 2 nuovi stati finali = $q_A$' e $q_R$' . 
Le quintuple sono le stesse di T più 2 nuove quintuple: 
<$q_A$, u, u, $q_R$' ,F>  e  <$q_R$, u, u, $q_A$' ,F>  $\forall u \in \Sigma \ \ \cup$ {$\square$}. 

Quindi, $\forall \ \ x \in \Sigma^*$ , la computazione T'(x) coincide con la computazione T(x) tranne per l'ultima istruzione eseguita da T'(x):  
- Se T(x) termina in $q_A$ $\Rightarrow$ T'(x) esegue un'altra istruzione e termina in $q_R$'
-  Se T(x) termina in $q_R$ $\Rightarrow$ T'(x) esegue un'altra istruzione e termina in $q_A$'

Allora, T'(x) Accetta x $\iff$ $x \in L$ , ossia, se e solo se $x \in L^c$.
Quindi T' Accetta $L^c$.

$(\Leftarrow)$ 

Viceversa, se $L$ è Accettabile e $L^c$ è Accettabile $\Rightarrow$ esistono due m.T.  $T_1$ e $T_2$ : 
$\forall \ \ x \in \Sigma^*$ :
 - $T_1$ Accetta $\iff$ $x \in L$ 
 -  $T_2$ Accetta $\iff$ $x \in L^c$ 
  
Definiamo una nuova m.T. $T$ che simulando le due computazioni di $T_1$ e $T_2$ , Decide $L$.

*Nota* : simulare interamente prima una computazione e poi l'altra non garantisce la terminazione.
La simulazione delle due macchine deve avvenire alternativamente.

T dispone di due nastri, inizializzati con l'input x, la computazione T(x) avviene alternando sui due nastri singole istruzioni di $T_1$ e $T_2$: 

1) Esegui una singola istruzione di $T_1$ su $N_1$ : 
	- Se $T_1$ = $q_A$ $\Rightarrow$ T Accetta.
	- Altrimenti esegui il passo <span style="color:rgb(0, 176, 240)">2)</span> .
	  
2) Esegui una singola istruzione di $T_2$ su $N_2$ : 
	- Se $T_2$ = $q_A$ $\Rightarrow$ T Rigetta.
	- Altimenti esegui il passo <span style="color:rgb(0, 176, 240)">1)</span> .
	  
Sia ora $x \in \Sigma^*$ : 
- Se $x \in L$  $\Rightarrow$ prima o poi al passo <span style="color:rgb(0, 176, 240)">1)</span> $T_1$ entrerà in $q_A$ portando $T$ ad Accettare.
- Se $x \in L^c$  $\Rightarrow$ prima o poi al passo <span style="color:rgb(0, 176, 240)">2)</span> $T_2$ entrerà in $q_A$ portando $T$ ad Rigettare.

Quindi, T Decide $L$.

$\square$ 

---

>[!definition]- Teorema 3.2: 
> Un linguaggio $L$  $\subseteq \Sigma^*$  è Decidibile $\iff$ $\chi_L$ è Calcolabile     

$dim.$

$(\Rightarrow)$<span style="color:rgb(0, 176, 240)"> </span>

Supponiamo che $L$ sia Decidibile $\Rightarrow$ esiste una m.T. Riconoscitore T con stati finali = $q_A$ e $q_R$: 

$$
O_T(x) = 
	\begin{cases}
	q_A &\text{se x $\in L$} \\[12pt]	
	q_R &\text{se x $\in L^c $}
	\end{cases}
$$
 Supponiamo che T utilizzi un unico nastro. 
 
 A partire da T, definiamo una m.T. Trasduttore T' a 2 nastri con input $x \in \Sigma^*$ , che opera nella maniera seguente:
 
 1) Su $N_1$ , su cui è scritto l'input x, esegue la computazione T(x).
    
 2) Se T(x) termina in $q_A$ $\Rightarrow$ scrive sul nastro di output il valore 1.
	Altrimenti scrive il valore 0.
	Successivamente termina.
    
 *Nota* : visto che $L$ è Decidibile, il passo <span style="color:rgb(0, 176, 240)">1)</span> termina per ogni $\forall \ \ x \in \Sigma^*$
  - Se $x \in L$ $\Rightarrow$ T(x) termina in $q_A$ , al passo 2) T'(x) scriverà sul $N_{output}$ 1
  - Se $x \in L^c$ $\Rightarrow$ termina in $q_R$ , al passo 2) T'(x) scriverà sul $N_{output}$ 0
    
Questo dimostra che $\chi_L$ è Calcolabile.

$(\Leftarrow)$ 

Supponiamo che $\chi_L$ sia Calcolabile, per costruzione $\chi_L$ è una Funzione Totale $\Rightarrow$ esiste una m.T. Trasduttore T che $\forall \ \ x \in \Sigma^*$ , che opera nella maniera seguente: 

1) Su $N_1$ , su cui è scritto l'input x, esegue la computazione T(x), scrivendo il risultato su $N_2$.

2) Se su $N_2$ è scritto 1 $\Rightarrow$ la computazione T'(x) termina in $q_A$ ,
   altrimenti termina in $q_R$ .

*Nota* : poiché $\chi_L$ è Totale, il passo 1) termina $\forall x$.  
- Se $\chi_L$(x) = 1  (allora $x \in L$) $\Rightarrow$  il passo <span style="color:rgb(0, 176, 240)">1)</span> termina scrivendo 1 su $N_2$ e al passo 2) T'(x) termina in $q_A$ .
- Se $\chi_L$(x) = 0 (allora $x \in L^c$) $\Rightarrow$  il passo <span style="color:rgb(0, 176, 240)">1)</span> termina scrivendo 0 su $N_2$ e al passo 2) T'(x) termina in $q_R$ .
  
  Questo dimostra che $L$ è Decidibile.

$\square$

---
 
 >[!definition]- Teorema 3.3: 
>Se la funzione $f:\Sigma^* \to\Sigma^*_1$ è totale calcolabile $\Rightarrow$ il linguaggio $L_f  \subseteq \Sigma^* \times \Sigma^*_1$ è Decidibile           
>
 
 $dim.$
 
 Poiché $f$ è Totale e Calcolabile $\Rightarrow$ esiste una m.T. Trasduttore T che $\forall \ \ x \in \Sigma^*$ , calcola f(x).
 
 Definiamo una m.T. T' con input (x,y) : $x \in \Sigma^*$ e $y \in \Sigma^*_1$ che opera nella seguente maniera: 
 
 1) Su $N_1$ è scritto l'input (x,y).
    
 2) Su $N_2$ esegue la computazione di T(x) scrivendo il risultato f(x).
    
 3) Esegue il confronto tra f(x) e y:
	 - Se f(x) = y  $\Rightarrow$ T'(x) termina in $q_A$. 
	 - Altrimenti T'(x) termina in $q_R$.

*Nota* : Dato che $f$ è Totale, il passo 2) termina $\forall$ x.
Se f(x) = y  $\Rightarrow$ il passo <span style="color:rgb(0, 176, 240)">2)</span> termina scrivendo y su $N_2$ e al passo <span style="color:rgb(0, 176, 240)">3)</span> T'(x) termina in $q_A$
Se f(x) $\not=$ y  $\Rightarrow$ il passo <span style="color:rgb(0, 176, 240)">2)</span> termina scrivendo y su $N_2$ e al passo <span style="color:rgb(0, 176, 240)">3) </span>T'(x) termina in $q_R$ 
 
 Questo dimostra che $L_f$ è Decidibile. 
 
 $\square$
 
 ---
 
  >[!definition]- Teorema 3.4: 
>Sia $f:\Sigma^* \to\Sigma^*_1$ una funzione.
> Se il linguaggio $L_f  \subseteq \Sigma^* \times \Sigma^*_1$ è Decidibile $\Rightarrow$ $f$ è Calcolabile.           
>
 
 $dim.$
 
 Se $L_f  \subseteq \Sigma^* \times \Sigma^*_1$ è Decidibile  $\Rightarrow$ esiste una m.T. T Riconoscitore che (x,y) : $x \in \Sigma^*$ e $y \in \Sigma^*_1$ 
 
 $$
 T(x,y) = 
	\begin{cases}
	q_A &\text{se y = f(x)} \\[12pt]	
	q_R &\text{se x $\not=$ f(x)}
	\end{cases}
 $$
 
 Deriviamo una m.T. T' Trasduttore a 4 nastri che lavora nel modo seguente: 
 
 $N_1$ --> scrive l'input (x,y).
 $N_2$ --> scrive $i$ = 0 , per contare la lunghezza delle stringhe y.
 $N_3$ --> scrive la stringa y con lughezza $i$. 
 $N_4$ --> Simula T(x,y) : 
 - Se T(x,y) = $q_A$  $\Rightarrow$ T'(x) termina e scrive f(x) su $N_{out}$.
 - Altrimenti incrementa $i$ e ricomincia a cercare la stringa y con nuova lunghezza.
  
*Nota* : Dato che $L_f$ è Decidibile $\Rightarrow$ la computazione T(x,y) termina $\forall$ (x,y).
Se $x \in \Sigma^*_1$  $\Rightarrow$ esiste una y che permetterà a T(x,y) di entrare in $q_A$ in modo che T'(x) termini, scrivendo f(x) su $N_{out}$.

Questo dimostra che $f$ è Calcolabile.

*Nota 2* : Mentre se $x \not= \Sigma^*_1$ allora non avremmo modo di trovare una y che permette a T(x,y) di terminare in $q_A$ $\Rightarrow$ T'(x) non termina.

L'ipotesi di Decidibilità non permette di dimostrare la calcolabilità.

$\square$

---
### Halting Problem

Dato un linguaggio $L_H$ = {($i, x$) : $i$ contiene solo le cifre tra '0' e '7' & $i$ è la codifica di una m.T.  &  $T_i(x)$ termina : $L_H \subseteq$ $\mathbb N\ \times\ \mathbb N$ }

Si vuole dimostrare che il linguaggio $L_H$ è Accettabile ma Non Decidibile.

  >[!definition]- Teorema 5.4: 
>$L_H$ è un linguaggio Accettabile.           
>

$dim.$
 
Dobbiamo dimostrare che $\forall (i,x) \in \mathbb N\ \times\ \mathbb N$ , 
T$(i,x)$ = $q_A$ $\iff$ $(i,x) \in L_H$.

La macchina T è una modifica della m.T. universale U, la macchina ha 4 nastri come U e lavora nel modo seguente: 
 
$N_1$ --> scrive il numero $i$ 
$N_2$ --> scrive $x \in$ {$0,1$}$^*$

T inizia la sua computazione veriicando che 
1. ($i$ $\not=$ '8' e '9')  
2. Inizi con '2'
	- Se <span style="color:rgb(0, 176, 240)">1.</span> non è verificato $\Rightarrow$ $q_R$ (non appartiene ad $L_H$).
	- Se <span style="color:rgb(0, 176, 240)">1.</span> è verificato e <span style="color:rgb(0, 176, 240)">2.</span> no $\Rightarrow$ elimino '2' e traduco ciò che rimande in $\Sigma$ di U.

$N_3$ --> Simula U, se U$(i,x)$ termina ($q_A$ o $q_R$)

$\square$
 
---
## Complessità

>[!definition]- Teorema 6.8: 
>Per ogni funzione totale calcolabile $f:\mathbb N\to\mathbb N$,
  $$DTIME[f(n)] \subseteq NTIME[f(n)]$$   

$dim.$

E' sufficiente notare che una m.T. Deterministica è una particolare m.T. Non Deterministica con grado di Non Determinismo = 1, se la m.T. decide un linguaggio in k passi $\implies$ accetta anche in k passi

$\square$ 

---

>[!definition]- Teorema 6.9: 
>Per ogni funzione totale calcolabile $f:\mathbb N\to\mathbb N$,
  $$DTIME[f(n)] \subseteq DSPACE[f(n)]$$
  $$\&$$
  $$NTIME[f(n)] \subseteq NSPACE[f(n)].$$
  
$dim.$

Sia $L \subseteq \Sigma^*$ : $L \in DTIME[f(n)]$ $\Rightarrow$ esiste una m.T. Deterministica T che Decide L : $\forall \ \ x \in \Sigma^*$ 
$[$ dtime(T,x) $\in$ O($f|x|$) $]$  

Poiché dspace(T,x) $\leq$ dtime(T,x) $[ \text{non possiamo avere più celle che quintuple: il \# di celle è pari almeno al \# di istruzioni}]$

$\Rightarrow$ dspace(T,x) $\in$ O($f|x|$)  $\& \ \ L \in DSPACE[f(n)]$ . 

$\square$

---


>[!definition]- Teorema 6.10: 
>Per ogni funzione totale calcolabile $f:\mathbb N\to\mathbb N$,          
>$$DSPACE[ f (n)] \subseteq DTIME[2^{O(f(n))} ]$$ 
>$$\&$$ 
>$$NSPACE[ f (n)] \subseteq NTIME[2^{O(f(n))}].$$

$dim.$

- Anche in questo caso, la prova segue direttamente dal Teorema 6.1. [^1]
- Sia $L \subseteq \{0,1\}^\star | L \in DSPACE[f(n)]$: allora, esiste una macchina di Turing deterministica T che Decide L e tale che, per ogni $x \in \{0,1\}^\star$, $dspace(T,x) \in O(f(|x|))$. 
- Poiché $$\begin{align}dtime(T,x) &\leq dspace(T,x)|Q| (|\Sigma|+1)^{dspace(T,x)} = dspace(T,x)|Q| 3^{dspace(T,x)}\\& = 2^{\log{( dspace(T,x))}} |Q| [2^{\log{3}}]^{dspace(T,x)} \\&=|Q| 2^{\log dspace(T,x) + dspace(T,x) \log3}\leq|Q| 2^{[1+\log{3} ] dspace(T,x)}\end{align} $$
- allora $dtime(T,x) ∈ O(2^{O(f(|x|))} )$ 
- e, dunque, $L \in DTIME[ 2^{O(f(n))} ]$.

La dimostrazione. per il caso non deterministico è analoga.

$\square$

---

>[!definition]- Teorema 6.17: 
>Per ogni funzione totale calcolabile $f \ \ \text{time constructible:}$
>$$NTIME[f(n)] \subseteq DTIME[2^{O(f(n))} ]$$

$dim.$

Sia $L \subseteq \Sigma^*$ : $L \in NTIME[f(n)]$ allora esiste una m.T Non Determinista NT che Accetta L e $h \in \mathbb N \ \ e \ \ \forall \ \ x \in L$ $[$ ntime(NT,x) $\in$ O($hf(x$)).

Poiché $f$ è $\text{time constructible}$, esiste una m.T. $T_f$ (Trasduttore) che preso $n \in \mathbb N$ in input calcola $f(x)$ in tempo O($f(n)$) .

Mentre con $k \in \mathbb N$ indichiamo il Grado di Non Determinismo di NT.

Deriviamo da NT una nuova m.T Deterministica T con input x, che simulerà tutte le computazioni Deterministiche di NT(x) con lunghezza $hf(x)$ .

1) Simula $T_f(x)$ : 
	- $\forall$ carattere 'x' scrive '1' su $N_2$.
	- Calcola $f|x|$ scrivendola su $N_3$.
	- Concatena $h$ - volte il contenuto su $N_3$ ottenendo: $hf(x)$.

 2) Simula ogni computazione Deterministica di NT(x), di lunghezza $hf(x)$ utilizzando per ogni computazione la testina su $N_3$ per scorrere.

Poiché $x \in L$ , ntime(NT,x) $\leq$ $hf(x)$ allora in $hf(x)$ passi NT(x) = $q_A$ oppure $x \notin L$.
Se dopo aver simulato tutte le computazioni di NT, NT(X) $\not= q_A$  allora neanche T entra in $q_A$ quindi può entrare correttamente in $q_R$.

Questo dimostra che T Decide $L$ .

Detto k il Grado di Non Determinismo delle computazioni Deterministiche di NT(x) con lunghezza $hf(x)$ è $k^{hf(x)}$, ciascuna simulata da T in O($f|x|$) passi.

Allora dtime(T,x) $\in$ O($f|x| * k^{hf(x)}$)  $\subseteq$ O($2^{O(f(n))}$) . 

$\Rightarrow$ $L \in DTIME[2^{O(f(x))}]$ 

$\square$ 

---

>[!definition]- Specifiche Classi di Complessità:  
>$$\text{P} = \bigcup_{k \in \mathbb{N}} \text{DTIME}[n^k] : \text{classe di linguaggi decidibili in tempo deterministico polinomiale.}$$
>
>$$\text{PSPACE} = \bigcup_{k \in \mathbb{N}} \text{DSPACE}[n^k] : \text{classe di linguaggi decidibili in spazio deterministico polinomiale.}$$
>
>$$\text{coP} = \{L \subseteq \Sigma^* \mid \Sigma \text{ è un alfabeto finito e } L^c \in \text{P}\}.$$
>
>$$\text{EXPTIME} = \bigcup_{k \in \mathbb{N}} \text{DTIME}[2^{n^k}] : \text{classe di linguaggi decidibili in tempo deterministico esponenziale.}$$
>
>$$\text{NP} = \bigcup_{k \in \mathbb{N}} \text{NTIME}[n^k] : \text{classe di linguaggi accettabili in tempo non deterministico polinomiale.}$$
>
>$$\text{NPSPACE} = \bigcup_{k \in \mathbb{N}} \text{NSPACE}[n^k] : \text{classe di linguaggi accettabili in spazio non deterministico polinomiale.}$$
>
>>$$\text{coNP} = \{L \subseteq \Sigma^* \mid \Sigma \text{ è un alfabeto finito e } L^c \in \text{NP}\}.$$
>>
>>$$\text{NEXPTIME} = \bigcup_{k \in \mathbb{N}} \text{NTIME}[2^{n^k}] : \text{classe di linguaggi accettabili in tempo non deterministico esponenziale.}$$

---

Definizione di *chiusura* rispetto ad una certa classe *C*.
$\forall \ \ L_1  \ e  \ L_2$ : $L_1 \leq L_2$ con $L_2 \in C$ $\Rightarrow L_1 \in C$ . 


>[!definition]- Teorema 6.21: 
> $$\text{La classe P è chiusa rispetto alla riducibilità polinomiale.}$$

$dim.$

Siano $L_1 \in \Sigma_1^*$ e $L_2 \in \Sigma_2^*$  due linguaggi : $L_1 \leq L_2$  e $L_2 \in P$ e  $(h,k)\in \mathbb N$.  

Sia $f : \Sigma_1^* \rightarrow \Sigma_2^*$ una funzione in FP, che riduce $L_1 \leq L_2$.

Costruiamo 2 m.T. ad 1 nastro: 
- $T_f$ : calcola $f$ in tempo polinomiale.
- $T_2$ : decide $L_2$ in tempo polinomiale.

Deriviamo una terza m.T a 2 nastri, $T_1$ che deciderà $L_1$ :

- $N_1$ : simula $T_f(x) \rightarrow T_f(x)$ legge x su $N_1$ in dtime($T_f$,x) $\in$ O($|x|^h$).
   
- $$ N_2 : simula
\  \
T_2(f(x))
	\begin{cases}
	q_A \Rightarrow T_1(x) = q_A. \\[12pt]	
	q_R \Rightarrow T_1(x) = q_R.
	\end{cases}
 $$
 in tempo dtime($T_2$ , $f(x)$) $\in$ O($f(x)^k$) = O($x^{hk}$).

Dato che f è una riduzione da $L_1 \leq L_2$ quindi $f(x) \in L_2 \iff x \in L_1$, allora $T_1$ termina per ogni input $x \in \Sigma_1^*$ e $T_1(x)$ accetta $\iff$ $x \in L_1 \rightarrow T_1$ decide $L_1$. 

Dato che impieghiamo : dtime($T_1$ , x) $\in$ O($|x|^h + |x|^{hk}$) e h,k sono due costanti $\Rightarrow$ $L_1 \in$ P.

$\square$

---

Definizione di *completezza* rispetto ad una classe di linguaggi e una riduzione: 
Un linguaggio $L \subseteq \Sigma^*$ è C-completo all riducibilità se:
1. $L \in C$ .
2. $\forall \ \ altro \ \ L' \in C$ vale che $L' \leq L$ .   


>[!definition]- Teorema 6.25: 
> $$\text{Un linguaggio $L$ è NP-Completo $\iff$ $L^c$ è coNP-Completo .}$$

$dim.$

($\Rightarrow$) 

Se $L \in$ NP-completo $\Rightarrow$ $L \in$ NP (per definizione) quindi $L^c \in$ coNP.

In virtù della completezza di $L$ per NP : $\ \ \forall \ \ L' \in$ NP , $L' \leq L$ . 

Significa che $\forall \ \ L' \in$ NP esiste una funzione $f_L$ : $\Sigma' \rightarrow \Sigma$ :  $f_{L'} \in$ FP e $\forall$ $x \in \Sigma'$ , $x \in L' \iff f_{L'}(x) \in L$.

Ciò significa che $\forall \ \ x \in \Sigma'$ , se $x \notin L' \iff f_{L'}(x) \notin L$ ossia : 
$\forall \ \ x \in L^{c'} \iff f_{L'}(x) \in L^c$. 

$\rightarrow L^c$ è completo per coNP. 


($\Leftarrow$) 

Se $L^c \in$ coNP-complemento $\Rightarrow$ $L^c \in$ coNP (per definizione) quindi $L \in$ NP.

In virtù della completezza di $L^c$ per coNP:  $\forall \ \ L^{c'}\in$ coNP, $L^{c'} \leq L^c$.

Significa che $\forall \ \ L^{c'} \in$ coNP esiste una funzione $f_L : \Sigma' \rightarrow \Sigma$ : $f_{L^{c'}} \in$ FP e $\forall \ \ x \in \Sigma', \ \ x \in L^{c'} \iff f_{L^{c'}}(x) \in L^c$.

Ciò significa che $\forall \ \ x \in \Sigma'$ se $x \notin L^{c'} \iff f_{L^{c'}} \notin L^c$ ossia :
$\forall \ \  x \in \Sigma' ,\ \ x \in L' \iff f_{L'}(x) \in L$.     

$\rightarrow L$ è completo per NP.

$\Rightarrow$ $L$ è NP-Completo $\iff$ $L^c$ è coNP-Completo.

$\square$ 

--- 

