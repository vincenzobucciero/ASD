//
// created by vincenzo on 22/12/22
//


//test for quicksort with stack

#include "QuickSortStack.h"
#include <iostream>

using namespace std;

int main () {
    int a[] = {8,4,1,3};

    cout << "Array prima sort:  " << endl;
    for (auto x: a) {
        cout << x << " ";
    }

    QuickSort::quicksort(a, 0, 3);

    cout << "\nArray dopo sort:  " << endl;
    for (auto x: a) {
        cout << x << " ";
    }

    return 0;
}