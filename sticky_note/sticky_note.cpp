// sticky_note.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class note 
{
private: string titolo;
private: string testo;
private: string categoria;

public : note(string titolo, string testo, string categoria) {
    this -> titolo = titolo;
    this->testo = testo;
    this->categoria = categoria;
}

public: void ModificaTitolo(string NewTitolo) {
    this->titolo = NewTitolo;
}
public: void ModificaTesto(string NewTesto) {
    this->testo = NewTesto;
}

public: string GetTitolo() {
    return this->titolo;
}
public: string GetTesto() {
    return this->testo;
}
public: string GetCategoria() {
    return this->categoria;
}

public : int CompareTo(note other)
{
          int ret = -1;
          if (titolo < other.GetTitolo())
              ret = -1;
          else if (titolo > other.GetTitolo())
              ret = 1;
          else if (titolo == other.GetTitolo())
              ret = 0;
          return ret;
}
};


list<note> lista;
int contatore = 0;

void Refresh() {
    system("cls");
    cout << "Scegliere una delle seguenti opzioni per continuare\n";
    cout << "Digitare ed inviare 1 se si vuole aggiungere una sticky note\n";
    cout << "Digitare ed inviare 2 se si vuole vedere tutte le sticky note (per titolo)\n";
    cout << "Digitare ed inviare 3 se si vuole vedere tutte le sticky note (in modo completo)\n";
    cout << "Digitare ed inviare 4 se si vuole eliminare una sticky note (ricerca per titolo)\n";
    cout << "Digitare ed inviare 5 se si vuole vedere quante sticky note si sono create\n";
    cout << "Digitare ed inviare 6 se si vuole cercare una sticky note in base alla categoria\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
}

void Aggiungi() {
    Refresh();
    string titolo, testo, categoria;
    cout << "Inserire il titolo della sticky note ed inviare\n";
    getline(cin >> ws, titolo);
    cout << "Inserire il testo della sticky note ed inviare\n";
    getline(cin >> ws, testo);
    cout << "Inserire la categoria della sticky note ed inviare\n";
    getline(cin >> ws, categoria);
    note nota1(titolo, testo, categoria);
    lista.push_back(nota1);
    contatore++;
}

void Stampa() {
    if (lista.empty()) {
        cout << "Non sono ancora state create sticky note\n";
        return;
    }
    cout << "Le sticky note che sono state create sono:\n";
    list<note> copia = lista;
    for (int i = 0; i < contatore;i++) {
        string titolo = copia.front().GetTitolo();         
        copia.pop_front();
        cout << "- Titolo: " << titolo << "\n";
    }
}

void StampaCompleto() {
    if (lista.empty()) {
        cout << "Non sono ancora state create sticky note\n";
        return;
    }
    cout << "Le sticky note che sono state create sono:\n";
    list<note> copia = lista;
    for (int i = 0; i < contatore; i++) {
        string titolo = copia.front().GetTitolo();
        string testo = copia.front().GetTesto();
        string categoria = copia.front().GetCategoria();
        copia.pop_front();
        cout << "- Titolo: " << titolo << "\n";
        cout << "  Testo: " << testo << "\n";
        cout << "  Categoria: :" << categoria << "\n";
    }
}

void Elimina() {
    if (lista.empty()) {
        cout << "Non sono ancora state create sticky note, di conseguenza non se ne possono cancellare\n";
        return;
    }
    cout << "Definire titolo della sticky note da eliminare\n";
    string nonlovoglio;
    cin >> nonlovoglio;
    list<note> tmp;
    for (int i = 0; i < contatore; i++) {

        note tempo = lista.front();
        lista.pop_front();
        tmp.push_back(tempo);
        
        if (tempo.GetTitolo() == nonlovoglio) {
            string ricordo=tempo.GetTitolo();
            tmp.pop_front();
            contatore--;
            cout << "La sticky note " << ricordo << " e' stata cancellata.\n";
            for (int y = 0; y < i;y++) {
                note scambia = tmp.front();
                tmp.pop_front();
                lista.push_back(scambia);
            }
            return;
        }      
    }
    for (int t = 0; t < contatore; t++) {
        note scambia = tmp.front();
        tmp.pop_front();
        lista.push_back(scambia);
    }
    cout << "Non sono stati trovati elementi con quel titolo\n";
}

