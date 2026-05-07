#architettura 
# Memoria Secondaria

## Gerarchie di memorie 

La dimensione della memoria è inversamente proporzionale al tempo di accesso e direttamente al costo.

- I **registri** della CPU sono le memorie più piccole, più veloci e più costose.
- I **nastri magnetici** e i **dischi ottici** sono le memorie più lente ma le più economiche e grandi.

![643](5976582202709445941.jpg)

Le tipologie di memorie possono essere classificate attraverso una struttura gerarchica:
- Cima -> Base: Tempo di accesso e costo decrementano, ma cresce la capacità di memorizzazione.


### Dischi Magnetici

Costituiti da: 

- **Disco magnetico** formato da uno o più piatti di alluminio rivestiti con una superficie magnetizzabile che ruota rispetto al centro.
  
- Una **Testina** che si muove avanti / dietro al disco, contiene un solenoide che orienta le particelle di materiale ferroso a seconda della polarità della corrente che attraversa la spirale.
  
- La **Traccia** è una sequenza circolare di bit scritti in una circonferenza del disco, divisa in settori di lunghezza fissa, tra settori adiacenti c'è l'intersector gap.
  Le tracce interne hanno densità > tracce esterne ma stesso contenuto informativo.
	- $\forall$ traccia è presente: 
		1. *Preambolo* che permette la sincronizzazione delle testine prima di inizia la lettura / scrittura.
		2. *Codice di Correzione dell' Errore*  permette di correggere errori multipli
		
- il **Controllore del disco** è una scheda dedicata che pilota il disco, accetta comandi, corregge i dati e altro.


![517|486](Gemini_Generated_Image_cm6itzcm6itzcm6i.png)


### Floppy Disk

Sono stati i primi dischi removibili e più piccoli in termini di quantità di informazione memorizzata.
In un drive per floppy disk la testina tocca la superficie del disco comportando un ritardo di almeno mezzo secondo quando il motore riparte.

### Hard Disk

I dischi rigidi sono dispositivi di memorizzazione dati collegabili *internamente* o *esternamente* al calcolatore.

Tra le categorie più diffuse esistono: 
1. **Magnetici**, più comuni e meccanici.
2. **Stato solido** più costosi ed elettronici.

#### Hard Disk Magnetico

Costituito da una pila di dischi che ruotano intorno allo stesso asse.
L'insieme di **tracce** di una posizione radiale generica è detta **cilindro**.

Le performance di un H.D.M. dipendono da: 

- *Tempo medio nel seek* --> posizionamento della testina nel raggio della traccia ricercata.
  
- *Latenza rotazionale* --> tempo necessario al disco di posizionare il corretto settore sotto la testina (dipende dalla velocità angolare del disco).
  
- *Tempo di trasferimento* --> dipende dalla densità lineare e dalla velocità rotazionale.

![438x312](6010122968123510142.jpg)

In un PC il controller dell'hard disk è su una scheda separata: 

.... inizialmente fu utilizzato: 

- Lo **Standard IDE** (Integrated Drive Electronics), il s.o. legge e scrive dati sul disco inserendo parametri nei registri della CPU e poi invocando il BIOS (Basic I/O System), memorizzato nella ROM (Random Access Memory) interna.

Da IDE -> EIDE:

- Lo **Standard EIDE** (Extended IDE) ha uno schema di indirizzamento aggiuntivo, LBA (Logical Block Addressing), che aumenta la capacità massima e la velocità.
  Hanno due canali per collegare un driver primario e uno secondario
  
Ci furono una serie di evoluzioni... EIDE -> ATA-3 -> ATAPI-4 -> ATAPI-5 -> ATAPI-6 -> ATAPi-7.


### SCSI Disk

**SCSI** (Small Computer System Interface) hanno un'organizzazione simile ai dischi IDE ma necessitano di diverse interfacce e hanno velocità di trasferimento maggiori.

### RAID

E' un insieme di dischi che appare al calcolatore come un unico ed enorme disco virtuale con elevata performance ed affidabilità.

Esistono diversi schemi: RAID 0 -> RAID 5: 


- **RAID 0**:  I dati sono suddivisi in strisce di k settori, memorizzati in dischi con modalità *round-robin* (risorse distribuite in maniera omogenea).
  Lavora bene con richieste di grandi dimensioni, non è un vero RAID poiché non esiste ridondanza (se si rompe un disco si perdono tutti i dati associati ad esso).

![466](6010122968123510175.jpg)



- **RAID 1**: Rispetto a RAID 0 duplica i dischi: 
	- Durante la *scrittura* ogni striscia viene scritta due volte (in parallelo).
	- Durante la *lettura* possono essere utilizzzate tutte le copie distribuendo il carico su più dischi.
  Il ripristino è semplice e veloce.

![6010122968123510179](6010122968123510179.jpg)



- **RAID 2**: Utilizza parole binarie per decomporre le informazioni su vari dischi, se un disco si rompe si può ricostruire una copia facilmente.
  
  ![6010122968123510186](6010122968123510186.jpg)



