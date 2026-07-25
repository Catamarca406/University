# Guida ARM Assembly

> Basata sull'architettura ARM "classica" (32 bit, stile ARMv7/ARM7), quella del libro di Alessandro Simonetta. Pensata per un esame scritto, carta e penna.

---

## 0. Modello di programmazione ARM

- **16 registri general purpose** visibili all'utente: `R0`...`R15`, ciascuno a 32 bit.
- `R13` = **SP** (Stack Pointer)
- `R14` = **LR** (Link Register) — indirizzo di ritorno dalle subroutine
- `R15` = **PC** (Program Counter) — attenzione: è un registro normale, ci si può scrivere direttamente per fare un salto!
- **CPSR** (Current Program Status Register): registro di stato che contiene i **flag**:
    - **N** (Negative): risultato negativo
    - **Z** (Zero): risultato zero
    - **C** (Carry): riporto/prestito
    - **V** (oVerflow): overflow con segno

I flag vengono aggiornati solo se l'istruzione lo richiede esplicitamente (vedi punto 2).

---

## 1. Caratteristica fondamentale: l'esecuzione condizionale

A differenza di molte altre architetture, in ARM **quasi ogni istruzione può essere eseguita condizionatamente**, aggiungendo un suffisso di 2 lettere legato ai flag del CPSR:

|Suffisso|Condizione|Significato|
|---|---|---|
|`EQ`|Z=1|uguale (equal)|
|`NE`|Z=0|diverso|
|`GT`|—|maggiore (signed)|
|`LT`|—|minore (signed)|
|`GE`|—|maggiore o uguale (signed)|
|`LE`|—|minore o uguale (signed)|
|`HI`|—|maggiore (unsigned)|
|`LO`/`CC`|C=0|minore (unsigned)|
|`MI`|N=1|negativo|
|`PL`|N=0|positivo o zero|
|`VS`/`VC`|V=1/0|overflow / no overflow|
|`AL`|sempre|esecuzione sempre (default, si omette)|

Esempi:

```asm
ADDEQ R0, R1, R2   ; esegue ADD solo se Z=1 (cioè se l'ultimo confronto ha dato uguaglianza)
MOVGT R3, #1       ; esegue MOV solo se "maggiore"
BLE   etichetta    ; salta se "minore o uguale" (il caso più comune: sul branch)
```

**Perché è potente**: spesso puoi evitare completamente i salti per if-then semplici, usando solo l'esecuzione condizionale. Questo è tipico delle domande d'esame ARM (a differenza di MIPS/LEGv8).

---

## 2. Istruzioni aritmetiche e logiche (Data Processing)

Formato generale: `OP{cond}{S} Rd, Rn, Operando2`

- `{cond}`: suffisso condizionale (opzionale, vedi sopra)
- `{S}`: se presente, **aggiorna i flag del CPSR**. Es. `ADDS` aggiorna i flag, `ADD` no.
- `Operando2` può essere: un registro, un registro shiftato, o un immediato.

```asm
ADD  R0, R1, R2       ; R0 = R1 + R2   (non tocca i flag)
ADDS R0, R1, R2       ; R0 = R1 + R2   (aggiorna N,Z,C,V)
SUB  R0, R1, R2       ; R0 = R1 - R2
RSB  R0, R1, R2       ; R0 = R2 - R1   (Reverse Subtract, utile per invertire l'ordine)
MUL  R0, R1, R2       ; R0 = R1 * R2

AND  R0, R1, R2       ; AND bit a bit
ORR  R0, R1, R2       ; OR bit a bit
EOR  R0, R1, R2       ; XOR bit a bit
BIC  R0, R1, R2       ; R0 = R1 AND (NOT R2)   ("bit clear")
MVN  R0, R1           ; R0 = NOT R1

MOV  R0, R1           ; R0 = R1
MOV  R0, #10          ; R0 = 10  (immediato)
CMP  R1, R2           ; confronta R1 e R2: calcola R1-R2 e aggiorna SOLO i flag (non salva il risultato)
CMN  R1, R2           ; confronta come R1+R2, aggiorna flag
TST  R1, R2           ; AND bit a bit solo per flag (test dei bit)
```

### Il barrel shifter (Operando2 shiftato) — caratteristica tipica ARM

L'operando2 può essere shiftato "gratis" nella stessa istruzione:

