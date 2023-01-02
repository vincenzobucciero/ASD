//
// created by vincenzo on 02/01/2023
//

#ifndef BUCKETSORT_H
#define BUCKETSORT_H

/*
    • Bucket sort o bin sort è un algoritmo di ordinamento il cui
        funzionamento consiste nel suddividere un array in un numero
        finito di buckets
    • Ciascun bucket è ordinato individualmente o utilizzando un
        algoritmo di ordinamento differente od applicando
        ricorsivamente il bucket sort
    • La sua complessità media è Q(n)
    • Il funzionamento del Bucket sort è il seguente:
        1. Definisce un array di "buckets" inizialmente vuoti
        2. Mette ogni elemento dell’array nel suo bucket
        3. Ordina ogni bucket non-vuoto
        4. Sposta gli elementi dai buckets all’array originale
*/

//IMPLEMENTAZIONE BUCKET SORT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class BucketSort {
    public:
        static void bucketSort(vector<T> arr, int n);
};

template <typename T>
void BucketSort<T>::bucketSort(vector<T> arr, int n) {
    vector<T> b[n];
    //metti elementi nei rispettivi bucket
    for(int i = 0; i < n; i++) {
        int bi = n*arr[i];
        b[bi].push_back(arr[i]);
    }
    //ordina bucket singolarmente
    for(int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end());
    
    //concateno i diversi bucket
    int idx = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr[idx++] = b[i][j];
}






#endif //BUCKETSORT_H