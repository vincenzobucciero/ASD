//
// created by vincenzo on 23/12/22
//

#ifndef MAXHEAP_H
#define MAXHEAP_H

/*
    Progettare ed implementare una classe template Max-Heap
    dotata delle seguenti operazioni:
    • Max-Heapify
    • Build-Max-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T> *tree;
        int HeapSize;

        int Parent(int i);
        int Left(int i);
        int Right(int i); 

        void maxHeapify(int i);
        void swap(T &A, T &B);

        void inOrderAscii(int, int);

        void buildMaxHeap();


    public:
        MaxHeap(vector<T> *tree);
        MaxHeap();
        ~MaxHeap();

        void insert(T nodo);
        void print();
        void printAsciiTree();
        void heapSort();
        void printVector();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T> *tree) {
    this->tree = tree;
    this->HeapSize = tree->size();
    buildMaxHeap();
}

template <typename T>
int MaxHeap<T>::Parent(int i) {
    return (i-1)/2;
}
template <typename T>
int MaxHeap<T>::Left(int i) {
    return (2*i)+1;
}
template <typename T>
int MaxHeap<T>::Right(int i) {
    return (2*i)+2;
}


template <typename T>
MaxHeap<T>::MaxHeap() {
    this->tree = new vector<T>;
    this->HeapSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete tree;
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
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
void MaxHeap<T>::swap(T &A, T &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void MaxHeap<T>::buildMaxHeap() {
    for (int i = HeapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::inOrderAscii(int i, int spazio) {
    if (i >= HeapSize) 
        return;
    spazio += vuoto;

    inOrderAscii(Right(i), spazio);

    cout << endl;
    for (int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(Left(i), spazio);
}

template <typename T>
void MaxHeap<T>::insert(T nodo) {
    HeapSize++;
    this->tree->push_back(nodo);
    int i = HeapSize-1;

    while (i != 0 && this->tree->at(Parent(i)) < this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
    }
}

template <typename T>
void MaxHeap<T>::print() {
    cout << "\n***MAX-HEAP***" << endl;
    for (int i = 0; i < HeapSize; i++) 
        cout << this->tree->at(i) << endl;
}

template <typename T>
void MaxHeap<T>::printAsciiTree() {
    cout << "\n***MAX-HEAP-ASCII" << endl;
    inOrderAscii(0,0);
}

template <typename T> 
void MaxHeap<T>::heapSort() {
    for (int i = HeapSize-1; i > 0; i--) {
        swap(this->tree->at(0), this->tree->at(i));
        HeapSize--;
        maxHeapify(0);
    }
}

template <typename T>
void MaxHeap<T>::printVector() {
    cout << "\n***MAX-HEAP-VECTOR***" << endl;
    for (int i = 0; i < this->tree->size(); i++)
        cout << this->tree->at(i) << " ";
    cout << endl;
}



#endif