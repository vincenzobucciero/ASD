//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE COUNTING SORT (VERSIONE CORMEN)

#include <iostream>

using namespace std;

class CountingSort {
    public:
        static void countingSort(int array[], int n);
};

void CountingSort::countingSort(int array[], int n) {
    int max = array[0];
    int min = array[0];

    for(int i = 1; i < n; i++) {
        if(array[i] > max)
            max = array[i];
        else if(array[i] < min)
            min = array[i];
    }

    int lengthC = max-min+1;
    int c[lengthC];

    for(int i = 0; i < lengthC; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[array[i]-min]++;
    for(int i = 1; i < lengthC; i++)
        c[i] += c[i-1];

    int b[n];
    for(int i = n-1; i>=0; i--) {
        b[c[array[i]-min]-1] = array[i];
        c[array[i]-min]--;
    }

    for(int i = 0; i < n; i++)
        array[i] = b[i];
}
