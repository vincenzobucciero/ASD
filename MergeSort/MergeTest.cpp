//
// Created by vincenzo on 16/12/22.
//

//test for mergesort

#include "MergeSort.h"

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
    MergeSort::MergeSortIte(elementi, 0, tot_elem-1);

    for (int indice = 0; indice < tot_elem; indice++)
        cout << "Elemento [" << indice << "] =  " << elementi[indice] << endl;
    delete [] elementi;

    return 0;
}
