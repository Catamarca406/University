
Fino ad' ora abbiamo visto due tipi di linguaggi: 
1. Linguaggio Procedurale 
2. Linguaggio Dichiarativo 

Nel classico linguaggio procedurale, abbiamo la *dichiarazione* di variabili, l'*assegnazione* di valori ad esse, la possibilità di attuare procedure e di creare algoritmi, fino ad arrivare a comporre funzioni. 
Nel procedurale viene "ignorata" la logica dietro alle assegnazioni;
Esempio: x = x + 1 , matematicamente non avrebbe senso, non esiste un valore per cui se stesso sia uguale al successivo.

In un linguaggio dichiarativo, incontriamo l'*unificazione* ovvero un valore che rende vera una sentenza;
Esempio: 4 + x = 5 è vero se x = 1.
Troviamo la *logica* e *predicati* questi ultimi composti da *fatti* (P(x)) e *regole* (P(a) :- P(b), P(c)).
Le *variabili* vengono rappresentate tramite l'iniziale maiuscola, oppure con l'underscore se non dobbiamo prendere il loro valore.
Le *costanti* si rappresentano in minuscolo, per scrivere in maiuscolo qualcosa si utilizzano gli apici 'mario'  = Mario.


>[!Example ] Esercizio:
> Definizione di genitore: 
> genitore(Gen1,F)
> 
> Trovare un fratello
> 
> 
> In logica proposizionale scriviamo:
> genitore(G,X) and genitore(G,Y) $\Rightarrow$ $\exists$G $\forall$X  and $\forall$Y
> 
> In prolog scriviamo:
> genitore(G,X) , genitore(G,Y) :- $\exists$G $\forall$X , $\forall$Y
> 
> Infine possiamo definire:
> sorelle_fratelli(X,Y) :- genitore(G,X) , genitore(G,Y)


>[!Example] Esercizio:
>Costruire un cruciverba:
>word(m,a,r,i,o)
>
>Cruciverba(
>A1,A2,A3,A4,A5,A6,
>B1,B2,B3,B4,B5,B6,
>C1,C2,C3,C4,C5,C6) :- word(A1,B1,C1), word(A1,A2,A3,A4,A5,A6), word(A3,B3,C3)
>	
>