```asm
MOV R0, R1, LSL #2    ; R0 = R1 << 2   (equivale a *4)
MOV R0, R1, LSR #1    ; R0 = R1 >> 1 logico  (equivale a /2 per unsigned)
MOV R0, R1, ASR #1    ; shift aritmetico a destra (preserva il segno, /2 per signed)
MOV R0, R1, ROR #4    ; rotazione a destra

ADD R0, R1, R2, LSL #2  ; R0 = R1 + (R2 << 2)   — utilissimo per indicizzare array!
```

**Trucco esame**: se devi calcolare `array[i]` con elementi da 4 byte, spesso la soluzione elegante è proprio `ADD Rbase_addr, Rbase, Ri, LSL #2` in una sola istruzione, invece di fare lo shift a parte.

---

## 3. Accesso alla memoria (load/store)

ARM è **load/store**: solo `LDR`/`STR` toccano la memoria, tutto il resto lavora sui registri.

```asm
LDR  R0, [R1]          ; R0 = Memoria[R1]           (word, 4 byte)
STR  R0, [R1]          ; Memoria[R1] = R0
LDR  R0, [R1, #4]      ; R0 = Memoria[R1 + 4]       (offset immediato)
LDR  R0, [R1, R2]      ; R0 = Memoria[R1 + R2]      (offset da registro)
LDR  R0, [R1, R2, LSL #2]  ; R0 = Memoria[R1 + R2*4]  (offset scalato — perfetto per array)

LDRB R0, [R1]          ; carica 1 byte (Byte)
LDRH R0, [R1]          ; carica 2 byte (Halfword)
STRB R0, [R1]
STRH R0, [R1]
```

### Modalità di indirizzamento pre/post indicizzato (molto chieste all'esame)

```asm
LDR R0, [R1, #4]!     ; PRE-indexed: R1 = R1+4, poi R0 = Memoria[R1]  (aggiorna R1!)
LDR R0, [R1], #4      ; POST-indexed: R0 = Memoria[R1], poi R1 = R1+4  (aggiorna R1 DOPO)
```

Queste sono ideali per **scorrere un array** senza dover incrementare l'indice a parte:

```asm
; somma tutti gli elementi di un array di N interi
    MOV R0, #0           ; accumulatore = 0
    MOV R2, #0           ; contatore i = 0
LOOP:
    CMP R2, R_N
    BGE FINE
    LDR R3, [R1], #4     ; carica array[i], poi R1 += 4 (post-incremento)
    ADD R0, R0, R3
    ADD R2, R2, #1
    B LOOP
FINE:
```

### LDM / STM — trasferimento multiplo (caratteristica tipica ARM, spesso chiesta)

Permettono di caricare/salvare **più registri in un colpo solo**, utili soprattutto per salvare/ripristinare registri sullo stack:

```asm
STMFD SP!, {R4-R7, LR}   ; salva R4,R5,R6,R7,LR sullo stack (Full Descending), SP aggiornato
LDMFD SP!, {R4-R7, PC}   ; ripristina R4-R7 e "ritorna" caricando PC = valore salvato di LR
```

