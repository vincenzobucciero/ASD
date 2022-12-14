//
// Created by vincenzo on 05/12/22.
//

//per gestire input e output su file usare #include <fstream>

#include <fstream>
#include <iostream>

using namespace std;

int main () {
    //OFSTREAM crea un riferimento ad un file su cui scrivere
    //stiamo dichiarando "fileOne.txt.txt" un oggetto della classe ofstream
    ofstream filewrite("fileOne.txt.txt");    //il parametro viene passato al costruttore

    //all'apertura del file, il puntatore memorizza la posizione corrente all'interno di un file
    //all'apertura è all'inizio del file
    filewrite << "Ciao Mondo!!" << endl;
    //.close() chiude il file
    filewrite.close();

    //file non piu accessibile

    return 0;
}
