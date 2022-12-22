//
// Created by vincenzo on 22/12/22.
//

//test for quicksort

#include "QuickSort.h"
#include <iostream>

using namespace std;

int main() {

    int *elementi = new int[];
    for (int i = 0; i < 7; ++i) {
        cout << "Inserisci elemento " << i << ":  ";
        cin >> elementi[i];
    }

    QuickSort::quicksort(elementi, 0, 6);

    for (int indice = 0; indice < 7; indice++)
        cout << "Elemento [" << indice << "] =  " << elementi[indice] << endl;
    delete [] elementi;

    return 0;


}
