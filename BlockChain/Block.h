//
// Created by vincenzo on 09/12/22.
//

//Credit to https://github.com/Attilio-Di-Vicino/Algoritmi-strutture-dati/tree/main/Lezione04

#ifndef ASD_BLOCK_H
#define ASD_BLOCK_H

#include "Transazione.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * La blockchain è una struttura dati composta da una lista di
    blocchi all'interno dei quali è memorizzato un insieme di
    transazioni.
 */

class Block {
private:
    //poiche allochiamo un oggetto blocco, gli assegniamo un currId (id corrente) in un attributo statico
    static int currId;
    //Assegniamo ancheun id non mutabile di quell'oggetto blocco
    const int id;
    LinkedList<Transazione>* listaTx;
public:
    Block():id(currId++),listaTx(new LinkedList<Transazione>){
        cout << "Aggiunto blocco id:  " << id << endl;
    }
    ~Block();

    //metodo setLista
    void setListaTx(LinkedList<Transazione>* bloccoObj) {
        this->listaTx = bloccoObj;
    }

    int getId() {
        return id;
    }

    LinkedList<Transazione>* getListaTx () {
        return listaTx;
    }

    //metodo che aggiunge transazione al blocco
    void addTx();
    //metodo che stampa le info del blocco
    void getInfoBlock();
    //metodo che stampa le info di un indirizzo blockchain
    int searchAddress(string address, int balance);
};

// I blocchi iniziano da 1, ma viene utilizzato
// blocco fittizzio per evitare errori
int Block::currId = 0;

Block::~Block() { delete listaTx; }

void Block::getInfoBlock() {
    cout << endl << "ID: " << getId() << endl;
    Node<Transazione>* tmp = listaTx->getHead();
    while (tmp != nullptr){
        tmp->getObj()->infoTx();
        tmp = tmp->getNext();
    }
}

//Aggiunge Tx nel blocco corrente
void Block::addTx(){
    string from;
    string to;
    int qt;

    cout << endl;
    cout << "Inserisci i dati della Transazione nel Blocco ID: " << getId() << endl;
    cout << "- From: "; cin >> from;
    cout << "- To: "; cin >> to;
    cout << "- Qt: "; cin >> qt;
    listaTx->insNode(listaTx->getLast(), new Transazione(from,to,qt));
}

// Controlla se nelle Tx è presente l'indirizzo preso in input
// Quindi stampa la Tx e esegue la somma algebrica del bilancio
// output Stampo a video le Tx e bilancio di un indirizzo
int Block::searchAddress(string address, int balance){

    Node<Transazione>* tmp = listaTx->getHead();

    cout << endl << "Le Tx effettuate da " << address << " Nel Blocco ID: " << getId() << " sono:" << endl;
    while (tmp != nullptr){
        if (tmp->getObj()->getFrom() == address){
            tmp->getObj()->infoTx();
            balance -= tmp->getObj()->getQt();
        } else if (tmp->getObj()->getTo() == address) {
            tmp->getObj()->infoTx();
            balance += tmp->getObj()->getQt();
        }
        tmp = tmp->getNext();
    }
    return balance;
}


#endif //ASD_BLOCK_H
