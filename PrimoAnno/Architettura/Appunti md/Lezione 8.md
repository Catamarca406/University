#Architettura 

## Architetture Parallele

Per incrementare drasticamente le Performance occorre progettare Sistemi con molte CPU.

La **classificazione di Flynn**: 

![](../../../imm/image-222.png)

E' utile ricordare i <span style="color:rgb(255, 0, 0)">2 tipi di Parallelismo</span>:
- <span style="color:rgb(0, 176, 240)">Livello delle ISTRUZIONI </span>-> Più istruzioni in 1 ciclo di clock.
-<span style="color:rgb(0, 176, 240)"> Livello della CPU</span> -> Più CPU collaborano per lo stesso compito.

### MultiThreading nel Chip

Quando parliamo di multithreading in un chip intendiamo la possibilità di passare da un THREAD ad un altro per evitare le Attese dovuto al tentativo di accesso in Memoria.

<span style="color:rgb(255, 0, 0)">Tipi di Multithreading</span>:

- A <span style="color:rgb(0, 176, 240)">Grana FIne</span> -> Le singole istruzioni dei thread sono eseguite ad ogni ciclo di clock, nei cicli di STALLO la CPU è occupata con altri thread.
- A <span style="color:rgb(0, 176, 240)">Grana Grossa</span> ->Un thread va avanti fino allo STALLO.
- <span style="color:rgb(0, 176, 240)">Simultaneo</span> -> Ogni thread ha 2 istruzioni per Ciclo fino allo STALLO.


### Multiprocessori

Il calcolatore, contiene più CPU (dette CORE) nello stesso chip, che condividono la Memoria principale.

<span style="color:rgb(255, 0, 0)">TIPI di Multiprocessori </span>: 

1. **UMA** (Uniform Memory Access) -> Può essere di diversi tipi:

   - Con <span style="color:rgb(0, 176, 240)">SINGOLO BUS</span>: Funziona bene con poche CPU.
     
   - Con <span style="color:rgb(0, 176, 240)">SINGOLO BUS e CACHE nella CPU:</span> Riduce il traffico sulla bus.
     
   - Con <span style="color:rgb(0, 176, 240)">SINGOLO BUS e CPU dotate di RAM</span>: Separazione tra le variabili locali (RAM) e globali (BUS).
     
   - Con <span style="color:rgb(0, 176, 240)">CROSBAR SWITCH:</span> Rete di INTERCONNESSIONE che collega "N" CPU a "K" Memorie.
   
   - Con<span style="color:rgb(0, 176, 240)"> Rete di COMMUTAZIONE MULTILIVELLO</span>:  Scambio di messagi che contengono (MODULO, INDIRIZZO,OPCODE,VALORE). 
     
     Un esempio è la <span style="color:rgb(255, 0, 0)">RETE OMEGA</span>: Ha uno schema *PERFECT SHUFFLE*, collega ad "N" CPU, "N" MEMORIE, è una *RETE BLOCCANTE* -> non tutte le richieste possono essere processate contemporaneamente. I riferimenti in Memoria vanno distribuiti rispetto ai moduli.
     
2. **NUMA** (Non Uniform Memory Access) -> Prevede uno spazio di indirizzamento unico rendendo lento l'accesso alla memoria remota. 
   
   Sono presenti due tipi di *NUMA*:
   
	- <span style="color:rgb(0, 176, 240)">NO CACHE NUMA</span>: il ritardo di accesso alla memoria vuota non è mascherato.
	- <span style="color:rgb(0, 176, 240)">CACHE NUMA</span>: C'è un sistema di CACHE COERENTI, con un database si tiene traccia di ogni linea di cache, per mascherare il ritardo di accesso.
	  
3. **Modello MASTER-SLAVE**:  
   - Una sola CPU (*MASTER*) gestisce il S.O. e le chiamate, le altre CPU (*SLAVE*) eseguono solo i processi utente.
     
4. **Multiprocessori SIMMETRICI** -> Tutte le CPU condividono una copia del S.O. e possono gestire le chiamate.


### Multicomputer

