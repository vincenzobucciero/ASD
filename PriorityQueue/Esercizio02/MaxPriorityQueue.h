//
// created by vincenzo on 30/12/22
//

/*
    • Dato un array di n elementi, trovare il massimo numero di
        elementi distinti dopo aver rimosso k elementi (k<=n)
*/

//ELIMINARE I NUMERI CHE SI RIPETONO PIU VOLTE
//EX. A = [5,4,4,3,4,6,2,1,2]  => PER K = 2  => A = [5,3,4,6,2,1,2]

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/Esercizio02/MaxHeap.h"

using namespace std;

template <typename T>
class MaxPriorityQueue:private MaxHeap<T> {
    public:
        MaxPriorityQueue(vector<T> *tree);
        MaxPriorityQueue();
        virtual ~MaxPriorityQueue();

        T maximum();
        T extractMax();

        void queueInsert(T nodo);
        void increaseKey(int i, T key);
        void decreaseKey(int i, T key);

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
void MaxPriorityQueue<T>::queueInsert(T nodo) {
    this->insert(nodo);
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
    cout << "****MAX-HEAP****" << endl;
    for(int i = 0; i < this->getHeapsize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MaxPriorityQueue<T>::printAsciiTree() {
    cout << endl;
    cout << "****MAX-ASCII-HEAP****" << endl;

    this->inOrderAscii(0,0);
}

template <typename T>
void MaxPriorityQueue<T>::decreaseKey(int i, T key){

    if (key > this->getTree()->at(i))
        return;

    this->setTree(i,key);
    this->maxHeapify(i);
}