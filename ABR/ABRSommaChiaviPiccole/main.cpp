//
// created by vincenzo on 02/01/23
//


/*
    • Progettare un algoritmo ricorsivo che dato un ABR 
        sommi le k chiavi più piccole
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/BinarySearchTree.h"
#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/ABRnode.h"

using namespace std;

int sommaKpiccole(BinarySearchTree<int> *tree, Node<int> *node, int k) {
    if(node == nullptr)
        return 0;
    else if(k == 0)
        return node->getKey();
    else    
        return node->getKey() + sommaKpiccole(tree, tree->successor(node), k-1);
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

    int k = 90;

    Node<int> *min = tree.minimum();

    cout << endl;
    cout << "Somma K chiavi piu piccole:  " << sommaKpiccole(&tree, min, k-1);
}