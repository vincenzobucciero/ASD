//
// Created by vincenzo on 14/12/22.
//

#ifndef ASD_CHECKEROCCORRENZE_H
#define ASD_CHECKEROCCORRENZE_H

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class CheckerOccorrenze {
private:
    ifstream file;
    string nomeF;

    map<string, int> amap;

    void openFile();
public:
    CheckerOccorrenze(string nomeF);
    ~CheckerOccorrenze();

    map<string, int> getMap() { return amap; }

    void readFile();
    void printMap();
};

CheckerOccorrenze::CheckerOccorrenze(string nomeF) {
    this->nomeF = nomeF;
    openFile();
}
CheckerOccorrenze::~CheckerOccorrenze() {
    file.close();
}

void CheckerOccorrenze::openFile() {
    file.open(nomeF, ios::in);
    if (!file.is_open())
        cout << "Errore apertura file.." << endl;
}

//LEGGERE FILE DA UNA MAP
void CheckerOccorrenze::readFile() {
    string word;
    //con l'utilizzo di map, possiamo utilizzare degli operatori
    map<string, int>::iterator it;

    while (file >> word) {
        it = amap.find(word);   //find() restituisce un iteratore prendendo in input una chiave
        //se trova la chiave nella map, allora torna l'iteratore chepunta ad esso
        //altrimenti ritorna l'iteratore end()
        if (it == amap.end())
            amap.insert(make_pair(word, 1));
        else
            amap.at(word)++;
    }
}

void CheckerOccorrenze::printMap() {
    map<string, int>::iterator it;
    for (it = amap.begin(); it != amap.end() ; ++it) {
        cout << "map:  " << it->first << " , " << it->second << endl;
    }
}

#endif //ASD_CHECKEROCCORRENZE_H
