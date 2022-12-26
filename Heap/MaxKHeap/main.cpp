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
    srand(time(NULL));

    MaxKappa<int> tree(new vector<int>, 3);

    for (int i = 0; i < 15; i++) {
        int num = rand()%100;
        tree.insert(num);
    }

    tree.printTree();
        

    return 0;
}

