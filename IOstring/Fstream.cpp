//
// Created by vincenzo on 05/12/22.
//

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main () {
    string filename = "file1.txt";
    string out = "nuovo";
    //la classe fstream viene usata quando non si sa se accedere al file in lettura o in scrittura (viene specificato dopo)
    //fstream è un riferimento generico ad un file e che ne deve essere specificata l'apertura
    fstream optfile;

    /*
    optfile.open(filename.c_str(), ios::in );
    char ch;
    optfile.get(ch);
    optfile.close();
    */
    char ch;
    optfile.open(filename.c_str(), ios::in | ios::out);
    optfile << out << " " << ch << endl;
    optfile.close();
    return 0;
}