//
// Created by vincenzo on 09/12/22.
//

//Credit to https://github.com/Attilio-Di-Vicino/Algoritmi-strutture-dati/tree/main/Lezione04

#ifndef ASD_LINKEDLIST_H
#define ASD_LINKEDLIST_H

#include "Transazione.h"
#include "Node.h"
#include <iostream>
#include <string>

/*
 * Progettare ed implementare una struttura dati
    LinkedList mediante template ed utilizzarla per
    realizzare una blockchain
 */

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* last;

    void insHead(T* newnodo);
    void insLast(T* newnodo);
public:
    LinkedList();
    ~LinkedList();

    void setHead(Node<T>* head) {
        this->head = head;
    }
    void setLast(Node<T>* last) {
        this->last = last;
    }

    Node<T>* getHead() {
        return this->head;
    }
    Node<T>* getLast() {
        return this->last;
    }

    void insNode(Node<T>* last, T* newnodo);
};

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = head;
    this->last = last;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (this->head != nullptr) {
        auto* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

template<typename T>
void LinkedList<T>::insHead(T *newnodo) {
    Node<T>* node = new Node<T>(nullptr, newnodo);
    head = node;
    last = head;
}
template<typename T>
void LinkedList<T>::insLast(T *newnodo) {
    Node<T>* node = new Node<T>(nullptr, newnodo);
    last->setNext(node);
    last = node;
}

template<typename T>
void LinkedList<T>::insNode(Node<T> *last, T *newnodo) {
    if (last == nullptr)
        insHead(newnodo);
    else
        insLast(newnodo);
}

#endif //ASD_LINKEDLIST_H
