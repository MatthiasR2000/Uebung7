#include <iostream>
#include <string>
using namespace std;
#include "Uebung7.h"

int main() {
    Buch buch1{"Mathe","Galster",BuchTyp::LEHRBUCH,57.0,300};
    Buch buch2{"GET","Winter",BuchTyp::LEHRBUCH,40.0,400};
    Buch buch3{"Info1","Januzaj",BuchTyp::LEHRBUCH,50.0,500};
    Buch buch4{"Physik","Brensing",BuchTyp::LEHRBUCH,45.0,600};
    Buch buch5{"Recht","Goldmann",BuchTyp::LEHRBUCH,60,1000};
    Regal regal;

    addBuch(regal, buch1);
    addBuch(regal, buch2);
    addBuch(regal, buch3);
    addBuch(regal, buch4);
    addBuch(regal, buch5);
    cout << "Suche Buch" << endl;
    sucheBuch(regal, "GET");
    sucheBuch(regal, "MySQL");
    Buch buch = sucheBuch2(regal, "GET");
    Buch buch6 = sucheBuch2(regal, "OracleDB");
    printBuch(buch);
    printBuch(buch6);
    cout << "\nGesamtseitenanzahl: "<< anzSeiten(regal, BuchTyp::LEHRBUCH);
    cout << "\nGesamtwert: " << regalWert(regal) << endl;
    printAll(regal);
    changeBook(regal, buch5);
    return 0;
}