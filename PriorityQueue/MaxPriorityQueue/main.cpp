//
// created by vincenzo on 27/12/22
//

//IMPLEMENTAZIONE MAX-HEAP PER CODA DI PRIORITA' MASSIMA

//test

/*
    Progettare ed implementare una classe Priority-queue che
    implementi le seguenti operazioni
    • Insert(S,x)
    • Maximum(S) / 
    • Extract-Max(S) / 
    • Increase-priority(S,x,k) /
*/

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/MaxPriorityQueue/MaxPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

    MaxPriorityQueue<int> maxQueueTree ;

    maxQueueTree.queueInsert(100);
    maxQueueTree.queueInsert(200);
    maxQueueTree.queueInsert(20);
    maxQueueTree.queueInsert(420);
    maxQueueTree.queueInsert(80);
    maxQueueTree.queueInsert(820);
    maxQueueTree.queueInsert(1020);
    maxQueueTree.queueInsert(600);

    maxQueueTree.printTree();
    maxQueueTree.printAsciiTree();

    cout << endl << "Maximum 1: " << maxQueueTree.maximum() << endl;

    cout << endl << "Extract Max 1: " << maxQueueTree.extractMax() << endl;

    maxQueueTree.increaseKey(2, 20);

    maxQueueTree.printTree();
    maxQueueTree.printAsciiTree();

    cout << endl << "Maximum 2: " << maxQueueTree.maximum() << endl;

    cout << endl << "Extract Max 2: " << maxQueueTree.extractMax() << endl;


    return 0;
}