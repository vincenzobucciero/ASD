//
// created by vincenzo on 28/12/22
//

//IMPLEMENTAZIONE CODA DI PRIORITA' MINIMA TRAMITE MIN-HEAP

/*
    • Progettare ed implementare una classe Priority-queue che
      implementi le seguenti operazioni
        • Insert(S,x)
        • Minimum(S)
        • Extract-Min(S)
        • Decrease-priority(S,x,k)
*/

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/MinPriorityQueue/MinPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;

//test

int main () {

    MinPriorityQueue<int> minQueueTree ;

    minQueueTree.queueInsert(100);
    minQueueTree.queueInsert(200);
    minQueueTree.queueInsert(20);
    minQueueTree.queueInsert(420);
    minQueueTree.queueInsert(80);
    minQueueTree.queueInsert(820);
    minQueueTree.queueInsert(1020);
    minQueueTree.queueInsert(600);


    minQueueTree.printTree();
    minQueueTree.printAsciiTree();

    cout << "Minimum 1: " << minQueueTree.minimum() << endl;
    cout << "Extract Min 1:  " << minQueueTree.extractMin() << endl;

    minQueueTree.decreaseKey(2,20);

    minQueueTree.printTree();
    minQueueTree.printAsciiTree();

    cout << "Minimum 2: " << minQueueTree.minimum() << endl;
    cout << "Extract Min 2:  " << minQueueTree.extractMin() << endl;

}