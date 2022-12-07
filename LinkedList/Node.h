//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_NODE_H
#define ASD_NODE_H

//Creazione nodo per l'implemetazone della lista

#include "Impiegato.h"
#include <iostream>

using namespace std;

class Node {
private:
    Node* Next;
    Impiegato* Imp;
public:
    Node(Node* Next, Impiegato* Imp);
    ~Node();

    void setNext(Node* Next);

    Node* getNext () {
        return Next;
    }
    Impiegato* getImp () {
        return Imp;
    }
};

Node::Node(Node *Next, Impiegato *Imp) {
    this->Next = Next;
    this->Imp = Imp;
}
Node::~Node() {
    delete Next;
    delete Imp;
}

void Node::setNext(Node *Next) {
    this->Next = Next;
}

#endif //ASD_NODE_H
