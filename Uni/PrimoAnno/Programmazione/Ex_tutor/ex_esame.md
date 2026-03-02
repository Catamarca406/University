# Traccia 2: Gestione Classifiche Torneo

In un torneo di scacchi internazionale, i risultati vengono registrati in un unico blocco di testo non strutturato. È necessario normalizzare questi dati, calcolare i punteggi corretti e generare una classifica che rispetti i criteri di spareggio tecnico.

Dovete scrivere una funzione Python che riceva una stringa multi-riga contenente i match, e che risolva le seguenti richieste:

1. **Normalizzazione Stringhe:** Elaborare la stringa per rimuovere eventuali spazi bianchi in eccesso all'inizio o alla fine dei nomi e uniformare i nomi dei giocatori (es. tutti in *Title Case*).
2. **Elaborazione Punteggi:** Utilizzare un dizionario per accumulare i punti di ogni partecipante (1 punto per la vittoria, 0.5 per la patta, 0 per la sconfitta).
3. **Identificativi Univoci:** Per ogni giocatore presente nel dizionario, generare un codice ID composto dalle prime tre lettere del nome in maiuscolo seguite dalla lunghezza totale del nome completo (es: "Magnus Carlsen" -> "MAG14").
4. **Criteri di Classifica:** Producete una lista di record (tuple) ordinata secondo i seguenti criteri gerarchici:
    - Punteggio totale decrescente.
    - In caso di parità, lunghezza del nome del giocatore (dal più corto al più lungo).
    - In caso di ulteriore parità, ordine alfabetico del codice ID.

5. **Podio:** Stampare a video solo i primi tre classificati con il relativo ID e punteggio.

**Esempio di input** 

Le stringhe multi-riga in input sono espresse nel seguente formato:

`"Bianco: [Nome Giocatore] vs Nero: [Nome Giocatore] | Risultato: [R]"`

Dove `[R]` può essere `1-0` (vince il bianco), `0-1` (vince il nero) o `0.5-0.5` (patta).

**Esempio di output richiesto:**

`1. CAR (Magnus Carlsen): 4.5 punti 2. NAK (Hikaru Nakamura): 4.0 punti`
