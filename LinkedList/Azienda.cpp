//
// Created by vincenzo on 07/12/22.
//

/*
 *  Progettare ed implementare una lista (linked list) di
    impiegati di un'azienda. Un impiegato ha un nome ed un
    salario. Un manager è un impiegato cui viene corrisposto
    un bonus oltre al salario:
        1.  Creare una lista di impiegati e stamparla a video
            sfruttando il principio del polimorfismo
        2.  Implementare l'overload dell'operatore + in modo da
            sommare i salari di tutti gli impiegati.
 */

#include "LinkedList.h"
#include "Impiegato.h"
#include "Manager.h"
#include <iostream>

using namespace std;

int main () {
    //istanzio nuovo oggetto della classe LinkedList vuota
    LinkedList* lista = new LinkedList(nullptr);

    //Inserisco elementi nella lista
    lista->insNode(lista->getLast(), new Manager("Vincenzo", 1800.00, 200.00));
    lista->insNode(lista->getLast(), new Impiegato("Giovanni", 1600.00));
    lista->insNode(lista->getLast(), new Impiegato("Maurizio", 1600.00));
    lista->insNode(lista->getLast(), new Manager("Ciretta", 1800.00, 200.00));

    lista->getList();

    lista->getSumSalrio();
}


