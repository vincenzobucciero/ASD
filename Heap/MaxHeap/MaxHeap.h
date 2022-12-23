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

using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T> tree;
        int HeapSize;

        int Parent(int i);
        int Left(int i);
        int Right(int i); 

        void maxHeapify(int i);
        void swap(T &A, T &B);

        void setHeapSize(int HeapSize);
        int getHeapSize();

        vector<T> getTree();
    public:
        MaxHeap(vector<T> t);

        void buildMaxHeapify();
        void insert(T nodo);
        void printArray();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T> t) {
    tree = t;
    HeapSize = t.size();
    buildMaxHeapify();
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
void MaxHeap<T>::maxHeapify(int i) {
    int max = i;
    int l = Left(i);
    int r = Right(i);

    if (l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if (r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    if (max != i) {
        swap(tree.at(i), tree.at(max));
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
void MaxHeap<T>::setHeapSize(int heapsize) {
    HeapSize = heapsize;
}
template <typename T>
int MaxHeap<T>::getHeapSize() {
    return HeapSize;
}

template <typename T>
vector<T> MaxHeap<T>::getTree() {
    return tree;
}

template <typename T>
void MaxHeap<T>::buildMaxHeapify() {
    setHeapSize((int)getTree().size());
    for (int j = (getHeapSize()/2)-1; j >= 0; j--)
        maxHeapify(j);
}

template <typename T>
void MaxHeap<T>::insert(T nodo) {
    setHeapSize(getHeapSize()+1);
    tree.push_back(nodo);

    int i = getHeapSize()-1;
    while (i > 0 && getTree().at(Parent(i)) < nodo)
    {
        /* code */
        swap(tree.at(Parent(i)), tree.at(i));
        i = Parent(i);
    }
}

template <typename T>
void MaxHeap<T>::printArray() {
    cout << endl << "**Alberello***" << endl;
    for (int i = 0; i < tree.size(); i++)
        cout << tree.at(i) << " ";
    cout << endl << endl;
}





#endif