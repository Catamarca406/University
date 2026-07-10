- Intro Oracle
- Intro AI
- Workshop tecnologie Oracle (framework AI, Oracle cloud)


### AI 

- Reti neurali --> composte da addizioni,sottrazioni,moltiplicazioni, operazioni matriciali e derivate. 

- Large Language Model (LLM)  --> rete neurale con miliardi di parametri che si aggiornano continuamente.

*Calcola la probabilità* di trovare una problema conoscendo il contesto delle precedenti.

*Self-Attention* : un elefante rosa cerca di entrare dentro una macchina ma è troppo .... grande. L' AI riconosce come rispondere grazie a moltissimi calcoli probabilistici utilizzando moltiplicazioni e addizioni utilizzando una forte quantità di potenza computazionale attraverso le GPU.

Regola del $softmax(QK^T)V$ 

Addestramento degli algoritmi attraverso tutto internet -> Problemi matematici , logici ecc. 
I modelli non sanno come sfruttare i dati aziendali (per questo dobbiamo vedere come fare, grande oracle).

Il modello "parla per parlare", si addestra attraverso le proprie risposte fallimentari e non grazie a moltissimi dati in iput.

*Frontier Models* --> Sistemi di AI avanzati e generici, superano la capacità dei modelli oggi più diffusi.
*Agents* --> Componente software autonomo, agiscono e automatizzano i workflows. Può richiamare tool-esterni per svolgere azioni che lui non può eseguire.


### Workshop

L'anatomia dell' Agente Applicativo per gli utenti finali: 
1. Conversazione
2. Interpreta le richieste dell'utente
3. Pianifica 
4. Decide quale tool utilizzare
5. Genera una risposta
6. Chiede un'approvazione "umana"


**Modelli OCI e API** 

Come interagire con il modello e cosa richiedere dal cloud per effettuare una prima chiamata.
Prima di passare a scrivere codice bisogna vedere cosa serve. 

Oracle preleva gli LLM di altri provider e li installa sui client

Le risposte dei modelli varia molto spesso attraverso dei parametri : 
- Temperatura 

Obiettivo Hackathon: Response API --> API compatibili con OpenAI

1. Creo un progetto (modelli non hanno memoria).
2. Attivo memoria breve termine e compattazione della memoria (per avere un prompt veloce e poco costosa).
3. Abilitare la memoria a lungo termine. 
4. API key.
5. Vector Store (embedding, dati trasformati in vettori per fare una ricerca (tecnica matematica) ).

>[!code] 
>response = client.responses.create{
model = "openai.gpt-oss-120b",
input = "What is 2x2"
}

Chiamo il tool MCP

