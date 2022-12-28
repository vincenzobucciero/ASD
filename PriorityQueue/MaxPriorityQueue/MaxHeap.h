//
// created by vincenzo on 27/12/22
//

//IMPLEMENTAZIONE MAX-HEAP PER CODA DI PRIORITA' MASSIMA

/*
    Progettare ed implementare una classe Priority-queue che
    implementi le seguenti operazioni
    • Insert(S,x)
    • Maximum(S) / 
    • Extract-Max(S) / 
    • Increase-priority(S,x,k) /
*/

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T> *tree;
        int Heapsize;
        
        int Left(int i) { return (2*i+1); }
        int Right(int i) { return (2*i+2); }
        void buildMaxHeap();

    protected:
        int Parent(int i) { return (i-1)/2; }

        T getRoot() { return this->tree->at(0); }

        void setTree(int i, T key) { this->tree->at(i) = key; }
        vector<T> *getTree() { return this->tree; }
        void setHeapsize(int Heapsize) { this->Heapsize = Heapsize; }
        int getHeapsize() { return this->Heapsize; }

        void maxHeapify(int i);
        void swap(T &A, T &B);
        void inOrderAscii(int i, int spazio);
    public:
        MaxHeap(vector<T> *tree);
        MaxHeap();
        ~MaxHeap();

        void insert(T nodo);
        void printTree();
        void printAsciiTree();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T> *tree) {
    this->tree = tree;
    this->Heapsize = tree->size();
    buildMaxHeap();
}

template <typename T>
MaxHeap<T>::MaxHeap() {
    this->tree = new vector<T>;
    this->Heapsize = 0;
}

template <class T>
MaxHeap<T>::~MaxHeap() {
    delete tree;
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int max = i;

    if(l < Heapsize && this->tree->at(max) < this->tree->at(l))
        max = l;
    if(r < Heapsize && this->tree->at(max) < this->tree->at(r))
        max = r;
    if(max != i) { 
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }
}

template <typename T>
void MaxHeap<T>::swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void MaxHeap<T>::inOrderAscii(int i, int spazio) {
    if(i >= Heapsize)
        return;

    spazio += vuoto;

    inOrderAscii(Right(i), spazio);

    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(Left(i), spazio);
}

template <typename T>
void MaxHeap<T>::buildMaxHeap() {
    for(int i = Heapsize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::insert(T nodo) {
    Heapsize++;
    this->tree->push_back(nodo);
    int i = Heapsize-1;

    while (i != 0 && this->tree->at(Parent(i)) < this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
    }
}

template <typename T>
void MaxHeap<T>::printTree() {
    cout << endl;
    cout << "***PRINT-TREE***" << endl;
    for(int i = 0; i < Heapsize; i++)
        cout << tree->at(i) << " ";
}

template <typename T>
void MaxHeap<T>::printAsciiTree() {
    cout << endl << "***Max Ascii Heap***" << endl;
    inOrderAscii(0,0);
}


#endif //MAXHEAP_H