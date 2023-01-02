//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE COUNTING SORT (VERSIONE CORMEN)

#include <iostream>

using namespace std;

class CountingSort {
    public:
        static void countingSort(int *arr, int n);
};

void CountingSort::countingSort(int *arr, int n) {
    int max = arr[0];
    int min = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
        else if(arr[i] < min)
            min = arr[i];
    }
    int lengthC = max-min+1;
    int *c = new int[lengthC];

    for(int i = 0; i < lengthC; i++) {
        c[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        c[arr[i]-min]++;
    }

    int k = 0;
    for(int i = 0; i < lengthC; i++) {
        while(c[i] > 0) {
            arr[k++] = i+min;
            c[i]--;
        }
    }

    delete [] c;
}

