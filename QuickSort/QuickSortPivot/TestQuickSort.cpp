//
// Created by vincenzo on 22/12/22.
//

//test for quicksort

#include "QuickSort.h"
#include <iostream>

using namespace std;

int main() {

    int a[4] = {7,5,4,9};

    cout << "Array prima sort:  " << endl;

    for (auto x : a){
        cout << x << " ";
    }

    QuickSort::quicksort(a,0,3);

    cout << "\nArray dopo sort:  " << endl;

    for (auto x : a){
        cout << x << " ";
    }

    return 0;


}
