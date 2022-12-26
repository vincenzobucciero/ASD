//
// created by vincenzo on 26/12/22
//

/*
    • Progettare ed implementare una classe che implementi un
        heap k-nario (ogni nodo ha k figli)
*/


//IMPLEMENTATO TRAMITE MIN-HEAP

//test

#include "MinKappa.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    MinKappa<int> tree(new vector<int>, 3);

    for (int i = 0; i < 13; i++) {
        int num = rand()%50;
        tree.insert(num);
    }

    tree.printTree();

    return 0;
}