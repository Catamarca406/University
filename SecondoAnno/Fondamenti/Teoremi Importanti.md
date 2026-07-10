#fondamenti 

Teo 6.8 


$\forall$ funzione TOTALE e CALCOLABILE       f : $\mathbb{N}$ -> $\mathbb{N}$
**DTIME[f(n)] $\subseteq$ NTIME[f(n)]**     

dim.

E' sufficiente notare che una m.T. Deterministica è una particolare m.T. Non Deterministica con grado di Non Determinismo = 1, se la m.T. decide un linguaggio in k passi $\implies$ accetta anche in k passi

$\square$ 





Teo 6.10

>[!definition]- Teorema 6.10: 
>Per ogni funzione totale calcolabile $f:\mathbb N\to\mathbb N$,          
>$$DSPACE[ f (n)] \subseteq DTIME[2^{O(f(n))} ];NSPACE[ f (n)] \subseteq NTIME[2^{O(f(n))}].$$

dim
- Anche in questo caso, la prova segue direttamente dal Teorema 6.1. [^1]
- Sia $L \subseteq \{0,1\}^\star | L \in DSPACE[f(n)]$: allora, esiste una macchina di Turing deterministica T che decide L e tale che, per ogni $x \in \{0,1\}^\star$, $dspace(T,x) \in O(f(|x|))$. 
- Poiché $$\begin{align}dtime(T,x) &\leq dspace(T,x)|Q| (|\Sigma|+1)^{dspace(T,x)} = dspace(T,x)|Q| 3^{dspace(T,x)}\\& = 2^{\log{( dspace(T,x))}} |Q| [2^{\log{3}}]^{dspace(T,x)} \\&=|Q| 2^{\log dspace(T,x) + dspace(T,x) \log3}\leq|Q| 2^{[1+\log{3} ] dspace(T,x)}\end{align} $$
- allora $dtime(T,x) ∈ O(2^{O(f(|x|))} )$ 
- e, dunque, $L \in DTIME[ 2^{O(f(n))} ]$.

La dimostrazione per il caso non deterministico è analoga.