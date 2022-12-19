//
// Created by vincenzo on 19/12/22.
//


//test for recursive merge

#include "MergeRecursive.h"
#include <iostream>

using namespace std;

int main() {
    int tot_elem;

    cout << "Inserisci numero elementi:  " ;
    cin >> tot_elem;

    int *elementi = new int[tot_elem];
    for (int i = 0; i < tot_elem; ++i) {
        cout << "Inserisci elemento " << i << ":  ";
        cin >> elementi[i];
    }

    MergeRecursive::MergeRec(elementi,0,tot_elem-1);

    for (int indice = 0; indice < tot_elem; indice++)
        cout << "Elemento [" << indice << "] =  " << elementi[indice] << endl;
    delete [] elementi;

    return 0;
}