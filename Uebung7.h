//
// Created by Matthias Roos on 08.01.25.
//
#ifndef UEBUNG7_H
#define UEBUNG7_H

using namespace std;
#include <iostream>
enum BuchTyp {
    LEHRBUCH, ROMAN
};

struct Buch {
    string titel;
    string autor;
    BuchTyp typ;
    float preis;
    int anzahlSeiten;
};

struct Regal {
    Buch buecher[35];
    int anzahlBuecher = 0;
};

void printBuch(Buch buch);
string enumToString(BuchTyp typ);
void addBuch(Regal& regal, Buch buch);
void sucheBuch(Regal regal, string titel);
Buch sucheBuch2(Regal regal, string teil);
int anzSeiten(Regal regal, BuchTyp typ);
float regalWert(Regal regal);
void printAll(Regal regal);
void changeBook(Regal& regal,Buch buch);

#endif //UEBUNG7_H