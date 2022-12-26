//
// created by vincenzo on 26/12/22
//

/*
    • Progettare ed implementare una classe che implementi un
        heap k-nario (ogni nodo ha k figli)
*/


//IMPLEMENTATO TRAMITE MAX-HEAP

#ifndef MAXKAPPA_H
#define MAXKAPPA_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxKappa {
    private:
        vector<T> *tree;
        int HeapSize;
        int k;

        int Parent(int i);
        int Left(int i);
        int Right(int i);

        void maxKHeapify(int i);
        void buildMaxKHeap();
        void swap(T &A, T &B);
    public:
        MaxKappa(vector<T> *tree, int k);
        MaxKappa(int k);
        ~MaxKappa();

        void insert(T nodo);
        void printTree();
};

template <typename T>
MaxKappa<T>::MaxKappa(vector<T> *tree, int k) {
    this->tree = tree;
    this->k = k;
    this->HeapSize = tree->size();

    buildMaxKHeap();
}

template <typename T>
MaxKappa<T>::MaxKappa(int k) {
    this->tree = new vector<T>;
    this->HeapSize = 0;
    this->k = k;
}

template <typename T>
MaxKappa<T>::~MaxKappa() {
    delete tree;
}

template <typename T>
int MaxKappa<T>::Parent(int i) {
    return (i-1)/2;
}
template <typename T>
int MaxKappa<T>::Left(int i) {
    return (2*i+1);
}
template <typename T>
int MaxKappa<T>::Right(int i) {
    return (2*i+2);
}

template <typename T>
void MaxKappa<T>::maxKHeapify(int i) {
    
    //NON NORMALE IMPLEMENTAZIONE
    //int l = Left(i);
    //int r = Right(i);

    int idx = i+1;  //indice
    int last = k*idx;   //ultimo figlio
    int first = last-k;     //primo figlio

    int max = i;

    // prendo max tra i figli
    for (int j = last; j > first; j--)
        if (j < HeapSize && this->tree->at(max) < this->tree->at(i))
            max = j;

    if (max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        maxKHeapify(max);
    }

}

template <typename T>
void MaxKappa<T>::buildMaxKHeap() {
    for (int i = HeapSize/2; i >= 0; i++)
        maxKHeapify(i);
}

template <typename T>
void MaxKappa<T>::swap(T &A, T &B) {
    int tmp = A;
    A = B;
    B = tmp;
}

template <typename T>
void MaxKappa<T>::insert(T nodo) {
    HeapSize++;
    this->tree->push_back(nodo);
    int i = HeapSize-1;

    while (i != 0 && this->tree->at(Parent(i)) < this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
    }
}

template <typename T>
void MaxKappa<T>::printTree() {
    cout << "\n***MAX-KAPPA-HEAP***" << endl;
    for (int i = 0; i < HeapSize; i++)
        cout << tree->at(i) << " ";
}





#endif