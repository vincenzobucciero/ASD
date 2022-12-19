//
// Created by vincenzo on 14/12/22.
//

//test for insertion sort con vector

#include "InsertionSortVector.h"
#include <iostream>

using namespace std;

void visuaArray (std::vector<int> a) {
    for (auto x: a) {
        cout << x << " ";
    }
}

int main () {
    vector<int> a = {5,24,11,10,12,20,26};
    cout << "Array prima di ordinamento:  " << endl;
    visuaArray(a);
    cout << "\nArray dopo l'ordinamento:  " << endl;
    InsertionSortVector::insertionSortVector<int>(a.begin(), a.end());
    visuaArray(a);
}