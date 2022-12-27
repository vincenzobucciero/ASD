//
// created by vincenzo on 26/12/22
//

//IMPLEMENTAZIONE HEAP-SORT

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include <vector>
#define vuoto 10

using namespace std;

template <typename T>
class HeapSort {
    private:
        vector<T> *tree;
        int HeapSize;

        int Parent(int i);
        int Left(int i);
        int Right(int i);

        //implementazione max_heapify
        void maxHeapify(int i);
        void buildMaxHeap();
        void swap(T &A, T &B);
        void inOrderAscii(int i, int spazio);
    public:
        HeapSort(vector<T> *tree);
        HeapSort();
        ~HeapSort();

        void insert(T nodo);
        void heapsort();
        void printTree();
        void printAsciiTree();
};

template <typename T>
HeapSort<T>::HeapSort(vector<T> *tree) {
    this->tree = tree;
    this->HeapSize = tree->size();

    buildMaxHeap();
}

template <typename T>
HeapSort<T>::HeapSort() {
    this->tree = new vector<T>;
    this->HeapSize = 0;
}

template <typename T>
HeapSort<T>::~HeapSort() {
    delete tree;
}

template <typename T>
int HeapSort<T>::Parent(int i) {
    return (i-1)/2;
}
template <typename T>
int HeapSort<T>::Left(int i) {
    return (2*i+1);
}
template <typename T>
int HeapSort<T>::Right(int i) {
    return (2*i+2);
}

template <typename T>
void HeapSort<T>::maxHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int max = i;

    
    if (l < HeapSize && this->tree->at(max) < this->tree->at(l))
        max = l;
    if (r < HeapSize && this->tree->at(max) < this->tree->at(r))
        max = r;
    if (max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }

}

template <typename T>
void HeapSort<T>::buildMaxHeap() {
    for (int i = HeapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void HeapSort<T>::swap(T &A, T &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void HeapSort<T>::insert(T nodo) {
    HeapSize++;
    this->tree->push_back(nodo);
    int i = HeapSize-1;

    while(i != 0 && this->tree->at(Parent(i) < this->tree->at(i))){
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
    }
}

template <typename T>
void HeapSort<T>::heapsort() {
    //buildMaxHeap();
    for(int j = HeapSize-1; j>0; j--)
        swap(this->tree->at(0), this->tree->at(j));
        HeapSize--;
        maxHeapify(0);
}

template <typename T>
void HeapSort<T>::printTree() {
    cout << "\n***HEAP-SORT***" << endl;
    for(int i = 0; i< HeapSize; i++)
        cout << this->tree->at(i) << " ";
}


template <typename T>
void HeapSort<T>::inOrderAscii(int i, int spazio){

    if (i >= HeapSize)
        return;

    spazio += vuoto;

    inOrderAscii(Right(i),spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(Left(i),spazio);
}

template <typename T>
void HeapSort<T>::printAsciiTree(){
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}

#endif //HEAPSORT_H