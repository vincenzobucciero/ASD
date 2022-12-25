//
// created by vincenzo on 25/12/22
//


/*
    • Progettare ed implementare una algoritmo che, dato un
      Min-Heap ed un valore X, stampi la somma dei valori dei
      nodi minori di X.
    
    • Es.: X=8 -> S=13
*/

#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>

#define vuoto 10;

using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T> *tree;
        int HeapSize;

        int Parent(int i);
        int Left(int i);
        int Right(int i);

        void buildMinHeap();
        void minHeapify(int i);
        void swap(T &A, T &B);
        void inOrderAscii(int i, int spazio);

    public:
        MinHeap(vector<T> *tree);
        MinHeap();
        ~MinHeap();

        void insert(T nodo);
        void print();
        void printAsciiTree();

        double sumValue(int root, double x);
        void sumValue(int root, double x, double &sum);
};

template <typename T>
MinHeap<T>::MinHeap(vector<T> *tree) {
    this->tree = tree;
    this->HeapSize = tree->size();
    buildMinHeap();
}

template <typename T>
MinHeap<T>::MinHeap() {
    this->tree = new vector<T>;
    this->HeapSize = 0;
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete tree;
}

template <typename T>
int MinHeap<T>::Parent(int i) {
    return (i-1)/2;
}
template <typename T>
int MinHeap<T>::Left(int i) {
    return (2*i+1);
}
template <typename T>
int MinHeap<T>::Right(int i) {
    return (2*i+2);
}

template <typename T>
void MinHeap<T>::minHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int max = i;

    if(l < HeapSize && this->tree->at(max) > this->tree->at(l))
        max = l;
    if(r < HeapSize && this->tree->at(max) > this->tree->at(r))
        max = r;
    if(max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        minHeapify(max);
    }
}

template <typename T>
void MinHeap<T>::buildMinHeap() {
    for(int i = HeapSize/2; i >= 0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::swap(T &A, T &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void MinHeap<T>::inOrderAscii(int i, int spazio) {
    if (i >= HeapSize) 
        return;
    spazio += vuoto;

    inOrderAscii(Right(i), spazio);

    cout << endl;

    //DA CORREGGERE CICLO FOR (ERRORE ;)
    for(int i = vuoto; i<spazio; i++)
        cout << " ";
    cout << this->tree->at(i) << endl;

    inOrderAscii(Left(i), spazio);
}

template <typename T>
void MinHeap<T>::insert(T nodo) {
    HeapSize++;
    this->tree->push_back(nodo);
    int i = HeapSize-1;

    while (i != 0 && this->tree->at(Parent(i)) > this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(i));
        i = Parent(i);
    }
}

template <typename T>
void MinHeap<T>::print() {
    cout << "\n***MIN-HEAP***" << endl;
    for (int i = 0; i < HeapSize; i++)
        cout << this->tree->at(i) << " ";
}

template <typename T>
void MinHeap<T>::printAsciiTree() {
    cout << "\n***MIN-HEAP-ASCII***" << endl;
    inOrderAscii(0,0);
}

template <typename T>
double MinHeap<T>::sumValue(int root, double x) {
    if (root >= HeapSize)
        return 0;
    if (this->tree->at(root) < x)
        return this->tree->at(root) + sumValue(Left(root), x) + sumValue(Right(root), x);

    return 0;    
}

template <typename T>
void MinHeap<T>::sumValue(int root, double x, double &sum) {
    //DA SPECIFICARE CHE SE E' UNA FOGLIA, ABBIAMO return IMPLICITO

    //SE MINORE UGUALE DELLA RADICE
    if (x <= this->tree->at(root))
        return;
    
    sum += this->tree->at(root);

    int l = Left(root);
    int r = Right(root);

    if (l < HeapSize && x > this->tree->at(l))
        sumValue(l, x, sum);
    if (r < HeapSize && x > this->tree->at(r))
        sumValue(r, x, sum);
}







#endif

