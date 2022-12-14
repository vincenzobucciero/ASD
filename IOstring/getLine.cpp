//
// Created by vincenzo on 05/12/22.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
    char line[80];
    fstream ioFile;

    ioFile.open("fileOne.txt.txt", ios::in | ios::out);
    //controllo se l'apertura del file è avvenuta con successo
    if(ioFile.fail())
        cout<< "Il file non è stato aperto con successo " <<endl;
    ioFile << "Ciao Gente!";
    ioFile.seekg(ios::beg);
    //metodo getline consente la lettura per linea. Legge dalla posizione coorente al piu n caratteri
    //fermandosi al primo carattere EOF, endline o delimitatore delim
    ioFile.getline(line, 80);
    cout << line << endl;

    ioFile.close();

    return 0;
}