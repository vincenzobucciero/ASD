//
// created by vincenzo on 02/01/23
//

/*
    • Progettare una classe BinarySearchTree che implementi un
        albero binario di ricerca con le seguenti funzioni
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR
        • SUCCESSOR
        • INSERT
        • DELETE
*/

#include <iostream>
#include <vector>

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/BinarySearchTree/BinarySearchTree.h"

using namespace std;

int main () {

    BinarySearchTree<int> *tree = new BinarySearchTree<int> ;

    tree->insert(10);
    tree->insert(20);
    tree->insert(2);
    tree->insert(4);
    tree->insert(60);
    tree->insert(222);
    tree->insert(40);
    tree->insert(62);

    tree->printAsciiTree();

    tree->search(40);
    tree->search(2);
    tree->search(600);

    cout << "Minimo: " << tree->minimum()->getKey() << endl;
    cout << "Massimo: " << tree->maximum()->getKey() << endl;

    cout << "Predecessore di 4: " << tree->predecessor(4)->getKey() << endl;
    cout << "Successore di 4: " << tree->successor(4)->getKey() << endl;

    tree->inOrder();
    tree->preOrder();
    tree->postOrder();

    tree->deleteNode(40);
    tree->deleteNode(62);
    tree->deleteNode(222);
    tree->deleteNode(10);

    tree->printAsciiTree();
}