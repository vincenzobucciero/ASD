//
// Created by vincenzo on 05/12/22.
//

#ifndef ASD_CHECKER_H
#define ASD_CHECKER_H

/*
 * Progettare ed implementare una classe che, dati
        – un file Problema.txt contenente diverse istanze del problema (una per ogni riga)
        – un file Soluzione.txt contenente una soluzione per ogni istanza di problema (una per ogni riga)

    • verifichi se ognuna delle soluzione è corretta rispetto al problema e scriva l'esito su un file Esito.txt
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Checker {
private:
    fstream problema;
    fstream soluzione;
    fstream esito;

    bool simbolicorretti(string , string );
    bool numeriusati(string);
    bool logicacorretta(string, string);

    string nomeP, nomeS, nomeE;
    string lineP, lineS;

public:
    Checker(string nomeP, string nomeS, string nomeE);
    ~Checker();

    void check();
};

Checker::Checker(string nomeP, string nomeS, string nomeE) {
    this->nomeP = nomeP;
    this->nomeS = nomeS;
    this->nomeE = nomeE;

    problema.open(nomeP, ios::in);
    if (problema.fail()) cout << "Errore" << endl;
    soluzione.open(nomeS, ios::in);
    if (soluzione.fail()) cout << "Errore" << endl;
    esito.open(nomeE, ios::out);
    if (esito.fail()) cout << "Errore" << endl;
}

Checker::~Checker() {
    problema.close();
    soluzione.close();
    esito.close();
}

bool Checker::simbolicorretti(string lineP, string lineS) {
    for (int i = 0; i < (int)lineS.size(); ++i) {
        if (lineS.at(i) == '<' || lineS.at(i) == '>') {
            soluzione += lineS.at(i);
        }
    }
    if(lineP != soluzione)
        return false;
    return true;
}

void Checker::check() {
    while (getline(problema, lineP) && getline(soluzione, lineS))
}

#endif //ASD_CHECKER_H
