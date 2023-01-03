//
// created by vincenzo on 03/01/23
//

/*
    Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi comprese tra il valore m ed il valore M, con m<M
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/ABRSommaChiavi/BST.h"
#include "/home/vincenzo/Scrivania/asd/ASD/ABR/ABRSommaChiavi/ABRnode.h"

using namespace std;

void sommaKFoglia(Node<int> *node, int N, int M, int &somma) {
    if(node == nullptr)
        return;
    if(N <= node->getKey() && node->getKey() <= M)
        somma += node->getKey();
    sommaKFoglia(node->getLeft(), N, M, somma);
    sommaKFoglia(node->getRight(), N, M, somma);
}

bool isRange(int n, int N, int M){
    return N <= n && n <= M;
}

int sommaKFoglia(Node<int> *node, int N, int M){

    if ( node == nullptr )
        return 0;

    if ( isRange(node->getKey(),N,M) )
        return sommaKFoglia(node->getLeft(),N,M) + sommaKFoglia(node->getRight(),N,M) + node->getKey();
    else if ( N > node->getKey() )
        return sommaKFoglia(node->getRight(),N,M);
    
    return sommaKFoglia(node->getLeft(),N,M);
}

int main () {

    BinarySearchTree<int> tree;

    tree.insert(10);
    tree.insert(24);
    tree.insert(12);
    tree.insert(102);
    tree.insert(66);
    tree.insert(2);
    tree.insert(2);
    tree.insert(20);

    tree.printAsciiTree();

    int somma = 0;
    sommaKFoglia(tree.getRoot(),10,99,somma);
    cout << "Somma void: " << somma << endl;
    cout << "Somma func: " << sommaKFoglia(tree.getRoot(),10,99);

    return 0;
}