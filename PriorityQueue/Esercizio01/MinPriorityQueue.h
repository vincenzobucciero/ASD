//
// created by vincenzo on 29/12/22
//

/*
    • Data una sequenza di interi (rappresentata da un array),
      trovare il k-esimo elemento più grande per ogni i=0..N-1.
        • seq=[10, 3, 21, 1, -1, 45, 8, 12, 78]
        • k=2
        • i=1 k-max=3
        • i=2 k-max=10
        • i=3 k-max=10
        • ...
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/Esercizio01/MinHeap.h"

using namespace std;

template <typename T>
class MinPriorityQueue:private MinHeap<T> {
    public:
        MinPriorityQueue(vector<T> *tree);
        MinPriorityQueue();
        virtual ~MinPriorityQueue();

        T minimum();
        T extractMin();

        void queueInsert(T nodo);
        void decreaseKey(int i, T key);

        void printTree();
        void printAsciiTree();
};

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue(vector<T> *tree):MinHeap<T>(tree) {

}

template <typename T>
MinPriorityQueue<T>::MinPriorityQueue() {

}

template <typename T>
MinPriorityQueue<T>::~MinPriorityQueue() {

}

template <typename T>
T MinPriorityQueue<T>::minimum() {
    return this->getRoot();
}

template <typename T>
T MinPriorityQueue<T>::extractMin() {
    if(this->getHeapsize() == 0)
        return false;
    T min = this->getRoot();
    this->swap(this->getTree()->at(0), this->getTree()->at(this->getHeapsize()-1));
    this->setHeapsize(this->getHeapsize()-1);
    this->minHeapify(0);

    return min;
}

template <typename T>
void MinPriorityQueue<T>::queueInsert(T nodo) {
    this->insert(nodo);
}

template <typename T>
void MinPriorityQueue<T>::decreaseKey(int i, T key) {
    if (key > this->getTree()->at(i))
        return;
    this->setTree(i, key);

    while(i > 0 && this->getTree()->at(this->Parent(i)) > this->getTree()->at(i))
        this->swap(this->getTree()->at(this->Parent(i)), this->getTree()->at(i));
        i = this->Parent(i);
}

template <typename T>
void MinPriorityQueue<T>::printTree() {
    cout << endl;
    cout << "***MIN-HEAP***" << endl;
    for(int i = 0; i < this->getHeapsize(); i++)
        cout << this->getTree()->at(i) << " ";
}

template <typename T>
void MinPriorityQueue<T>::printAsciiTree() {
    cout << endl;
    cout << "***MIN-ASCII-HEAP***" << endl;

    this->inOrderAscii(0,0);
}