//
// created by vincenzo on 26/12/22
//

/*
    • Progettare ed implementare una classe che implementi un
        heap k-nario (ogni nodo ha k figli)
*/


#ifndef MINKAPPA_H
#define MINKAPPA_H

//IMPLEMENTATO TRAMITE MIN-HEAP

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MinKappa {
    private:
        vector<T> *tree;
        int HeapSize;
        int k;

        int Parent(int i);
        int Left(int i);
        int Right(int i);

        void minKHeapify(int i);
        void buildMinKHeap();
        void swap(T &A, T &B);
    public:
        MinKappa(vector<T> *tree, int k);
        MinKappa(int k);
        ~MinKappa();

        void insert(T nodo);
        void printTree();
};

template <typename T>
MinKappa<T>::MinKappa(vector<T> *tree, int k) {
    this->tree = tree;
    this->HeapSize = tree->size();
    this->k = k;

    buildMinKHeap();
}

template <typename T>
MinKappa<T>::MinKappa(int k) {
    this->tree = new vector<T>;
    this->HeapSize = 0;
    this->k = k;
}

template <typename T>
MinKappa<T>::~MinKappa() {
    delete tree;
}

template <typename T>
int MinKappa<T>::Parent(int i) {
    return (i-1)/2;
}
template <typename T>
int MinKappa<T>::Left(int i) {
    return (2*i+1);
}
template <typename T>
int MinKappa<T>::Right(int i) {
    return (2*i+2);
}

template <typename T>
void MinKappa<T>::minKHeapify(int i) {
    int idx = i+1;
    int last = k*idx;
    int first = last-k;

    int min = i;

    for (int j = last; j > first; j--) 
        if (j < HeapSize && this->tree->at(min) > this->tree->at(j)) 
            min = j;
    
    
    if (min != i) {
        swap(this->tree->at(i), this->tree->at(min));
        minKHeapify(min);
    }
}

template <typename T>
void MinKappa<T>::buildMinKHeap() {
    for (int i = HeapSize/2; i >= 0; i--) 
        minKHeapify(i);
}

template <typename T>
void MinKappa<T>::swap(T &A, T &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void MinKappa<T>::insert(T nodo) {
    HeapSize++;
    this->tree->push_back(nodo);
    int i = HeapSize-1;

    while (i >= 0 && this->tree->at(Parent(i)) > this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
    }
}

template <typename T>
void MinKappa<T>::printTree() {
    cout << "\n***MIN-KAPPA-HEAP***\n" << endl;
    for (int i = 0; i < HeapSize; i++)
        cout << this->tree->at(i) << " ";
}





#endif //MINKAPPA_H
