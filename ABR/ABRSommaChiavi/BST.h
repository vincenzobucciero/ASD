//
// created by vincenzo on 03/01/23
//

/*
    Progettare un algoritmo ricorsivo che dato un ABR sommi le
    chiavi comprese tra il valore m ed il valore M, con m<M
*/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>

#define vuoto 5

#include "/home/vincenzo/Scrivania/asd/ASD/ABR/ABRSommaChiavi/ABRnode.h"

using namespace std;

template <typename T>
class BinarySearchTree {
    private:
        Node<T> *root;

        void insNode(T key, Node<T> *prev, Node<T> *curr);
        void transplant(Node<T> *u, Node<T> *v);

        void inOrderAscii(Node<T> *root, int spazio);

        void inOrderView(Node<T> *node);
        void preOrderView(Node<T> *node);
        void postOrderView(Node<T> *node);
    public:
        BinarySearchTree(Node<T> *root);
        BinarySearchTree();
        ~BinarySearchTree();

        Node<T> *getRoot() { return this->root; }

        void search(T key);
        Node<T> *search(T key, Node<T> *node);

        Node<T> *minimum();
        Node<T> *maximum();
        Node<T> *minimum(Node<T> *node);
        Node<T> *maximum(Node<T> *node);

        Node<T> *predecessor(T key);
        Node<T> *successor(T key);
        Node<T> *predecessor(Node<T> *node);
        Node<T> *successor(Node<T> *node);

        void insert(T key);
        void insert(T key, Node<T> *prev, Node<T> *curr);

        void deleteNode(T key);

        void printAsciiTree();

        void inOrder();
        void preOrder();
        void postOrder();
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T> *root) {
    this->root = root;
}
template <typename T>
BinarySearchTree<T>::BinarySearchTree() {
    this->root = nullptr;
}
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete root;
}

template <typename T>
void BinarySearchTree<T>::insNode(T key, Node<T> *prev, Node<T> *curr) {
    if(prev != nullptr) {
        curr = new Node<T>(key);
        curr->setParent(prev);
        if(key > prev->getKey())
            prev->setRight(curr);
        else   
            prev->setLeft(curr);
    } else {
        curr = new Node<T>(key);
    }
}
template <typename T>
void BinarySearchTree<T>::insert(T key, Node<T> *prev, Node<T> *curr) {
    if(this->root == nullptr)
        this->root = new Node<T>(key);
    if(curr == nullptr) 
        insNode(key, prev, curr);
    else if(key > curr->getKey())
        insNode(key, curr, curr->getRight());
    else    
        insNode(key, curr, curr->getLeft());
}
template <typename T>
void BinarySearchTree<T>::insert(T key) {
    this->insert(key, nullptr, this->root);
}

template <typename T>
void BinarySearchTree<T>::transplant(Node<T> *u, Node<T> *v) {
    // -> 1 nodo nell'albero
    if(u->getParent() == nullptr)
        this->root = v;
    // -> se u è figlio sx
    else if(u == u->getParent()->getLeft())
        u->getParent()->setLeft(v);
    // -> se u è figlio dx
    else    
        u->getParent()->setRight(v);

    if(v != nullptr)
        v->setParent(u->getParent());
}
template <typename T>
void BinarySearchTree<T>::deleteNode(T key) {

    Node<T> *node = this->search(key, root);

    if(node != nullptr) {
        if(node->getLeft() == nullptr)
            this->transplant(node, node->getRight());
        else if(node->getRight() == nullptr)
            this->transplant(node, node->getLeft());
        else {
            Node<T> *y = this->maximum(node->getRight());
            if(y->getParent() != node) {
                this->transplant(y, y->getRight());
                y->setRight(node->getRight());
                y->getRight()->setParent(y);
            }
            this->transplant(node, y);
            y->setLeft(node->getLeft());
            y->getLeft()->setParent(y);
        }
    }
}

