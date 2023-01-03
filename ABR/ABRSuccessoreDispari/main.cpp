//
// created by vincenzo on 03/01/23
//

/*
    Progettare un algoritmo che dato un ABR ed una chiave k
    restitusca il successore dispari di k
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/ABRnode.h"
#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/BinarySearchTree.h"

using namespace std;

int successoreDispari(BinarySearchTree<int> *tree, Node<int> *node) {
    Node<int> *succ = tree->successor(node);
    if(succ == nullptr)
        return -10;
    if(succ->getKey()%2 == 0)
        return successoreDispari(tree, succ);
    else    
        return succ->getKey();
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
    tree.insert(15);

    tree.printAsciiTree();

    int k = 10;

    cout << "SommaKKey: " << successoreDispari(&tree,tree.getRoot());

    return 0;
}