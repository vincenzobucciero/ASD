//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE COUNTING SORT (VERSIONE CORMEN)

//class test

#include <iostream>
#include "/home/vincenzo/Scrivania/asd/ASD/CountingSort/CountingSortCormen/CountingSort.h"

using namespace std;

int main () {
    int numvar = 8;
    int a[] = {100,20,40,20,12,120,220,240};

    CountingSort::countingSort(a, numvar);

    for(int i = 0; i< numvar; i++)
        cout << a[i] << " ";
    cout << endl;
}