template <typename T>
void BinarySearchTree<T>::inOrderAscii(Node<T> *root, int spazio) {
    if(root == nullptr)
        return;
    spazio += vuoto;
    inOrderAscii(root->getRight(), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << " ";
    cout << root->getKey() << endl;
    inOrderAscii(root->getLeft(), spazio);
}
template <typename T>
void BinarySearchTree<T>::printAsciiTree() {
    cout << endl;
    cout << "****ASCII-TREE****" << endl;
    inOrderAscii(root, 0);
}
template <typename T>
void BinarySearchTree<T>::inOrderView(Node<T> *node) {
    if(node == nullptr)
        return;
    cout << node->getKey() << " ";
    inOrderView(node->getLeft());
    inOrderView(node->getRight());
}
template <typename T>
void BinarySearchTree<T>::inOrder() {
    cout << endl;
    cout << "****VISITA-INORDER****" << endl;
    this->inOrderView(root);
}
template <typename T>
void BinarySearchTree<T>::preOrderView(Node<T> *node) {
    if(node == nullptr)
        return;
    inOrderView(node->getLeft());
    cout << node->getKey() << " ";
    inOrderView(node->getRight());
}
template <typename T>
void BinarySearchTree<T>::preOrder() {
    cout << endl;
    cout << "****VISITA-PREORDER****" << endl;
    this->preOrderView(root);
}
template <typename T>
void BinarySearchTree<T>::postOrderView(Node<T> *node) {
    if(node == nullptr)
        return;
    inOrderView(node->getLeft());
    inOrderView(node->getRight());
    cout << node->getKey() << " ";
}
template <typename T>
void BinarySearchTree<T>::postOrder() {
    cout << endl;
    cout << "****VISITA-POSTORDER****" << endl;
    this->postOrderView(root);
}

template <typename T>
Node<T> *BinarySearchTree<T>::search(T key, Node<T> *node) {
    if(node == nullptr || key == node->getKey())
        return node;
    if(key < node->getKey())
        return search(key, node->getLeft());
    else
        return search(key, node->getRight());
    
    return nullptr;
}
template <typename T>
void BinarySearchTree<T>::search(T key) {

    Node<int> *tmp = this->search(key, this->getRoot());

    if(tmp == nullptr)
        cout << "NodeABR [" << key << "] non trovato" << endl;
    else
        cout << "NodeABR [" << key << "] trovato =>  " << tmp->getKey() << endl;
}

template <typename T>
Node<T> *BinarySearchTree<T>::minimum(Node<T> *node) {
    while(node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}
template <typename T>
Node<T> *BinarySearchTree<T>::minimum() {
    return this->minimum(root);
}
template <typename T>
Node<T> *BinarySearchTree<T>::maximum(Node<T> *node) {
    while(node->getRight() != nullptr) {
        node = node->getRight();
    }
    return node;
}
template <typename T>
Node<T> *BinarySearchTree<T>::maximum() {
    return this->maximum(root);
}

template <typename T>
Node<T> *BinarySearchTree<T>::predecessor(Node<T> *node) {
    if(node->getLeft() != nullptr)
        return maximum(node->getLeft());
    Node<T> *y = node->getParent();
    while(y != nullptr && node == y->getLeft()) {
        node = y;
        y = y->getParent();
    }
    return y;
}
template <typename T>
Node<T> *BinarySearchTree<T>::predecessor(T key) {
    Node<T> *node = this->search(key, this->getRoot());
    if(node->getLeft() != nullptr)
        return maximum(node->getLeft());
    Node<T> *y = node->getParent();
    while(y != nullptr && node == y->getLeft()) {
        node = y;
        y = y->getParent();
    }
    return y;
}
template <typename T>
Node<T> *BinarySearchTree<T>::successor(Node<T> *node) {
    if(node->getRight() != nullptr)
        return minimum(node->getRight());
    Node<T> *y = node->getParent();
    while(y != nullptr && node == y->getRight()) {
        node = y;
        y = y->getParent();
    }
    return y;
}
template <typename T>
Node<T> *BinarySearchTree<T>::successor(T key) {
    Node<T> *node = this->search(key, this->getRoot());
    if(node->getRight() != nullptr)
        return minimum(node->getRight());
    Node<T> *y = node->getParent();
    while(y != nullptr && node == y->getRight()) {
        node = y;
        y = y->getParent();
    }
    return y;
}

#endif //BST_H