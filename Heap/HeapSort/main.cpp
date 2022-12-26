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
    
    srand(time(NULL));

    HeapSort<int> tree (new vector<int>);

    for(int i = 0; i < 15; i++) {
        int num = rand()%20;
        tree.insert(num);
    }

    tree.printTree();

    tree.heapsort();

    cout << "\n\n DOPO ORDINAMENTO " << endl;

    tree.printTree();

}