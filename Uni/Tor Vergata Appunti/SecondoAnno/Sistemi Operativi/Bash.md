#sistemi_operativi
# Intro
- Bash Shell
- I/O redirection (pipes, etc)
- Navigating the file
- Processes and job control
- Editors
- Hello world in C


Tecnica del dividi et impera nel s.o.
	visto che everything is a file allora tutto si può incastrare con tutto


Pipe  = pseudofile, mi da la possibilità di scrivere (in coda, ha byte che si accodano) e leggere (con fifo) ha un buffer

Esempio:
numero di nomi di battesimo diversi: 
	cut --> pipe --> sort --> pipe --> uniq --> pipe --> wc


### Comandi: 

- cat (fa visualizzare i file)
- cut (prende la 3a colonna)
- diff (compara due file, utilizzato in git per verificare le modifiche)
- grep (seleziona tutti i sottinsiemi di righe che rispettano determinati criteri)
	Esempio:
	Verificare il numero di persone con nome Marco
		cut --> pipe --> cut --> grep(Marco) --> wc - L
			se facessi uniq poi wc avrei come risultato 1, ho cancellato i duplicati di Marco
- head (prende le prime k-righe di un file)
- less (permette di leggere un file, mandarlo a schermo e scorrerlo)
- od (dumpa i file in vari formati)
- sed (modifica il file)
- sort (ordina i file)
- split (divide i file)
- tail (prende le ultime righe del file)
- tr (permette di effettuare il replace di un solo carattere)
- uniq (filtraa le duplicazioni in una linea)
- tar (prende un insieme di file e li accoda in un file binario con un intestazione che ricorda dove comincia uno e finisce un altro)
- wc (conta: linea, parola e numero di caratteri)


Applicazioni C- compilate, ogni app. ha uno standard input, output, error e posso utilizzarle reindirizzando le pipe

### Shell 
programma che interpreta i comandi e li gira al s.o. tramite chiamate di sistema
 Linux supporta due shell : TCSH e Bash
 Bash = "Bourne- again Shell"   *Steve Bourne creatore della prima shell

Variabili nell'ambiente bash: 
-  printenv (fa vedere tutte le variabili)


grep "Danilo" - w prende tutte le cose meno che quella che inserisco, è simile ad un not grep



23/10/25

## the linux file system

tutti i file del s.o. sono organizzati a cartelle con criterio fisso e ricorrente.

Tutti nodi rispondono ad un nodo radice 
	cartelle 			
		-boot
		-user (dati a disposizione delle utenze, dove abbiamo local e share)
		-opt (tutte le app a disposizione di tutti gli utenti)

Comandi essenziali per navigare: 
	- pwd        print working directory 
	- ls            list files
	- cd           change directory

' * ' è una wild card, mi fa vedere tutto 


Manipolare file e cartelle

Link simbolici

Cosa succede se cancello un file? Cancello il suo hardlink, non viene cancellato dal disco

softlink punta all'hardlink

Cercare un file
	find, può avere 
		find . name my-file.txt
		find ~ name bu -type d
		find ~ name '* .txt'



28/10/25

background 
foreground

codice: 
seq 27 -1 1 (va da 27 a 1 decrementando di 1)
random %3 (restituisce un numero casuale da 1-3)

con la & mando in background, facendomi vedere la mia bash

3 modalità per poter interagire con questi processi: 
	Ho eseguito ma ad un certo punto vorrei poterlo bloccare
		ctrl C lo termina
		ctrl Z lo sospende



Comando screen 
Apre un'applicazione che da la sensazione di aver aperto una nuova Bash

screen -r 
ctrl -d per terminare
Se volessi aprire un'altra Bash riutilizzo screen


Comando nohup (no hang up)
Permette di far continuare un processo nonostante il terminale sia chiuso
Si utilizza per applicazioni che durano tanto, gira fino a che non si fa kill

Quando utilizzare screen vs nohup


Il modello di un processo: 
	Ogni processo ha un proprio flusso di esecuzione
	Tutti i processi progrediscono ma solo uno è attivo in un dato momento
	
Processi concorrenti:
- Processi multipli sono reciprocamente indipendenti
- Hanno bisogno di mezzi espliciti per interagire tra loro
- CpU assegnata a turno a diversi processo
- Il s.o. non offre garanzie di tempistiche

Gerarchie di processi
S.O crea solo un processo di init 
	nei moderni s.o init avvia kthread, un processo che gestisce i thread
I sottoprocessi sono creati in modo indipendente:
	Processo padre può creare un processo figlio

Creazione di Processo:
	Inizializzazione di sistema (init ())
	Esecuzione di chiamata di sistema per la creazione di un processo da parte di un processo in esecuzione (fork ())

Termine di un Processo: 
- Uscita normale (volontario)
- Uscita per errore (volontario)
- Errore fatale (involontario)
- Ucciso da un altro processo (involontario)


Process Management:
- Fork() crea un nuovo processo
- exect: esegue un nuovo processo
- exit: causa la terminazione volontaria del processo
- kill: invia un segnale a un processo (o a un gruppo)


Gli stati di un processo
1) Running, in esecuzione, utilizza effettivamente la CPU in quel momento
2) Ready, pronto, eseguibile temporaneamente fermato per consentire l'esecuzione di un altro processo  
3) Blocked, bloccato, non può essere eseguito fino a quando non si verifica un evento esterno

Informazioni associate ad un processo

Signal(s) e Interrupt(s) 
Segnali
Interrupt, tipo hardware