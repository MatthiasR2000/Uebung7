//
// Created by Matthias Roos on 08.01.25.
//

#include "Uebung7.h"

void printBuch(Buch buch) {
    if (buch.titel == "-1") {
        cout << "Buch mit dem Titel: " << buch.titel << "Nicht vorhanden" << endl;
    }
    else {
        cout << "Titel: " << buch.titel
            << " Autor: " << buch.autor
            << " BuchTyp: " << enumToString(buch.typ)
            << " Preis: " << buch.preis
            << " Anzahl Seiten: " << buch.anzahlSeiten
            << endl;
    }
}

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

void addBuch(Regal& regal, Buch buch) {
    if (regal.anzahlBuecher < 25) {
        regal.buecher[regal.anzahlBuecher++] = buch;
    }
    else {
        cout << "Regal ist leider voll" << endl;
    }
}

void sucheBuch(Regal regal, string titel) {
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].titel == titel) {
            printBuch(regal.buecher[i]);
            return;
        }
    }
    cout << "Buch mit dem Titel: " << titel << " wurde nicht gefunden" << endl;
}

Buch sucheBuch2(Regal regal, string titel) {
    Buch buch;
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].titel == titel) {
            return regal.buecher[i];
        }
    }
    Buch keinBuch{"-1", "-1", ROMAN,-1.0,-1};
    return keinBuch;
}

int anzSeiten(Regal regal, BuchTyp typ) {
    int summeSeiten = 0;
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].typ == typ) {
            summeSeiten += regal.buecher[i].anzahlSeiten;
        }
    }
    return summeSeiten;
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

void changeBook(Regal& regal,Buch buch) {
  string neuerTitel;
  cout << "Geben sie einen neuen Buch Titel an: ";
  cin >> neuerTitel;
    for (int i = 0; i < regal.anzahlBuecher; i++) {
        if (regal.buecher[i].titel == buch.titel) {
            regal.buecher[i].titel = neuerTitel;
        }
    }
    printAll(regal);
}