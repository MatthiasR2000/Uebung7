#include <iostream>
#include <string>
using namespace std;

enum BuchTyp { ROMAN, LEHRBUCH };

struct Buch {
    string titel;
    string autor;
    BuchTyp typ;
    float preis;
    int anzahlSeiten;
};

struct Regal {
    Buch buecher[25];
    int anzahlBuecher = 0;
};

void printBuch(Buch buch);
void buchHinzufuegen(Regal &regal, Buch buch);
void sucheBuch(Regal regal, string titel);
void sucheBuch2(const Regal &regal, const string &titel);
int anzSeiten(Regal regal, BuchTyp typ);
float regalWert(Regal regal);
void printAll(Regal regal);
string enumToString(BuchTyp typ);



int main() {
    // Erstellen von 5 Büchern
    Buch buch1{"Mathe", "Galster", LEHRBUCH, 10.0, 100};
    Buch buch2{"GET", "Winter", LEHRBUCH, 20.0, 200};
    Buch buch3{"Info", "Januzaj", LEHRBUCH, 30.0, 300};
    Buch buch4{"Recht", "Goldmann", ROMAN, 40.0, 400};
    Buch buch5{"Physik", "Schnell", LEHRBUCH, 50.0, 500};
    Regal regal1; //Standard Konstruktor

    buchHinzufuegen(regal1, buch1);
    buchHinzufuegen(regal1, buch2);
    buchHinzufuegen(regal1, buch3);
    buchHinzufuegen(regal1, buch4);
    buchHinzufuegen(regal1, buch5);

    cout << "Alle Bücher im Regal:" << endl;
    printAll(regal1);

    cout << "\nSuche nach Buch mit Titel 'Info':" << endl;
    sucheBuch(regal1, "Info");

    cout << "\nGesamtanzahl der Seiten aller Lehrbücher: " << anzSeiten(regal1, LEHRBUCH) << endl;
    cout << "Gesamtwert des Regals: " << regalWert(regal1) << " Euro" << endl;

    return 0;
}

void printBuch(Buch buch) {
    cout << "Titel: " << buch.titel
         << ", Autor: " << buch.autor
         << ", BuchTyp: " << enumToString(buch.typ)
         << ", Preis: " << buch.preis
         << ", Anzahl Seiten: " << buch.anzahlSeiten << endl;
}


void buchHinzufuegen(Regal &regal, Buch buch) {
    if (regal.anzahlBuecher < 25) {
        regal.buecher[regal.anzahlBuecher++] = buch;
    } else {
        cout << "Das Regal ist voll" << endl;
    }
}


void sucheBuch(Regal regal, string titel) {
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].titel == titel) {
            printBuch(regal.buecher[i]);
            return;//Ohne will er irgendwie nicht???
        }
    }
    cout << "Das Buch mit dem Titel: " << titel << " wurde nicht gefunden." << endl;
}

void sucheBuch2(const Regal &regal, const string &titel) {
    bool gefunden = false;

    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].titel == titel) {
            printBuch(regal.buecher[i]);
            gefunden = true;
        }
    }

    if (!gefunden) {
        cout << "Das Buch mit dem Titel: " << titel << " wurde nicht gefunden." << endl;
    }
}

int anzSeiten(Regal regal, BuchTyp typ) {
    int seitenSumme = 0;
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].typ == typ) {
            seitenSumme += regal.buecher[i].anzahlSeiten;
        }
    }
    return seitenSumme;
}

float regalWert(Regal regal) {
    float gesamtWert = 0.0;
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        gesamtWert += regal.buecher[i].preis;
    }
    return gesamtWert;
}


void printAll(Regal regal) {
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        printBuch(regal.buecher[i]);
    }
}

// Ändert den enum wert zu string um sonst gibt er 0 1 2 3 usw aus
string enumToString(BuchTyp typ) {
    switch (typ) {
        case ROMAN:
            return "Roman";
        case LEHRBUCH:
            return "Lehrbuch";
        default:
            return "Unbekannt";
    }
}
