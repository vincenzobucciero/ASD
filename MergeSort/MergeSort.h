//
// Created by vincenzo on 16/12/22.
//

#ifndef ASD_MERGESORT_H
#define ASD_MERGESORT_H


#include <iostream>
#include <vector>

using namespace std;

//Implementazione Merge a due vie

class MergeSort {
private:
    static void MergeDueVie(int c[], int a[], int N, int b[], int M);
    static void MergeAstratto(int a[], int left, int med, int right);
public:
    static void MergeSortIte(int a[], int left, int right);
};


//IMPLEMENTAZIONE MERGE A DUE VIE
/*
void MergeSort::MergeDueVie(int *c, int *a, int N, int *b, int M) {
    for (int i=0, j=0, k=0; k < N+M; k++) {
        if (i == N) { c[k] = b[j++];
            continue;
        }
        if (j == M) { c[k] = a[i++];
            continue;
        }
        c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
    }
}
 */

//IMPLEMENTAZIONE MERGE ASTRATTO SUL POSTO
void MergeSort::MergeAstratto(int *a, int left, int med, int right) {
    int aux[right-left+1];
    int i, j;
    for (i = med+1; i > left; i--)
        aux[i-1] = a[i-1];
    for (j = med; j < right; j++)
        aux[right+med-j] = a[j+1];
    for (int k = left; k <= right ; k++)
        if (aux[j] < aux[i])
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}



void MergeSort::MergeSortIte(int *a, int left, int right) {
    if (left < right) {
        int med = (left+right)/2;
        MergeSortIte(a,left,med);
        MergeSortIte(a,med+1, right);
        //int tot_elesx = med-left+1;
        //int tot_eledx = right-med;
        //int dim_out = right-left+1;

        //alloco vettore
        //int *out = new int[dim_out];

        //MergeDueVie(out, a+left, tot_elesx, a+(med+1), tot_eledx);
        MergeAstratto(a, left, med, right);
    }
}


#endif //ASD_MERGESORT_H
