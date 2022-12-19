//
// Created by vincenzo on 14/12/22.
//

#ifndef ASD_INSERTIONSORT_H
#define ASD_INSERTIONSORT_H


//Algoritmo di ordinamento utile per ordinare piccole quantità di elementi

class InsertionSort {
    //Ogni elemento dal secondo all’ ultimo viene estratto
    //dal mazzo e confrontato con tutti i precedenti che
    //slittano in avanti se sono più grandi
public:
    static void insertionSort(int a[], int n);
};

void InsertionSort::insertionSort(int a[], int n) {
    int key;
    int i;

    for (int j = 0; j < n; j++) {
        key = a[j];
        i = j-1;
        while (i > 0 && key < a[i]) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

#endif //ASD_INSERTIONSORT_H
