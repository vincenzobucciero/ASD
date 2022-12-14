//
// Created by vincenzo on 14/12/22.
//

#ifndef ASD_BUBBLE_H
#define ASD_BUBBLE_H

#include <iostream>

using namespace std;

class Bubble {
private:
    static int cont;
    static void compswap(int &A, int &B);
    static void swap(int &A, int &B);
public:
    static void bubble(int a[], int l, int r);
    static int getCont() { return cont; }
};

int Bubble::cont = 0;

void Bubble::compswap(int &A, int &B) {
    if (B < A)
        swap(A, B);
}
void Bubble::swap(int &A, int &B) {
    int temp = A;
    A = B;
    B = temp;
    //Incremento contatore per gli scambi
    cont++;
}

//implementazione bubbleSort
void Bubble::bubble(int *a, int l, int r) {
    for (int i = l; i < r; ++i) {
        for (int j = r; j > i; --j) {
            compswap(a[j-1], a[j]);
        }
    }
}

#endif //ASD_BUBBLE_H


