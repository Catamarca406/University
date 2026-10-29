#Intelligenza_Artificiale 

### Intelligenza Artificiale

Si occupa di: 
- Osservazione e comprensione delle attività legate al comportamento intelligente.
- Per riprodurne le leogiche e le funzionalità in modo accurato.

### Agenti Intelligenti

![584](../../../imm/image-230.png)
Gli agenti intelligenti ricevono percezioni da un <span style="color:rgb(112, 48, 160)">ambiente</span> e agiscono sull'ambiente mediante <span style="color:rgb(112, 48, 160)">azioni</span>. 
Hanno capacità di interazione sociale, possono comunicare, collaborare e difendersi da altri agenti.

#### Percezioni e Azioni

- Una <span style="color:rgb(255, 192, 0)">percezione</span> è l'insieme delle informazioni che l'agente riceve dall'ambiente attraverso i suoi sensori.
  
- La <span style="color:rgb(255, 192, 0)">sequenza percettiva</span> rappresenta la storia completa delle percezioni ricevute dall'agente fino a quel momento.
  
- La <span style="color:rgb(255, 192, 0)">scelta dell'azione</span>, l'azione che l'agente decidere di compiere dipende esclusivamente dalla sequenza delle percezioni ricevute. 
  
- La <span style="color:rgb(255, 192, 0)">funzione dell'agente</span> è la funzione che per ogni sequenza percettiva stabilisce quale azione l'agente deve compiere.
  Il programma dell'agente avviene quando la funzione agente viene concretamente realizzata attraverso un programma -> Agente Software / Programma Agente.
  Che permette all'agente di scegliere le azioni da eseguire. 

### Agenti Razionali

Un agente razionale interagisce con il suo ambiente in maniera efficace, mostrando una preferenza selettiva verso certi comportamenti.

Ha bisogno di un criterio di valutazione oggettivo dell'effetto delle azioni dell'agente. 

- Misure della prestazione 
	- <span style="color:rgb(112, 48, 160)">Esterna</span> (come vogliamo che il mondo evolva ?).
	- <span style="color:rgb(112, 48, 160)">Scelta dal progettista a seconda del problema</span> considerando la evoluzione massimamente desiderabile del mondo.
	- <span style="color:rgb(112, 48, 160)">Applicabile ad ambienti diversi</span>, non sempre è possible generalizzare.
	  
Definizione finale: Per ogni sequenza di percezioni compie l'azione che massimizza il valore atteso della misura delle prestazioni, considerando le sue percezioni passate e la sua conoscenza pregressa.

<span style="color:rgb(255, 192, 0)">Qualità</span>: 
Massimizzare il risultato atteso.
Acquisire informazioni.
Capacità limitate.
Modificare il proprio comportamento in base alla propria esperienza. 


### Agenti autonomi

Un agente è autonomo nella misura in cui il suo comportamento dipende dalla sua esperienza, del mondo e delle operazioni a lui richieste.

*Nota* : se un agente avesse il proprio comportamento determinato solo dalla sua conoscenza buil-in, sarebbe non completamente autonomo e poco flessibile.


#### Ambienti 

Definire un problema P per un agente significa caratterizzare l'ambiente in cui l'agente opera. 
La progettazione dell’agente corrisponde ad una soluzioni per P, ovvero 
- <span style="color:rgb(255, 192, 0)">Agente razionale</span> = <span style="color:rgb(255, 192, 0)">Soluzione</span> 

