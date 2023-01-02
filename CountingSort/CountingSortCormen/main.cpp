//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE COUNTING SORT (VERSIONE CORMEN)

//class test

#include <iostream>
#include "/home/vincenzo/Scrivania/asd/ASD/CountingSort/CountingSortCormen/CountingSort.h"

using namespace std;

int main () {
    int  numvar;

    cout << "Inserisci numero elementi vettore:  ";
    cin >> numvar;

    int *a = new int[numvar];

    for(int j = 0; j < numvar; j++) {
        cout << "Elemento [" << j << "]:  " ;
        cin >> a[j];
    }

    CountingSort::countingSort(a, numvar);

    cout << "Vettore ordinato:  " << endl;
    for(int idx = 0; idx < numvar; idx++) {
        cout << "Elemento [" << idx << "] =  " << a[idx] << endl;
    }

    return 0;
}
