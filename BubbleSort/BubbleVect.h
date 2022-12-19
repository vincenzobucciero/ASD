//
// Created by vincenzo on 14/12/22.
//

#ifndef ASD_BUBBLEVECT_H
#define ASD_BUBBLEVECT_H

#include <vector>
#include <iostream>

using namespace std;
//implementazione bubblesort con vector


class BubbleVect {
private:
    template<typename T> static void compwsap(T &A, T &B);
    template<typename T> static void swap(T &A, T &B);
public:
    template<typename T> static void bubblevect(typename vector<T>::iterator, typename vector<T>::iterator);
};

template <typename T>
void BubbleVect::compwsap(T &A, T &B) {
    if (B < A)
        swap(A, B);
}

template <typename T>
void BubbleVect::swap(T &A, T &B) {
    T temp = A;
        A = B;
        B = temp;
}

template <typename T>
void BubbleVect::bubblevect(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;

    for (i = begin; i != end; ++i) {
        for (j = end; j != i; --j) {
            compwsap(*(j-1), *j);
        }
    }
}

#endif //ASD_BUBBLEVECT_H
