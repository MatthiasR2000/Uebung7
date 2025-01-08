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
    Buch buecher[25];
    int anzahlBuecher = 0;
};

void printBuch(const Buch& buch);
string enumToString(BuchTyp typ);
void addBuch(Regal& regal, Buch buch);
void sucheBuch(const Regal& regal, const string& titel);
Buch sucheBuch2(const Regal& regal, const string& titel);
int anzSeiten(const Regal& regal, BuchTyp typ);
float regalWert(const Regal& regal);
void printAll(const Regal& regal);
void changeBook(Regal& regal, const Buch& buch);


#endif //UEBUNG7_H