- `FD` = Full Descending (lo stile stack più comune in ARM: SP punta all'ultimo elemento pieno, la pila cresce verso il basso)
- Altri modi: `IA` (Increment After), `IB` (Increment Before), `DA` (Decrement After), `DB` (Decrement Before) — `FD`/`ED`/`FA`/`EA` sono gli pseudonimi orientati allo stack.

---

## 4. Salti e strutture di controllo

```asm
B    etichetta        ; salto incondizionato
BL   etichetta        ; salto con salvataggio del ritorno in LR (chiamata a subroutine)
BX   R14              ; salto all'indirizzo in R14 cambiando eventualmente stato (usato per tornare)
MOV  PC, LR            ; modo "vecchio stile" per tornare da una subroutine
```

Grazie all'esecuzione condizionale, i confronti si fanno con `CMP` + branch condizionato (`B{cond}`), oppure a volte **senza nessun salto**, usando istruzioni condizionali dirette.

### If-else — due modi

**Modo 1 (con salti, come in altre architetture):**

```c
if (R1 == R2) { R0 = 1; } else { R0 = 2; }
```

```asm
CMP R1, R2
BNE ELSE
MOV R0, #1
B   FINE
ELSE:
    MOV R0, #2
FINE:
```

**Modo 2 (esecuzione condizionale, tipico "stile ARM", spesso preferito nelle soluzioni eleganti):**

```asm
CMP  R1, R2
MOVEQ R0, #1     ; eseguito solo se R1==R2
MOVNE R0, #2     ; eseguito solo se R1!=R2
```

Niente salti! Questo secondo stile è quello che distingue ARM da MIPS/LEGv8 e spesso è ciò che i professori vogliono vedere per dimostrare di aver capito la specificità dell'architettura.

### While

```c
while (R1 != 0) { R0 = R0 + 1; R1 = R1 - 1; }
```

```asm
LOOP:
    CMP R1, #0
    BEQ FINE
    ADD R0, R0, #1
    SUB R1, R1, #1
    B LOOP
FINE:
```

### For (i da 0 a N-1)

```c
for (i = 0; i < N; i++) { array[i] = 0; }
```

```asm
    MOV R2, #0             ; i = 0
LOOP:
    CMP R2, R_N
    BGE FINE
    MOV R3, #0
    STR R3, [R_base, R2, LSL #2]   ; array[i] = 0
    ADD R2, R2, #1
    B LOOP
FINE:
```

---

## 5. Subroutine (chiamate a procedura)

Regole chiave:

1. `BL nome` salta alla subroutine e mette l'indirizzo di ritorno in `LR (R14)`.
2. Per tornare: `MOV PC, LR` oppure `BX LR`.
3. Se la subroutine è **foglia** (non chiama altre subroutine), non serve salvare LR.
4. Se la subroutine **chiama altre subroutine** (non-foglia), deve salvare LR sullo stack prima, perché la BL successiva sovrascrive LR.
5. Convenzione tipica: `R0-R3` per i parametri (e per il valore di ritorno in `R0`), `R4-R11` se usati vanno salvati/ripristinati (callee-saved).

### Procedura foglia

```c
int somma(int a, int b) { return a + b; }
```

```asm
somma:
    ADD R0, R0, R1    ; a in R0, b in R1, risultato in R0
    MOV PC, LR
```

### Procedura non-foglia (con LDM/STM per salvare stato)

```c
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n - 1);
}
```

```asm
fact:
    STMFD SP!, {R4, LR}   ; salvo R4 (userò per tenere n) e LR
    MOV R4, R0             ; R4 = n
    CMP R0, #0
    MOVEQ R0, #1
    BEQ FINE
    SUB R0, R0, #1
    BL  fact               ; chiamata ricorsiva, risultato in R0 = fact(n-1)
    MUL R0, R4, R0          ; R0 = n * fact(n-1)
FINE:
    LDMFD SP!, {R4, PC}    ; ripristino R4 e "ritorno" caricando PC
```

Nota lo schema classico: `STMFD SP!, {..., LR}` all'inizio e `LDMFD SP!, {..., PC}` alla fine — è un pattern che ricorre in quasi tutte le subroutine non-foglia in ARM ed è molto amato dai professori come domanda d'esame.

---

## 6. Riepilogo istruzioni essenziali

|Istruzione|Significato|
|---|---|
|`MOV/MVN`|copia / copia negata|
|`ADD/SUB/RSB/MUL`|aritmetica|
|`AND/ORR/EOR/BIC`|logiche|
|`CMP/CMN/TST`|confronto (solo flag, no risultato salvato)|
|`LSL/LSR/ASR/ROR` (come parte di Operando2)|shift/rotazione "gratis"|
|`LDR/STR` (+`B`/`H` per byte/halfword)|load/store singolo|
|`LDM/STM`|load/store multiplo (blocchi di registri)|
|`B`/`BL`/`BX`|salto / salto con link / salto con cambio stato|
|suffissi `EQ,NE,GT,LT,GE,LE,...`|esecuzione condizionale su QUALSIASI istruzione|
|suffisso `S`|aggiorna i flag del CPSR|

---

## 7. Consigli per lo scritto 

1. **Esercitati sull'esecuzione condizionale**: è la caratteristica che più distingue ARM, ed è probabile che ci siano domande specifiche su come evitare salti usando i suffissi condizionali.
2. **Occhio al barrel shifter** dentro le istruzioni (`ADD R0, R1, R2, LSL #2`): è elegante e spesso richiesto per array.
3. **Pattern standard delle subroutine**: `STMFD SP!, {..., LR}` / `LDMFD SP!, {..., PC}` — impara questo schema a memoria, ricorre quasi sempre.
4. Attenzione alla **differenza tra istruzioni con e senza `S`** (es. `ADD` vs `ADDS`): solo la versione con `S` aggiorna i flag, e i salti condizionati dipendono da quei flag.
5. Fai anche l'esercizio inverso: **assembly → C**, capita spesso.

---
