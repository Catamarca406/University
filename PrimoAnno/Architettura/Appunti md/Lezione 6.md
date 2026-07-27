#Architettura 

## Microarchitettura 


Quando parliamo di Microarchitettura, ci troviamo al *Livello 1* 

![336](../../../imm/image-217.png)


Un esempio:
**Microprogramma** contiene una sequenza di *Microistruzioni*:
- Composte da variabili che Descrivono lo stato della macchina.
  
Ciascuna contiene:
- *Codice Operativo* (<span style="color:rgb(0, 176, 240)">OpCode</span>) -> Identifica il tipo di istruzione.
- *Operando* -> Su cui applicare l'istruzione.


### Modello di esecuzione delle istruzioni:

-> **Fetch** (Caricamento in memoria) -> **Decode** (Riconoscimento del Tipo di istruzione) -> **Execute** (Esecuzione) -> Fetch ..... 


### Datapath

Il DATAPATH è la parte della CPU che contiene: ALU, Registri Interni,  I/O.

![|315x561](../../../imm/image-218.png)

- I Registri <span style="color:rgb(0, 176, 240)">MAR</span>, <span style="color:rgb(0, 176, 240)">MDR</span>, <span style="color:rgb(0, 176, 240)">PC</span>, <span style="color:rgb(0, 176, 240)">MBR</span> controllano l'accesso in Memoria.
- Sono presenti <span style="color:rgb(0, 176, 240)">2 Bus</span> : <span style="color:rgb(0, 176, 240)">C</span>, <span style="color:rgb(0, 176, 240)">B</span>.
- Alla base della <span style="color:rgb(0, 176, 240)">ALU</span> c'è lo <span style="color:rgb(0, 176, 240)">Shifter</span>.
- Ci sono <span style="color:rgb(0, 176, 240)">due segnali di controllo</span>: 
	- <span style="color:rgb(0, 176, 240)">Freccia Nera</span>: serve per abilitare la scrittura dal Registro al Bus B.
	- <span style="color:rgb(0, 176, 240)">Freccia Bianca</span>: serve per scrivere il contenuto del Bus C sul Registro.

<span style="color:rgb(255, 0, 0)">ELENCO DEI REGISTRI</span> :

- <span style="color:rgb(0, 176, 240)">MAR</span> -> Memory Address Register.
- <span style="color:rgb(0, 176, 240)">MDR</span> -> Memory Data Register.
- <span style="color:rgb(0, 176, 240)">PC</span> -> Program Counter.
- <span style="color:rgb(0, 176, 240)">MBR</span> -> Memory Byte Register.
- <span style="color:rgb(0, 176, 240)">SP</span> -> Stack Pointer.
- <span style="color:rgb(0, 176, 240)">LV</span> -> Local Variable.
- <span style="color:rgb(0, 176, 240)">CPP</span> -> Constant Pool.
- <span style="color:rgb(0, 176, 240)">TOS</span> -> Top word On the Stack.
- <span style="color:rgb(0, 176, 240)">OPC</span> -> Op Code Register.
- <span style="color:rgb(0, 176, 240)">H</span> -> Holding.

<span style="color:rgb(255, 0, 0)">ALU</span> :

La ALU (Arithmetic Logic Unit) possiede 6 linee di controllo:
- <span style="color:rgb(0, 176, 240)">F0</span> e <span style="color:rgb(0, 176, 240)">F1</span> per selezionare il tipo di funzione.
- <span style="color:rgb(0, 176, 240)">Enx</span> per abilita/annulla il valore della variabile x.
- <span style="color:rgb(0, 176, 240)">INVA</span> inverte la variabile A, utile per la sottrazione.
- <span style="color:rgb(0, 176, 240)">INC</span> incrementa.

Agisce su 2 operandi: 1 dal registro H, 1 dal Bus B.

L'operando B si può spostare in A: 
--> chiamando la funzione che restituisce B e memorizzando il risultato del Bus C in H.

Lo <span style="color:rgb(0, 176, 240)">SHIFTER</span> può far scorrere i bit/byte del risultato verso DX/SX.


<span style="color:rgb(255, 0, 0)">INCREMENTARE UN REGISTRO IN 1 CICLO DI CLOCK</span> :

**Fase 1** : Prendere il valore del Registro sul Bus B.
**Fase 2** : Disattivare A e Incrementare B.
**Fase 3**:  Ignorare lo scorrimento dello shifter.
**Fase 4** : Scrivere il risultato nel registro originario.

### Formato delle microistruzioni (36 bit)

Si compone di: 

- <span style="color:rgb(0, 176, 240)">ADDR</span> -> Indirizzo della successiva microistruzione, 9 bit.
- <span style="color:rgb(0, 176, 240)">JAM</span> -> Determina come selezionare la prossima microistruzione, 3 bit.
- <span style="color:rgb(0, 176, 240)">ALU</span> -> Seleziona le funzioni dell' ALU o dello SHIFTER, 8 bit.
- <span style="color:rgb(0, 176, 240)">C</span> -> Seleziona quali REGISTRI sono scritti dal Bus C, 9 bit.
- <span style="color:rgb(0, 176, 240)">MEM</span> -> Seleziona la funzione in Memoria, 3 bit.
- <span style="color:rgb(0, 176, 240)">B</span> -> Seleziona quale REGISTRO è scritto sul Bus B, 4 bit.


![](../../../imm/image-219.png)


### Microarchitettura Mic-1


![551](../../../imm/image-220.png)

Il **Mic-1** si compone di: 

- **Decoder 4:16** -> Per decodificare il tipo di istruzione in base all' <span style="color:rgb(0, 176, 240)">OpCode</span>.
- **Memoria  di Controllo** 512 * 36 bit -> Per memorizzare le microistruzioni e contenere il microprogramma, ha 2 registri specifici: <span style="color:rgb(0, 176, 240)">MPC</span> per gli indirizzi e <span style="color:rgb(0, 176, 240)">MIR</span> per i dati.
- **Registri del Datapath** -> 


<span style="color:rgb(255, 0, 0)">FUNZIONAMENTO DEL MIC-1</span> 

Bisogna sincronizzare le operazioni in 1 ciclo di clock, che è diviso in *4 intervalli di tempo* con ognuno un compito specifico.

1.  $\Delta W$ -> <span style="color:rgb(0, 176, 240)">FRONTE DI DISCESA</span>: fase inziale in cui la Microistruzione dal MPC viene caricata nel MIR.
2. $\Delta X$ -> I registri caricano i loro dati sul Bus e questi iniziano ad andare verso l' ALU.
3.  $\Delta Y$ -> La ALU esegue l'operazione e lo SHIFTER fa eventuali spostamenti.
4. $\Delta Z$ -> Il RISULTATO viene propagato tra i registri.

Una volta finito il Primo Ciclo di Clock, c'è il <span style="color:rgb(0, 176, 240)">FRONTE DI SALITA</span> (altro ciclo di clock) in cui:
- I risultati sono caricati nei registri e nella memoria.
- L'indirizzo della Microistruzione successiva viene caricato nel MPC.