void Categorie() {
    if (lista.empty()) {
        cout << "Non sono ancora state create sticky note\n";
        return;
    }

    cout << "Definire Categoria da mostrare\n";
    string speciale;
    cin >> speciale;
    list<note> tmp;
    list<note> copia = lista;

    for (int i = 0; i < contatore; i++) {

        note tempo = copia.front();
        copia.pop_front();

        if (tempo.GetCategoria() == speciale) {
            tmp.push_back(tempo);
        }
    }

    if (tmp.empty()) {
        cout << "Non sono stati trovati elementi con quel titolo\n";
    }
    else {
        cout << "Le sticky note della categoria " << speciale << " sono:\n";
        for (int j = 0; j < tmp.size(); j++) {
            cout << "- " << tmp.front().GetTitolo() << "\n";
        }
    }
}

int main()
{
    cout << "Scegliere una delle seguenti opzioni per continuare\n";
    cout << "Digitare ed inviare 1 se si vuole aggiungere una sticky note\n";
    cout << "Digitare ed inviare 2 se si vuole vedere tutte le sticky note (per titolo)\n";
    cout << "Digitare ed inviare 3 se si vuole vedere tutte le sticky note (in modo completo)\n";
    cout << "Digitare ed inviare 4 se si vuole eliminare una sticky note (ricerca per titolo)\n";
    cout << "Digitare ed inviare 5 se si vuole vedere quante sticky note si sono create\n";
    cout << "Digitare ed inviare 6 se si vuole cercare una sticky note in base alla categoria\n";
    cout << "--------------------------------------------------------------------------------------------------\n";

    while (0 < 1)
    {
        string scelta;
        cin >> scelta;

        if (scelta != "0" && scelta != "1" && scelta != "2" && scelta != "3" && scelta != "4" && scelta != "5") {
            Refresh();
            cout << "Carattere non supportato, sceglierne un'altro";
        }

        int argomento = stoi(scelta);

        switch (argomento)
        {
        case 1:
            // aggiunta sticky note
            cout << "Creazione sticky note\n";
            Aggiungi();
            Refresh();
            break;
        case 2:
            // Stampa degli elementi in base al titolo
            cout << "Sticky note esistenti (titolo):\n";
            Refresh();
            Stampa();
            break;
        case 3:
            // Stampa completa degli elementi
            Refresh();
            StampaCompleto();
            break;
        case 4:
            // Eliminazione di un elemento in base al titolo
            Refresh();
            Elimina();
            break;
        case 5:
            //conteggio sticky note
            Refresh();
            cout << "Il numero di sticky note attualmente esistenti e': " << lista.size();
            break;
        case 6:
            //categoria
            Refresh();
            Categorie();
            break;
        default:
            // terminazione
            return 0;
        }
        cout << "Scrivi un numero per una nuova azione...\n";
    }
}

// Per eseguire il programma: CTRL+F5 oppure Debug > Avvia senza eseguire debug
// Per eseguire il debug del programma: F5 oppure Debug > Avvia debug

// Suggerimenti per iniziare: 
//   1. Usare la finestra Esplora soluzioni per aggiungere/gestire i file
//   2. Usare la finestra Team Explorer per connettersi al controllo del codice sorgente
//   3. Usare la finestra di output per visualizzare l'output di compilazione e altri messaggi
//   4. Usare la finestra Elenco errori per visualizzare gli errori
//   5. Passare a Progetto > Aggiungi nuovo elemento per creare nuovi file di codice oppure a Progetto > Aggiungi elemento esistente per aggiungere file di codice esistenti al progetto
//   6. Per aprire di nuovo questo progetto in futuro, passare a File > Apri > Progetto e selezionare il file con estensione sln