- **RAID 3**: E' la versione semplificata di RAID 2, viene scritto un bit di parità in un disco di parità $\forall$ parola.
  I dati sono suddivi su più dischi, perciò devono essere sincronizzati, non ci sono garanzie su errori casuali perché un solo bit non è sufficiente.
  Offre un'alta velocità di trasferimento.

![586](6010122968123510187.jpg)



- **RAID4**: Lavora con le strisce e non richiede dischi sincronizzati, si esegue l' EXOR bit a  bit di tutte le strisce ottenendo una striscia di parità.

![586](6010122968123510188.jpg)



- **RAID 5**: Anche RAID 5 lavora con le strisce, distribuendo in modalità round-robin (evitando così il collo di bottiglia) le strisce di parità.
  Se si rompe un disco ripristinarlo è un processo complesso ricostruirlo.
  
  ![569](6012374767937195341.jpg)
  
### SSD

Gli **SSD** (Dischi a Stato Soliido) sono basati su una *memoria flash non volatile*; 
- La capacità di memorizzazione si degrada nel tempo (usura dei transistor).
- Hanno prestazioni eccellenti -> sono velocissimi.
- Hanno un costo elevato.

### CD-ROM 

I **CD-ROM** (Compact Disc-Read Only Memory) sono composti da:

- Del policarbonato su cui è depositato un sottile strato di alluminio riflettente ricoperto da vernice riflettente.
	- Nel substrato del policarbonato ci sono: 
		1. **Pit** --> Depressioni scritte in modo continuo su una spirale che parte dal centro del disco.
		2. *Land* --> Aree non incise.
		   
		   ![image-188](image-188.png)

Per *leggere* un CD-ROM si utilizza un laser a bassa potenza.

Il *formato base* di un CD-ROM codifica: 
- <span style="color:rgb(0, 176, 240)"> 1 Simbolo</span> a <span style="color:rgb(0, 176, 240)">14 bit</span> $\forall$ <span style="color:rgb(0, 176, 240)">byte</span>.
- <span style="color:rgb(0, 176, 240)">42 Simboli</span> per un <span style="color:rgb(0, 176, 240)">frame</span>.
- <span style="color:rgb(0, 176, 240)">98 Frame</span> per un <span style="color:rgb(0, 176, 240)">settore</span>.

![image-187](image-187.png)



### CD-R

I **CD-R** (CD Registrabili) sono simili ai *CD-ROM*, hanno in più uno strato di pigmento che permette di scrivere i pit.
Contengono una scanalatura che guida il laser in fase di scrittura -> quando il laser colpisce il pigmento crea una zona oscura non ripristinabile.

![424x257](image-189.png)



### CD-RW

I **CD-RW** (CD Riscrivibili) al posto del pigmento hanno una lega con due stati stabili:
- *Cristallino*: 
- *Amorfo*:

Il laser utilizza tre intensità diverse: 
1. <span style="color:rgb(255, 0, 0)">Alta</span> -> il raggio scioglie la lega portandola dallo stato cristallino a quello amorfo (pit). Serve per *scrivere*.  
2. <span style="color:rgb(255, 0, 0)">Media</span> -> la lega si scioglie e torna allo stato cristallino (land). Serve per *cancellare*.
3. <span style="color:rgb(255, 0, 0)">Bassa</span> -> si può leggere lo stato del materiale (pit/land) senza alterarlo. Serve per *leggere*.




### DVD 

I **DVD** (Digital Versatile Disk) sono simili ai CD ma più innovativi: 

- <span style="color:rgb(255, 0, 0)">Pit più piccoli</span> -> si hanno molti più bit nella stessa area di superficie.
- <span style="color:rgb(255, 0, 0)">Una spirale più stretta</span> -> diminuendo il *track pitch* la lunghezza totale della traccia disponibile aumenta.
- <span style="color:rgb(255, 0, 0)">Laser rosso</span> -> focalizza il raggio in un punto più piccolo e preciso.
- <span style="color:rgb(255, 0, 0)">Maggiore capacità</span> -> grazie al ridimensionamento dei pit e all'infittimento della spirale 
- <span style="color:rgb(255, 0, 0)">Maggiore Througput </span>(velocità di trasferimento dei dati) -> per via della maggiore densità di bit, ne vengono letti di più.




## Dispositivi interni al Computer

### Scheda Madre

La **Scheda Madre** è la scheda principale che contiene: 
- *CPU*.
- Slot per la *RAM*.
- *Bus* di comunicazione.
- *Connettori* per i *controller* di *dispositivi I/O*.

![421](image-190.png)


### Bus Interno

In un computer un **Bus** è un sistema di comunicazione che collega la *CPU*, la *Memoria* e i *dispositivi* di *I/O*.
E' un insieme di cavi paralleli --> trasmette più bit nella stessa unità di tempo. 

![437](image-191.png)


Un Bus Interno i può suddividere in:

- <span style="color:rgb(255, 0, 0)">Bus Dati</span> (*Bidirezionale*) --> trasmette informazioni tra componenti interne al computer.
  
