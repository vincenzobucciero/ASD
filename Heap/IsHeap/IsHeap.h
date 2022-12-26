//
// created by vincenzo on 25/12/22
//

/*
    • Progettare ed implementare un algoritmo ricorsivo che dato
       un array verifichi se rappresenta un heap binario
*/

#ifndef ISHEAP_H
#define ISHEAP_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class IsHeap {
    private:
        vector<T> *tree;
        static bool isMaxHeap(vector<T> tree, int HeapSize, int i);
        static bool isMinHeap(vector<T> tree, int HeapSize, int i);
    public:
        void isHeap(vector<T> tree, int HeapSize, int i);
};

template <typename T>
bool IsHeap<T>::isMaxHeap(vector<T> tree, int HeapSize, int i) {
    if (i > HeapSize/2)
        return true;

    int l = 2*i+1;
    int r = 2*i+2;

    if ( (l < HeapSize && tree.at(i) < tree.at(l) ) )
        return false;
    if ( (r < HeapSize && tree.at(i) < tree.at(r) ) )
        return false;

    return isMaxHeap(tree, HeapSize, l) && isMaxHeap(tree, HeapSize, r);
}

template <typename T>
bool IsHeap<T>::isMinHeap(vector<T> tree, int HeapSize, int i) {
    if (i > HeapSize/2)
        return true;

    int l = 2*i+1;
    int r = 2*i+2;

    if (l < HeapSize && tree.at(i) > tree.at(l))
        return false;
    if (r < HeapSize && tree.at(i) > tree.at(r))
        return false;

    return isMinHeap(tree, HeapSize, l) && isMinHeap(tree, HeapSize, r);
}

template <typename T>
void IsHeap<T>::isHeap(vector<T> A, int HeapSize, int i) {
    if (isMinHeap(A, HeapSize, i) && !isMaxHeap(A, HeapSize, i))
        cout << endl << "***E' UN MIN-HEAP***" << endl;
    else if(!isMinHeap(A, HeapSize, i) && isMaxHeap(A, HeapSize, i))
        cout<<endl<<"***E' un Max Heap!!***"<<endl;
    else 
        cout<<endl<<"***Non e' niente***"<<endl;
}
#endif