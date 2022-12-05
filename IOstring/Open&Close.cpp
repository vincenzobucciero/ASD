//
// Created by vincenzo on 05/12/22.
//

#include <fstream>
#include <iostream>

using namespace std;

int main () {
    string filename;
    ifstream fileread;
    cout << "Inserisci nome file:  ";
    cin >> filename;

    fileread.open(filename.c_str());    //uso metodo c_str()
    char ch;

    while (fileread.get(ch))    //legge da file
        cout << ch;
    cout << endl;
    fileread.close();

    return 0;
}