In un multicomputer, tutte le CPU sono interconnesse, ognuna con la sua memoria.

La comunicazione tra PROCESSI avviene tramite lo SCAMBIO di MESSAGGI attraverso la RETE di INTERCONNESSIONE.

Ogni CPU riconosce la CPU che ha inviato la richiesta e fornisce una copia dei dati richiesti 
-> <span style="color:rgb(0, 176, 240)">SEND & RECEIVE</span>.

<span style="color:rgb(255, 0, 0)">L'invio dei messaggi può essere</span>:
- <span style="color:rgb(0, 176, 240)">Blocking</span> -> La CPU si BLOCCA fino alla fine della trasmissione.
- <span style="color:rgb(0, 176, 240)">Non Blocking</span> -> La CPU prosegue le sue operazioni.
  
<span style="color:rgb(255, 0, 0)">L' HARDWARE dei MULTICOMPUTER</span>:

La TOPOLOGIA di una RETE è il modo in cui sono disposti i COLLEGAMENTI e i COMMUTATORI:
Le topologie di multicomputer sono le seguenti:

- **STELLA** -> Tutti i nodi sono Connessi ad 1 Switch Centrale che gestisce tutte le comunicazioni, questa topologia è vulnerabile ai guasti.

  ![](../../../imm/image-223.png)
- **ANELLO** -> Ogni nodo è collegato al PRECEDENTE e al SUCCESSIVO, è economico ma ha prestazioni Limitate per la potenziale congestione del traffico.


![](../../../imm/image-225.png)

- **MAGLIA** -> E' una griglia Bidimensionale dove OGNI NODO è collegato direttamente ad altri nodi, è una topologia costosa da implementare e da gestire. Ha uno schema altamente scalabile e una buona tolleranza ai guasti.


![](../../../imm/image-226.png)

- **DOPPIO TORO** -> E' la versione migliorata della MAGLIA con collegamenti tra i Nodi ai Bordi, prevede una Latenza ridotta e una migliore tolleranza ai guasti.


![](../../../imm/image-227.png)

- **CUBO TRIDIMENSIONALE** -> E' un'estensione della MAGLIA in 3 dimensioni.


![](../../../imm/image-228.png)


- **IPERCUBO** -> E' un'estensione della MAGLIA in più di 3 dimensioni, è ottimo per ridurre la latenza ma è molto costoso.


![](../../../imm/image-229.png)


### Virtualizzazione

La virtualizzazione è una tecnica che consente di ESEGUIRE più sistemi operativi (Guest SO) su una macchina fissa simulando più ambienti isolati (Virtual Machine) con RISORSE PROPRIE.

I principali vantaggi della virtualizzazione sono: 

- <span style="color:rgb(0, 176, 240)">Ottimizzazione Hardware</span> -> Più sistemi su una macchina.
- <span style="color:rgb(0, 176, 240)">Isolamento</span> -> Un guasto su una VM non compromette le altre.
- <span style="color:rgb(0, 176, 240)">Flessibilità</span> -> Facile creazione, Copia e Backup per le VM.
- <span style="color:rgb(0, 176, 240)">Sicurezza</span>: Per via dell' *isolamento*.
- <span style="color:rgb(0, 176, 240)">Risparmio</span>: Sia economico che energetico, si ha meno hardware da acquistare/raffreddare/alimentare.
  

### Hypervisor

L'hypervisor è il SOFTWARE che gestisce le operazioni kernel.

<span style="color:rgb(255, 0, 0)">Tipologie di hypervisor</span>:

- <span style="color:rgb(0, 176, 240)">Hypervisor di tipo 1</span> -> Lavora direttamente sull'hardware senza S.O. intermedio, è un S.O. che ha come unico scopo AVVIARE e GESTIRE le VM.
  Ha prestazioni elevate e un consumo molto basso.
  
- <span style="color:rgb(0, 176, 240)">Hypervisor di tipo 2 </span>-> E' un applicazione software che gira su un S.O. già esistente, è più semplice da installare ma ha prestazioni inferiori e consumo più alto.
  
  
  