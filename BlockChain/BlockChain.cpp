//
// Created by vincenzo on 09/12/22.
//

//Credit to https://github.com/Attilio-Di-Vicino/Algoritmi-strutture-dati/tree/main/Lezione04

/*
 * La blockchain è una struttura dati composta da una lista di
    blocchi all'interno dei quali è memorizzato un insieme di
    transazioni. Una transazione è costituita da un indirizzo
    FROM, un indirizzo TO ed un valore intero QT.
        1. Progettare ed implementare una struttura dati
            LinkedList mediante template ed utilizzarla per
            realizzare una blockchain
        2. Dato un indirizzo A, stampare a video/salvare su file
            tutte le transazioni in cui compare A ed il suo bilancio
            finale.
 */

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Block.h"

using namespace std;

void visualizza(LinkedList<Block>*);
void searchAdd(LinkedList<Block> *);
bool isFittizzio(LinkedList<Block>*);
int main(){

    // instanzio oggetto blockchain
    LinkedList<Block>* blockchain = new LinkedList<Block>;

    // instanzio la testa della blockchain, quindi inserisco il primo blocco
    // che risulta essere un blocco fittizzio
    blockchain->insNode(blockchain->getLast(),new Block());

    // a questo punto la testa della lista transazione viene allocata dal costruttore nella classe Blocco
    // quindi passo direttamente all'inserimento delle transazioni

    char scelta;

    do{
        // MENU
        cout << endl << "***MENU***" << endl;
        cout << "1- Inserisci un nuovo blocco" << endl;
        cout << "2- Inserisci una transazione" << endl;
        cout << "3- Visualizza Blockchain" << endl;
        cout << "4- Visualizza Tx e Bilancio di un indirizzo" << endl;
        cout << "5- Esci: ";
        cin >> scelta;

        switch (scelta){

            case '1': blockchain->insNode(blockchain->getLast(),new Block());
                break;
            case '2': if (isFittizzio(blockchain))
                    break;
                blockchain->getLast()->getObj()->addTx();
                break;
            case '3': visualizza(blockchain);
                break;
            case '4': searchAdd(blockchain);
                break;
            case '5': exit(1);
                break;

            default: exit(1);
                break;
        }
    } while (1);

    return 0;
}

/*
    input indirizzo della blockchain

    scorre la lista dei blocchi e richiama il metodo
    che permette di stampare la lista delle Tx al suo interno
*/
void visualizza(LinkedList<Block>* list){
    Node<Block>* tmp = list->getHead();

    // nel caso in cui sia il nodo fittizzio
    if ( tmp->getObj()->getId() == 0 )
        tmp = tmp->getNext();

    while (tmp != nullptr){
        tmp->getObj()->getInfoBlock();
        tmp = tmp->getNext();
    }
}

/*
    input indirizzo della blockchain
    scorre la lista dei blocchi e richiama il metodo
    che permette di cercare all'interno della lista Tx l'indirizzo
    e ritorna il bilancio
*/
void searchAdd(LinkedList<Block>* list){
    string address;
    cout << endl << "Inserisci l'indirizzo: "; cin >> address;

    int balance = 0;

    Node<Block>* tmp = list->getHead()->getNext();
    while (tmp != nullptr){
        balance = tmp->getObj()->searchAddress(address,balance);
        tmp = tmp->getNext();
    }
    cout << endl << "Il bilancio di " << address << " corrisponde a: " << balance << endl;
}

/*
    input indirizzo della blockchain
    controlla de l'id dell ultimo blocco istanziato
    quindi se è 0 allora stiamo nel blocco fittizzio e ritorna vero
*/
bool isFittizzio(LinkedList<Block>* list){
    if (!list->getLast()->getObj()->getId()){
        cout << "\n***ATTENZIONE SEI NEL BLOCCO FITTIZZIO***\nCREA PRIMA UN NUOVO BLOCCO" << endl;
        return true;
    }
    return false;
}


