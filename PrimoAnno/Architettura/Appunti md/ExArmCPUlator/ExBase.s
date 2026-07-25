.global _start
_start:
	
	MOV R1,#1;	//Inizializzo il registro R1
	MOV R2, #3;	//Inizializzo il registro R2
	
	ADD R3, R1, R2; // R3 = R1+R2
	
	//----------------------------------------
	
	MOV R4, #15;  //Inizializzo il registro R4
	MOV R5, #10;  //Inizializzo il registro R5
	
	SUB R4,R5;	//R4-R5	
	
	//----------------------------------------
	
	MOV R7, #11;	//Inizializzo il registro R7
	MOV R8, #3;		//Inizializzo il registro R8
	
	MUL R9,R7,R8;	//R9 = R7 * R8
	
	//----------------------------------------
	
	MOV R10, #255	//Inizializzo il registro R10
	MOV R11, #32 	//Inizializzo il registro R11
	
	// Struttura IF 
	CMP R10,R11		//R10 == R11 (?)
	BNE ELSE 
	MOV R0,#255		// then R10+255
	B FINE
	ELSE:			// else 
		MOV R11,R10		// R11 = R10
	FINE:
	
	//----------------------------------------
	
	// Struttura WHILE
	LOOP:		//While
    CMP R1, #0  // Verifico se R1 != 0 
    BEQ FINE	// Se R1 == 0 end
    ADD R0, R0, #1	// R0 = RO + 1
    SUB R1, R1, #1	// R1 = R1 - 1
    B LOOP		// Vado in loop (Branch, salto, in loop)
	FINE:		
	
	