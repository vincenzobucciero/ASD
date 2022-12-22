//
// created by vincenzo on 22/12/22
//

//IMPLEMENTAZIONE QUICKSORT CON STACK (main)

#ifndef QUICKSORTSTACK_H
#define QUICKSORTSTACK_H

#include "/home/vincenzo/Scrivania/asd/ASD/Template/Stack.h"
#include <iostream>

using namespace std;

class QuickSort {
    private:
        static int Partition(int a[], int left, int right);
        static void swap(int &A, int &B);
    public:
        static void quicksort(int a[], int left, int right);
};

int QuickSort::Partition(int a[], int left, int right) {        //IMPLEMENTAZIONE HOARE
    int i = left-1;
    int j = right;

        int pivot = a[right];   //assegno l'ultimo elemento come pivot

        while (1)
        {
            /* code */
            while (a[++i] < pivot);
            while (pivot < a[--j])
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

void QuickSort::quicksort(int a[], int left, int right) {

    //Creo lo stack
    Stack<int> stack;

    //Inserisci left & right nello stack
    stack.push(left);
    stack.push(right);

    while (!stack.isEmpty()){
        //Estrai left & right dallo stack
        stack.pop(left);
        stack.pop(right);

        int pivot = Partition(a, left, right);

        if (pivot < left){
            /* code */
            stack.push(left);
            stack.push(pivot-1);
        } else if (pivot > right) {
            /* code */
            stack.push(pivot+1);
            stack.push(right);
        }
    }
}




#endif //QUICKSORTSTACK_H