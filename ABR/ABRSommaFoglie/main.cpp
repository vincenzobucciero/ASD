//
// created by vincenzo on 02/01/23
//

/*
    Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi di tutte le foglie
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/BinarySearchTree.h"
#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/ABRnode.h"


using namespace std;

int somma(Node<int> *node) {
    if(node == nullptr) 
        return 0;
    if(node->getLeft() == nullptr && node->getRight() == nullptr)
        return node->getKey();
    return somma(node->getLeft()) + somma(node->getRight());
}

int main () {

    BinarySearchTree<int> *tree = new BinarySearchTree<int>;

    tree->insert(10);
    tree->insert(24);
    tree->insert(12);
    tree->insert(102);
    tree->insert(66);
    tree->insert(2);
    tree->insert(20);

    tree->printAsciiTree();

    cout << endl;
    cout << "Somma delle foglie:  " << somma(tree->getRoot());
}

