//
// created by vincenzo on 02/01/23
//

/*
    • Progettare una classe BinarySearchTree che implementi un
        albero binario di ricerca con le seguenti funzioni
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR
        • SUCCESSOR
        • INSERT
        • DELETE
*/

#ifndef ABRNODE_H
#define ABRNODE_H

#include <iostream>
#include <vector>

using namespace std;

/*
    Ogni nodo di un ABR contiene:
        • la chiave (key);
        • il puntatore al PADRE
        • il puntatore al FIGLIO DESTRO
        • il puntatore al FIGLIO SINISTRO
        • Eventuali dati satelliti
*/

template <typename T>
class Node {
    private:
        T key;
        Node<T> *Parent;
        Node<T> *Right;
        Node<T> *Left;
    public:
        Node(T *key, Node<T> *Parent, Node<T> *Right, Node<T> *Left);
        Node(T key);
        ~Node();

        void setKey(T *key) { this->key = key; }
        void setParent(Node<T> *Parent) { this->Parent = Parent; }
        void setRight(Node<T> *Right) { this->Right = Right; }
        void setLeft(Node<T> *Left) { this->Left = Left; }

        T getKey() { return this->key; }
        Node<T> *getParent() { return this->Parent; }
        Node<T> *getRight() { return this->Right; }
        Node<T> *getLeft() { return this->Left; }
};

template <typename T>
Node<T>::Node(T *key, Node<T> *Parent, Node<T> *Right, Node<T> *Left) {
    this->key = key;
    this->Parent = Parent;
    this->Right = Right;
    this->Left = Left;
}

template <typename T>
Node<T>::Node(T key) {
    this->key = key;
    this->Parent = nullptr;
    this->Right = nullptr;
    this->Left = nullptr;
}

template <typename T>
Node<T>::~Node() {
    
}




#endif //ABRNODE_H