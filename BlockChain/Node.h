//
// Created by vincenzo on 09/12/22.
//

//Credit to https://github.com/Attilio-Di-Vicino/Algoritmi-strutture-dati/tree/main/Lezione04

#ifndef ASD_NODE_H
#define ASD_NODE_H

#include "Transazione.h"
#include <iostream>
#include <string>

/*
 * Progettare ed implementare una struttura dati
    LinkedList mediante template ed utilizzarla per
    realizzare una blockchain
 */

//implementazione nodo per la lista

template <typename T>
class Node {
private:
    Node<T>* Next;
    T* obj;
public:
    Node(Node<T>* Next, T* info);
    ~Node();

    void setNext(Node<T>* Next);
    void setObj(T* info);

    Node<T>* getNext();
    T* getObj();
};

template <typename T>
Node<T>::Node(Node<T> *Next, T *info) {
    this->Next = Next;
    this->obj = info;
}
template <typename T>
Node<T>::~Node() {
    delete Next;
    delete obj;
}

template <typename T>
void Node<T>::setNext(Node<T> *Next) {
    this->Next = Next;
}
template <typename T>
void Node<T>::setObj(T *info) {
    this->obj = info;
}

template <typename T>
Node<T> *Node<T>::getNext() {
    return Next;
}
template <typename T>
T *Node<T>::getObj() {
    return this->obj;
}

#endif //ASD_NODE_H
