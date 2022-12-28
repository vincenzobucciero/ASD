//
// created by vincenzo on 27/12/22
//


#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_h

//IMPLEMENTAZIONE CODA DI PRIORITA' MASSIMA FACENDO USO DEL MAX-HEAP

/*
    Progettare ed implementare una classe Priority-queue che
    implementi le seguenti operazioni
    • Insert(S,x)
    • Maximum(S) / 
    • Extract-Max(S) / 
    • Increase-priority(S,x,k) /
*/

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/MaxPriorityQueue/MaxHeap.h"
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class MaxPriorityQueue:private MaxHeap<T> {
    public:
        MaxPriorityQueue(vector<T> *tree);
        MaxPriorityQueue();
        virtual ~MaxPriorityQueue();

        //metodo che restituisce il massimo degli elementi
        T maximum();
        //metodo che estrae e restituisce elemento con priorità massima
        T extractMax();
        //metodo che inserisce nella coda di priorità
        void queueInsert(T nodo);
        //metodo che aiuta a ripristainare le proprietà dell'heap
        void increaseKey(int i, T key);

        void printTree();
        void printAsciiTree();
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(vector<T> *tree):MaxHeap<T>(tree) {

}

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue() {

}

template <typename T>
MaxPriorityQueue<T>::~MaxPriorityQueue() {

}

template <typename T>
T MaxPriorityQueue<T>::maximum() {
    return this->getRoot();
}

template <typename T>
T MaxPriorityQueue<T>::extractMax() {
    if(this->getHeapsize() == 0)
        return false;

    T max = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapsize()-1));
    this->setHeapsize(this->getHeapsize()-1);
    this->maxHeapify(0);

    return max;
}

template <typename T>
void MaxPriorityQueue<T>::queueInsert(T key) {
    this->insert(key);
}

template <typename T>
void MaxPriorityQueue<T>::increaseKey(int i, T key) {
    if(key < this->getTree()->at(i))
        return;
    
    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->Parent(i)) < this->getTree()->at(i)) {
        this->swap(this->getTree()->at(this->Parent(i)), this->getTree()->at(i));
        i = this->Parent(i);
    }
}

template <typename T>
void MaxPriorityQueue<T>::printTree() {
    cout << endl;
    cout << "***MAX-HEAP***" << endl;
    for(int i = 0; i< this->getHeapsize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MaxPriorityQueue<T>::printAsciiTree() {
    cout << endl;
    cout << "***MAX-ASCII-HEAP***" << endl;
    this->inOrderAscii(0,0);
}




#endif //MAXPRIORITYQUEUE_H