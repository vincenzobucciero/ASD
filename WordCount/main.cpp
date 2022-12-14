//
// Created by vincenzo on 14/12/22.
//

/*
Progettare ed implementare un programma che utilizzando una Map, conti il
numero di occorrenze di ogni parola contenuta in un file.
*/

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "CheckerOccorrenze.h"

using namespace std;

int main () {
    CheckerOccorrenze verify("file.txt");
    verify.readFile();
    verify.printMap();

    return 0;
}