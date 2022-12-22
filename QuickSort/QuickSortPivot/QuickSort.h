//
// Created by vincenzo on 22/12/22.
//

#ifndef ASD_QUICKSORT_H
#define ASD_QUICKSORT_H

//IMPLEMENTAZIONE QUICKSORT CON PIVOT

#include <iostream>

using namespace std;

class QuickSort {
private:
    static int Partition(int a[], int left, int right);
    static void swap(int &A, int &B);
public:
    static void quicksort(int a[], int left, int right);
};

int QuickSort::Partition(int *a, int left, int right) {            //VERSIONE HOARE
    int i = left-1;     //i punta a all'elemento prima del primo elemento
    int j = right;      //j punta all'ultimo elemento

    int pivot = a[right];   //dichiaro l'ultimo elemento come pivot

    while (1) {     //ciclo while infinito fin quando non viene eseguito un break
        while (a[++i] < pivot);         //fin quando trova elementi minori del pivot
        while (pivot < a[--j])          //fin quando trova alementi maggiori del pivot
             if (j == left)
                break;
        if (i >= j)
            break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[right]);

    return i;
}

void QuickSort::swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

void QuickSort::quicksort(int *a, int left, int right) {
    if (right <= 1)
        return;
    int i = Partition(a, left, right);
    quicksort(a,left, i-1);
    quicksort(a, i+1, right);
}



#endif //ASD_QUICKSORT_H
