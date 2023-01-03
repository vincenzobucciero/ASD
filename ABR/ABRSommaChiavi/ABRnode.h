//
// created by vincenzo on 03/01/23
//

/*
    Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi comprese tra il valore m ed il valore M, con m<M
*/

#ifndef ABRNODE_H
#define ABRNODE_H

#include <iostream>
#include <vector>

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