La descrizione <span style="color:rgb(255, 192, 0)">PEAS</span> dei problem è sistematica e caratterizza:
- <span style="color:rgb(255, 192, 0)">Performance</span> (Prestazione richiesta all'agente). 
- <span style="color:rgb(255, 192, 0)">Environment</span> (L'ambiente dove si muove l'agente).
- <span style="color:rgb(255, 192, 0)">Actuators</span> (Gli attuatori, che determinano le azioni possibili).
- <span style="color:rgb(255, 192, 0)">Sensors</span> (I sensori che consentono la percezione).


![](../../../imm/image-231.png)

#### Formulazione PEAS dei problemi:
![](../../../imm/image-232.png)

#### Proprietà dell'ambiente e del problema 

I diversi ambienti posseggono caratteristiche comuni lungo alcune dimensioni: 

-  Completamente Osservabile  <span style="color:rgb(255, 0, 0)">VS</span>. Parzialmente Osservabile  
-  Agente (Singole) <span style="color:rgb(255, 0, 0)">VS</span>. Multi-Agente 
-  Deterministico, Stocastico o Non Deterministico 
-  Episodico <span style="color:rgb(255, 0, 0)">VS</span>. Sequenziale 
-  Statistico <span style="color:rgb(255, 0, 0)">VS</span>. Dinamico 
-  Discreto <span style="color:rgb(255, 0, 0)">VS</span>. Continuo


<span style="color:rgb(255, 192, 0)">Osservabilità</span>:

Ambiente <span style="color:rgb(112, 48, 160)">completamente osservabile</span>: 

- L'apparato percettivo è in grado di dare una conoscenza completa dell'ambiente o almeno tutto quello che serve a decidere l'azione.
- Non c'è bisogno di mantenere uno stato del mondo.

Ambiente <span style="color:rgb(112, 48, 160)">parzialmente osservabile</span>: 

- Sono presenti limiti o inaccuratezze dell'apparato sensoriale.


<span style="color:rgb(255, 192, 0)">Ambiente Singolo</span> / <span style="color:rgb(255, 192, 0)">Multiagente</span>: 

Distinzione <span style="color:rgb(112, 48, 160)">agente</span> / <span style="color:rgb(112, 48, 160)">non agente</span>: 
- Il mondo può anche cambiare per eventi, non necessariamente per azioni di agenti.

Ambiente <span style="color:rgb(112, 48, 160)">multi-agente competitivo</span> :
- Comportamento randomizzato.

Ambiente<span style="color:rgb(112, 48, 160)"> multi-agente </span>:
- Comunicazione.


<span style="color:rgb(255, 192, 0)">Predicibilità</span>:

<span style="color:rgb(112, 48, 160)">Deterministico</span>: 
- Se lo stato successivo è completamente determinato dallo stato corrente e dall'azione.

<span style="color:rgb(112, 48, 160)">Stocastico</span>: 
- Esistono elementi di incertezza con una probabilità associata.

<span style="color:rgb(112, 48, 160)">Non Deterministico</span>:
- Se gli stati possibili non corrispondono ad una specifica distribuzione di probabilità.


<span style="color:rgb(255, 192, 0)">Episodico</span> / <span style="color:rgb(255, 192, 0)">Sequenziale</span>:

<span style="color:rgb(112, 48, 160)">Episodico</span>:
- L'esperienza dell'agente è divisa in episodi atomici indipendenti.
- In ambienti episodici non c'è bisogno di pianificare.

<span style="color:rgb(112, 48, 160)">Sequenziale</span>:
- Ogni decisione influenza le successive.


<span style="color:rgb(255, 192, 0)">Statico</span> / <span style="color:rgb(255, 192, 0)">Dinamico</span>:

<span style="color:rgb(112, 48, 160)">Statico</span>: 
- Il mondo non cambia mentre l'agente decide l'azione.

<span style="color:rgb(112, 48, 160)">Dinamico</span>: 
- I cambiamenti del mondo possono avvenire durante la decisione dell'agente.
- Ritardare una decisione equivale a non agire.

<span style="color:rgb(112, 48, 160)">Semi-dinamico</span>:
- L'ambiente non cambia ma la valutazione dell'agente si.

<span style="color:rgb(255, 192, 0)">Discreto</span> / <span style="color:rgb(255, 192, 0)">Continuo</span>:

<span style="color:rgb(112, 48, 160)">Discreto</span>:
- Lo stato, solo un numero finito di stati.
- Le azioni possibili

<span style="color:rgb(112, 48, 160)">Continuo</span>:
- Tempo
- Parametri

<span style="color:rgb(255, 192, 0)">Noto</span> / <span style="color:rgb(255, 192, 0)">Ignoto</span>:

Distinzione riferita allo stato di conoscenza dell'agente, l'agente conosce l'ambiente oppure deve compiere azioni esplorative? 
(Noto è diverso da osservabile)

Gli ambienti reali sono in genere: parzialmente osservabili, stocastici, sequenziali, dinamici, continui, multi-agente, ignoti.


#### L'automazione nell'ambiente

L'ambiente richiede la simulazione attraverso uno strumento software che si occupa di:
- <span style="color:rgb(112, 48, 160)">Generare stimoli </span>per gli agenti.
- <span style="color:rgb(112, 48, 160)">Raccogliere le azioni</span> in risposta.
- <span style="color:rgb(112, 48, 160)">Aggiornare il proprio stato</span>.
- <span style="color:rgb(112, 48, 160)">Valutare le prestazioni</span> degli agenti.


### Agenti con valutazione di utilità

<span style="color:rgb(255, 192, 0)">Obiettivi alternativi</span> :

- L'agente deve decidere verso quali muoversi
- Necessita di una <span style="color:rgb(112, 48, 160)">funzione di utilità </span>(Associa ad uno stato obiettivo un numero reale).

<span style="color:rgb(255, 192, 0)">Obiettivi + facilmente raggiungibili</span> :

- La funzione di utilità tiene conto della probabilità di successo.


#### Agenti che apprendono

<span style="color:rgb(255, 192, 0)">Componente di apprendimento</span> :
- Produce cambiamenti al programma agente.

<span style="color:rgb(255, 192, 0)">Elemento esecutivo</span> :
- Il programma agente.

<span style="color:rgb(255, 192, 0)">Elemento critico</span> :
- Osserva e fornisce feedback sul comportamento  (feedback di rinforzo o esempi di successo).

<span style="color:rgb(255, 192, 0)">Generatore di problemi</span> : 
- Suggerisce nuove situazioni da esplorare (generatore di nuovi dati per l'apprendimento).


![|515x352](../../../imm/image-233.png)

#### Tipi di rappresentazione

![490](../../../imm/image-234.png)
- <span style="color:rgb(255, 192, 0)">Rappresentazione atomica</span>: Stati finiti, Transizioni semplici, possibili estensioni probabilistiche.
  
- <span style="color:rgb(255, 192, 0)">Rappresentazione fattorizzata:</span> Fattori come dimensioni in uno spazio vettoriale.
  
- <span style="color:rgb(255, 192, 0)">Rappresentazione strutturata</span>: Rappresentazioni complesse come le relazioni delle RA o le espressioni ricorsive della logica.


### Agenti: Desiderata 

I sistemi di AI, gli agenti, sono sistemi complessi la cui progettazione e rilascio in ambiente operativo costituiscono fasi costose e a forte impatto sui processi tradizionali vigenti nelle organizzazioni.

- Sfide principali: 
  
	<span style="color:rgb(255, 192, 0)">Accuratezza</span> (prestazioni vicine a quelle degli esperti).
	<span style="color:rgb(255, 192, 0)">Generalità</span> (come portabilità a domini e task diversi).
	<span style="color:rgb(255, 192, 0)">Sostenibilità</span> nel tempo (limitati costi di manutenzione ed evoluzione).
	<span style="color:rgb(255, 192, 0)">Modularità</span> (quali componenti sono adatte per il riuso).
	<span style="color:rgb(255, 192, 0)">Trasparenza</span> (perché il sistema decide in un certo modo).
	<span style="color:rgb(255, 192, 0)">Scalabilità</span> (rispetto ai dati ed al numero di utenti).
