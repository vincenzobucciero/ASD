//
// created by vincenzo on 22/12/22
//

#ifndef QUICKSORTVECTOR_H
#define QUICKSORTVECTOR_H

#include <vector>
#include <iostream>

using namespace std;

template <typename T> 
class QuickSortVector {
    private:
        static typename vector<T>::iterator Partition(typename vector<T>::iterator begin, typename vector<T>::iterator end);
        static void swap(T &A, T &B);
    public:
        static void quicksortVector(typename vector<T>::iterator begin, typename vector<T>::iterator end);
};

template <typename T>
typename vector<T>::iterator QuickSortVector<T>::Partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    typename vector<T>::iterator i = begin-1;
    typename vector<T>::iterator j = end;

    T pivot = *end;

    while (1) {
        while (*(++i) < pivot);
        while (pivot < *(--j))
            if (j == begin)
                break;
        if (i >= j)
            break;

        swap(*i, *j);
    }
    swap(*i, *end);

    return i;
}

template <typename T>
void QuickSortVector<T>::swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void QuickSortVector<T>::quicksortVector(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    auto size = distance(begin, end);

    if (size <= 0)
        return;
    typename vector<T>::iterator i = Partition(begin, end);
    quicksortVector(begin, i-1);
    quicksortVector(i+1, end);
}




#endif