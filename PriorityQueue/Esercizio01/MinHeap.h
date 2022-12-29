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

#define vuoto 5

using namespace std;

template <typename T>
class MinHeap {
    private:
        vector<T> *tree;
        int Heapsize;

        int Left(int i) { return (2*i+1); }
        int Right(int i) { return (2*i+2); }

        void buildMinHeap();
    protected:
        int Parent(int i) { return (i-1)/2; }

        void minHeapify(int i);
        void swap(T &a, T &b);
        void inOrderAscii(int i, int spazio);

        T getRoot() { return this->tree->at(0); }

        void setHeapsize(int Heapsize) { this->Heapsize = Heapsize; }
        int getHeapsize() { return Heapsize; }

        void setTree(int i, T key) { this->tree->at(i) = key;  }
        vector<T> *getTree() { return this->tree; }
    public:
        MinHeap(vector<T> *tree);
        MinHeap();
        ~MinHeap();

        void insert(T nodo);
        void printTree();
        void printTreeAscii();
};

template <typename T>
MinHeap<T>::MinHeap(vector<T> *tree) {
    this->tree = tree;
    this->Heapsize = tree->size();

    buildMinHeap();
}

template <typename T>
MinHeap<T>::MinHeap() {
    this->tree = new vector<T>;
    this->Heapsize = 0;
}

template <typename T>
MinHeap<T>::~MinHeap() {
    delete tree;
}

template <typename T>
void MinHeap<T>::swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
void MinHeap<T>::minHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int min = i;

    if (l < Heapsize && this->tree->at(min) < this->tree->at(l))
        min = l;
    if (r < Heapsize && this->tree->at(min) < this->tree->at(r))
        min = r;
    if (min != i) {
        swap(this->tree->at(i), this->tree->at(min));
        minHeapify(min);
    }
}

template <typename T>
void MinHeap<T>::buildMinHeap() {
    for(int i = Heapsize/2; i >= 0; i--)
        minHeapify(i);
}

template <typename T>
void MinHeap<T>::insert(T nodo) {
    Heapsize++;
    this->tree->push_back(nodo);
    int i = Heapsize-1;

    while(i != 0 && this->tree->at(Parent(i)) > this->tree->at(i))
        swap(this->tree->at(i), this->tree->at(Parent(i)));
        i = Parent(i);
}

template <typename T>
void MinHeap<T>::inOrderAscii(int i, int spazio) {
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
void MinHeap<T>::printTree() {
    cout << endl;
    cout << "***MIN-HEAP***" << endl;
    for(int i = 0; i < Heapsize; i++)
        cout << this->tree->at(i) << " ";
}

template <typename T>
void MinHeap<T>::printTreeAscii() {
    cout << endl;
    cout << "***MIN-ASCII-HEAP***" << endl;

    inOrderAscii(0,0);
}