- <span style="color:rgb(255, 0, 0)">Bus di Controllo</span> (*Bidirezionale*) --> si compone di *segnali di controllo* e *sincronizzazione* per: 
	1. Stabilire chi può trasmettere dati sul *Bus Dati*.
	2. Indicare il tipo di operazione (Read/Write).
	3. La dimensione dei dati trasmessi (Numero di byte).
	4. La richiesta di interruzione.
	
- <span style="color:rgb(255, 0, 0)">Bus Indirizzi</span> (*Unidirezionale*) --> specifica la posizione *fisica* dove i dati vanno letti o scritti.



### Lettura sul Disco

Se un programma vuole leggere un dato dal disco: 

*Programma* --> (fornisce un comando al) --> *Controller del disco* --> (comunica di posizionarsi, con una seek, al) --> *Drive* --> (invia una sequenza di byte al) --> *Controller*.

Il **DMA** (Direct Memory Access) è una tecnica che permette al *controllore* del disco di scrivere dati direttamente in memoria senza far intervenire la CPU. 



### DMA

Come funziona il **DMA** (Direct Memory Access) ? 

--> appena il trasferimento è completato il *controller* invoca un <span style="color:rgb(255, 0, 0)">interrupt</span> che forza la *CPU* a sospendere il programma corrente avviando una procedura speciale  **ISR** (Interrupt Service Routine). 

L' **ISR** ha il compito di: 
1. Verificare la presenza di errori
2. Comunicare al *S.O.* che il trasferimento è terminato.
 
Al termine dell' **ISR**, la CPU riprende il programma che aveva sospeso.

E' presente un chip chiamato **Arbitro del Bus** che stabilisce, in base a delle priorità assegnate, chi può utilizzare il *Bus* (la *CPU* ha priorità maggiore).



### Tipi di Bus

Esistono vari tipi di bus per ottimizzare ogni operazione

- **BUS ISA**  (Industry Standard Architecture) --> E' il bus singolo del primo PC è obsoleto per la capacità di memoria e il # di dispositivi di I/O associabili.
  
- **BUS EISA** (Extended ISA)  --> Successore di *ISA*, aumentò la banda.
  
- **BUS PCI** (Peripheral Component Interconnect) --> Progettato da Intel, è adatto al controllo di dispositivi più veloci. 

- **Computer con Due Bus** --> L'evoluzione dei PC permise di gestire sia periferiche *EISA* che *PCI*.

	1. La *CPU* e la *Memoria* comunicano con un *Bus dedicato* ad alta velocità.
	  
	2. I dispositivi veloci sono connessi al *BUS PCI*, quelli più vecchi al *BUS EISA*.

	 - Due *Bridge* collegano i due bus (punto 2.) e la linea dedicata tra CPU e memoria (punto 1.).

		![541x300](6012374767937195380.jpg)

- **BUS PCIe** --> Evoluzione del *Bus PCI*, è una rete punto-punto con linee seriali tra le periferiche.

	![461](6012374767937195381.jpg)




### Dispositivi di I/O

Le periferiche esterne possono essere divise in tre categorie: 

- **Dispositivi di Input** --> permettono di inserire dati all'interno del computer.
- **Dispositivi di output** --> permettono di fornire dati dal computer.
- **Dispositivi di I/O** --> permettono di inserire ed estrarre dati dal computer.



#### Tastiere

*Pressione di un tasto* --> (genera) --> *Interrupt* --> (stimola) --> *Gestore interrupt* --> (legge) 
--> *Registro Hardware* (ricava il numero associato al tasto premuto).

#### Monitor

- *Schermo LCD* (Liquid Crystal Display) --> Formato da molecole organiche viscose che si muovono come in un liquido ma con struttura simile ad un cristallo.
  L'applicazione di un campo elettrico cambia l'allineamento delle molecole e delle loro proprietà ottiche.
  Hanno uno spessore ridotto.

#### Vram

- *Vram* (Video Ram) --> Risiede in un controller speciale della scheda video.

#### Dispositivi di puntamento

- *Mouse di vari tipi: 

	1. <span style="color:rgb(255, 0, 0)">Meccanico</span> : Una pallina muove due potenziometri, la distanza percorsa viene calcolata tramite il valore delle due resistenze

	2. <span style="color:rgb(255, 0, 0)">Ottico</span> : Un led illumina il fondo ed un fotorivelatore comprende il movimento del dispositivo.

	3. <span style="color:rgb(255, 0, 0)">Opto-Meccanico</span> : Dotato di una pallina che muove due cilindretti che ruotano, attraverso dei fori permettono che la luce passi e di rilevare la distanza percorsa.

Quando il muose si muove su una superficie, un puntatore si muove in corrispondenza sullo schermo --> spedendo al calcolatore una <span style="color:rgb(255, 0, 0)">sequenza di 3 byte </span>(detti *mickey*) che spedisce 1 byte alla volta: 
1. Intero con segno = spostamento x 
2. Intero con segno = spostamento y
3. Indica lo stato corrente dei pulsanti
 
in corrispondenza dell'asse minimo.

