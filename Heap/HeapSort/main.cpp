//
// created by vincenzo on 26/12/22
//

//IMPLEMENTAZIONE HEAP-SORT

//test

#include "HeapSort.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main () {
    
    HeapSort<int> tree;

    tree.insert(1998);
    tree.insert(1);
    tree.insert(10);
    tree.insert(190);
    tree.insert(2);
    tree.insert(20);
    tree.insert(100);

    tree.printAsciiTree();

    tree.heapsort();

    tree.printTree();
    tree.printAsciiTree();

}