//
// Created by vincenzo on 09/12/22.
//

#ifndef ASD_STACK_H
#define ASD_STACK_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    int Dim, Top;
    T *Vet;
public:
    Stack() {
        Vet = nullptr;
        Dim = 0;
        Top = -1;
    }
    void push(T elem);
    bool pop(T &elem);
};

template<typename T> void Stack<T>::push(T elem) {
    if (Top == Dim-1) {
        T *App;
        App = new T[Dim+10];    //trasloca lo stack
        for (int i = 0; i < Dim; i++) {
            App[i] = Vet[i];
        }
        Dim += 10;
        delete [] Vet;
        Vet = App;
    }
    Vet[ ++Top ] = elem;
}

template<typename T> bool Stack<T>::pop(T &elem) {
    bool Risp;
    if (Top >= 0) Risp = true, elem = Vet[Top--];
    else Risp = false; // stack vuoto
    return Risp;
}

#endif //ASD_STACK_H
