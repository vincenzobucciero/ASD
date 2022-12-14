//
// Created by vincenzo on 14/12/22.
//

#ifndef ASD_CHECKER_H
#define ASD_CHECKER_H

/*
 * Progettare ed implementare un programma che legga da file una
    configurazione del gioco e verifichi se rappresenta la soluzione, usando un
    contenitore della STL.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Checker {
private:
    ifstream file;
    string nomeF;

    bool soluzione;

    vector<int> numbers;

    void openFile();
    void readNum();
    bool checkSeq();
public:
    Checker(string nomeF);
    ~Checker();

    void Check();
    void getSoluzione();
    void getInfo();
};

Checker::Checker(string nomeF) {
    this->nomeF = nomeF;
    openFile();
}
Checker::~Checker() {
    file.close();
}

void Checker::openFile() {
    file.open(nomeF, ios::in);
    if (!file.is_open())
        cout << "Errore in apertura file.." << endl;
}
void Checker::readNum() {
    int word;
    while (file >> word) //legge documento
        numbers.push_back(word);    //inserisce caratteri nel vector
}
bool Checker::checkSeq() {
    if (numbers.size() != 15)
        return false;
    for (int i = 0; i < numbers.size(); ++i) {
        if (numbers.at(i) != i+1)
            return false;
        return true;
    }
}

void Checker::Check() {
    readNum();
    soluzione = checkSeq();
}
void Checker::getSoluzione() {
    if (soluzione)
        cout << "Questo file contiene soluzione valida" << endl;
    else
        cout << "Soluzione non valida.." << endl;
}
void Checker::getInfo() {
    cout << "Stampo info soluzione tramite ciclo range-for:  " << endl;
    for (auto x: numbers)
        cout << x << " ";
    cout << endl;
}


#endif //ASD_CHECKER_H
