//
// Created by vincenzo on 04/12/22.
//

//Example with alias references

#include <iostream>

using namespace std;

int Dividi (int x, int y) {
    return x/y;
}

float Dividi (float x, float y) {
    return x/y;
}

int main () {
    int X = 5;
    int Y = 2;
    int &rx = X;    //valore referenziale
    float A = 5.0;
    float B = 2.0;

    cout << Dividi(rx,Y) << endl;   //passo rx, cioè un riferimento alla variabile X
    cout << Dividi(A,B) << endl;

    cout << "Valore di X:  " << X << endl;
    rx = 2;
    cout << "Valore di X dopo modifica:  " << X << endl;

    return 0;
}