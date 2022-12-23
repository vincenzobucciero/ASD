//
// created by vincenzo on 23/12/22
//

/*
    Progettare ed implementare una classe template Max-Heap
    dotata delle seguenti operazioni:
    • Max-Heapify
    • Build-Max-Heap
    • Insert
    • PrintArray
    • (PrintAsciiTree)
*/

//test for max heap

#include "MaxHeap.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> tree{10,30,50,60,20};

    MaxHeap<int> maxTree = MaxHeap<int>(tree);

    maxTree.buildMaxHeapify();
    /*maxTree.insert(10);
    maxTree.insert(30);
    maxTree.insert(50);
    maxTree.insert(60);
    maxTree.insert(20);*/

    maxTree.printArray();
    

    return 0;
}