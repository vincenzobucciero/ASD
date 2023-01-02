//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE RADIX SORT

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/RadixSort/RadixSort.h"

using namespace std;

/*
void visualizza(int array[], int n){
    for (int i=0; i<n; i++)
        cout << "Array[" << i << "]: " << array[i] << endl;
}
*/

void visualizzaString(string array[], int n) {
    for(int i = 0; i < n; i++)
        cout << "Array[" << i << "]: " << array[i] << endl;
}

int main () {
    /*
    int array[] = {566,435,123,765,948,686,827,642,761,980};

    cout << "array prima radix sort:  " << endl;
    visualizza(array, 10);

    RadixSort::radixSort(array, 10);

    cout << "array dopo radix sort:  " << endl;
    visualizza(array, 10);
    */

    string array2[] = {"Alba","Logo","Face","Song","Lato","Bistecchiera","Calcio"};

    cout << "array prima radix sort:  " << endl;
    visualizzaString(array2, 7);

    RadixSort::radixSortString(array2, 7);

    cout << "array dopo radix sort:  " << endl;
    visualizzaString(array2, 7);
}