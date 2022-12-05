//
// Created by vincenzo on 05/12/22.
//

#include <fstream>
#include <iostream>

using namespace std;

int main () {
    //ifstream crea un riferimento ad un file da cui leggere
    ifstream fileread("file1.txt"); //viene dichiarato un oggetto della classe ifstream
    char ch;
    //file1.txt viene passato come parametro
    while (fileread.get(ch))
        cout << ch;
    cout << endl;
    fileread.close();

    return 0;
}
