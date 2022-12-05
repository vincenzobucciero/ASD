//
// Created by vincenzo on 05/12/22.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    string str;
    fstream ioFile;

    ioFile.open("file1.txt", ios::in | ios::out);
    ioFile << "Ciao Mondo Grande!!";
    //posizione iniziale del file -> ioFile.seekg(ios::beg)
    ioFile.seekg(5);        //puntatore 5 posizioni avanti
    ioFile >> str;
    cout << str << endl;
    ioFile.close();

    return 0;
}
