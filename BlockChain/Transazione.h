//
// Created by vincenzo on 09/12/22.
//

//Credit to https://github.com/Attilio-Di-Vicino/Algoritmi-strutture-dati/tree/main/Lezione04

#ifndef ASD_TRANSAZIONE_H
#define ASD_TRANSAZIONE_H

/*
 * Una transazione è costituita da un indirizzo
    FROM, un indirizzo TO ed un valore intero QT.
 */

#include <iostream>
#include <string>

using namespace std;

class Transazione {
private:
    string from;
    string to;
    float qt;
public:
    Transazione(string from, string to, float qt);
    ~Transazione();

    void setFrom(string from);
    void setTo(string to);
    void setQt(float qt);

    string getFrom();
    string getTo();
    float getQt();

    void infoTx();
};

Transazione::Transazione(string from, string to, float qt) {
    this->from = from;
    this->to = to;
    this->qt = qt;
}
Transazione::~Transazione() {

}

void Transazione::setFrom(string from) {
    this->from = from;
}
void Transazione::setTo(string to) {
    this->to = to;
}
void Transazione::setQt(float qt) {
    this->qt = qt;
}

string Transazione::getFrom() {
    return from;
}
string Transazione::getTo() {
    return to;
}
float Transazione::getQt() {
    return qt;
}

void Transazione::infoTx() {
    cout << endl;
    cout << "From:  " << from << endl;
    cout << "To:  " << to << endl;
    cout << "Qt:  " << qt << endl;

}

#endif //ASD_TRANSAZIONE_H
