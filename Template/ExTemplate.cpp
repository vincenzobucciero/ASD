//
// Created by vincenzo on 09/12/22.
//

//Sommatoria con template

/*
 * In C++ è possibile scrivere piu funzioni con lo stesso nome ma con parametri e tipi diversi (overloading)
 * per descrivere piu funzioni con lo stesso scopo. Comunque dovremmo ripetere la scrittura di codice.
 * Per evitare ciò, è possibile utilizzare i TEMPLATE:
 *
 *                  template <class T1, class T2, ...>
 *                  Tr Funzione (Tp1 Param1, Tp2 Param2, ...) {
 *                      Tp3 variabili locali;
 *                      istruzioni della funzione...
 *                  }
 */

#include <iostream>
#include <string>

using namespace std;
//template <class || template T>
template <class T>      //T rappresemta il tipo generico, viene sostituito di volta in volta dal compilatore
T SumArray (T v[], int n) {     //T sarà int || float || double
    int i;
    T Acc = 0;
    for (i = 0; i < n; ++i) {
        Acc += v[i];
    }
    return Acc;
}

int main() {
    int A[10] = {2,4,6,8,10,12,14,16,18,20};
    float B[10] = {2,4,6,8,10,12,14,16,18,20};;
    double C[10] = {2,4,6,8,10,12,14,16,18,20};;

    cout << "\nLa somma degli elementi dell'array [int] è: " << SumArray(A,10) << endl;
    cout << "\nLa somma degli elementi dell'array [float] è: " << SumArray(B,10) << endl;
    cout << "\nLa somma degli elementi dell'array [double] è: " << SumArray(C,10) << endl;
}


//Una funzione generica viene anche chiamata template

