//
// created by vincenzo on 30/12/22
//

//IMPLEMENTAZIONE COUNTING SORT (AUSILIO DEI VECTOR E TEMPLATE)

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class CountingSort {
    public:
        static void countingSort(vector<T> *vec, int n);
};

template <typename T>
void CountingSort<T>::countingSort(vector<T> *vec, int n) {
    int max = vec->at(0);
    int min = vec->at(0);

    for(int i = 1; i < n; i++) {
        if(vec->at(i) > max)
            max = vec->at(i);
        else if(vec->at(i) < min)
            min = vec->at(i);
    }

    int lengthC = max-min+1;
    int *c = new int[lengthC];

    for(int i = 0; i < lengthC; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[vec->at(i)-min]++;

    int k=0;
    for (int i = 0; i < lengthC; i++) {
        while(c[i] > 0) {
            vec->at(k++) = i+min;
            c[i]--;
        }
    }
    delete [] c;
}

#endif //COUNTINGSORT_H