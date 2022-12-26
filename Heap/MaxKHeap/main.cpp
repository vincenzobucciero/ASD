//
// created by vincenzo on 26/12/22
//

/*
    • Progettare ed implementare una classe che implementi un
        heap k-nario (ogni nodo ha k figli)
*/

#include "MaxKappa.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main () {
    srand(1);
    srand((unsigned)time(0));

    MaxKappa<int> tree(new vector<int>, 4);

    for (int i = 0; i < 20; i++)
        tree.insert(rand()%900);
    tree.printTree();

    return 0;
}

