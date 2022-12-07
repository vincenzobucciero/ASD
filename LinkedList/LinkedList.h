//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_LINKEDLIST_H
#define ASD_LINKEDLIST_H

/*
 *  Creare una lista di impiegati e stamparla a video
            sfruttando il principio del polimorfismo
 */

//per creare una lista, creare prima un nodo

#include "Impiegato.h"
#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
private:
    Node* head;
    Node* last;

    //dichiaro private insHead & insLast poichè rendo pubblico un solo metodo insNode
    //per l'inserimento in base ai diversi parametri
    //prende come argomento un riferimento ad impiegato poichè stiamo costruendo una lista di impiegati
    void insHead(Impiegato* pt);
    void insLast(Impiegato* pt);
public:
    LinkedList(Node* head);
    ~LinkedList();

    Node* getHead() {
        return head;
    }
    Node* getLast() {
        return last;
    }

    void insNode (Node* node, Impiegato* pt);
    void getList();

    void getSumSalrio();
};

LinkedList::LinkedList(Node *head) {
    this->head = head;
    this->last = this->head;
}
LinkedList::~LinkedList() {
    while (this->head != nullptr) {
        auto* tmp = head;
        head = head->getNext();
        delete tmp;
    }
}

void LinkedList::insHead(Impiegato *pt) {
    Node* newnode = new Node(nullptr, pt);  //come primo parametro passo nullptr poiche sto inserendo in cima alla lista
    head = newnode;
    this->last = head;
}
void LinkedList::insLast(Impiegato *pt) {
    Node* newnode = new Node(nullptr, pt);
    last->setNext(newnode);
    last = newnode;
}
void LinkedList::insNode(Node *node, Impiegato *pt) {
    if (node == nullptr)
        insHead(pt);
    else
        insLast(pt);
}

void LinkedList::getList() {
    Node* tmp = head;
    while (tmp != nullptr) {
        tmp->getImp()->getInfo();
        tmp = tmp->getNext();
    }
}

void LinkedList::getSumSalrio() {
    Impiegato tmp("",0);
    Node *scor = head;

    while (scor != nullptr) {
        Impiegato emp("",scor->getImp()->getSalario());

        // in questo caso utilizzo l'overload dell operatore+
        tmp = tmp + emp;

        scor = scor->getNext();
    }
    cout << endl << endl << "Somma totale dei salari: " << tmp.getSalario() << endl;
}

#endif //ASD_LINKEDLIST_H
