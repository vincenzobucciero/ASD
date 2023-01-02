//
// created by vincenzo on 02/01/23
//

/*
    • Progettare ed implementare un algoritmo che dato in input un
        array di stringhe le ordini in modo che ogni stringa sia una
        sottostringa delle successive

    • Es.: [palmare, re, spalmare, mare]
    
        re
        mare
        palmare
        spalmare
*/

#include <iostream>
#include <vector>
#include <string>

#include "/home/vincenzo/Scrivania/asd/ASD/CountingSort/SubString/Substring.h"

using namespace std;

int main () {
    vector<string> A = {"mare", "spalmare", "re", "palmare"};

    cout << "Vector prima sort:  " << endl;
    CountingSortString::printArray(A);

    CountingSortString::countingSortString(&A);
    
    cout << endl;
    cout << "Vector dopo sort:  " << endl;
    CountingSortString::printArray(A);

    return 0;
}