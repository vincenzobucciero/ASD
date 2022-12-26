//
// created by vincenzo on 25/12/22
//

/*
    • Progettare ed implementare un algoritmo ricorsivo che dato
       un array verifichi se rappresenta un heap binario
*/


#include "IsHeap.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    //min heap
    vector<int> heap {1,2,3,4,5,6,7};
    //max heap
    //vector<int> heap {60,50,30,40,20,10}

    IsHeap<int> Tree;

    Tree.isHeap(heap, heap.size(), 0);

    cout << endl;

    return 0;
}