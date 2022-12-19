//
// Created by vincenzo on 14/12/22.
//

//test for insertionSort

#include "InsertionSort.h"
#include <iostream>

using namespace std;

void visuaArray(int a[],int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main () {
    int a[] = {5,24,11,10,12,20,26};
    cout << "Array prima di ordinamento:  " << endl;
    visuaArray(a,7);
    cout << "\nArray dopo l'ordinamento:  " << endl;
    InsertionSort::insertionSort(a,6);
    visuaArray(a,7);

    return 0;
}
