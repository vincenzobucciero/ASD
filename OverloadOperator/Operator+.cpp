//
// Created by vincenzo on 07/12/22.
//

#include "Operator+.h"

#include <iostream>

using namespace std;

int main() {
    Punto A(12.78, 33.4), B(2.45, 1.2);
    Punto C;
    //somma vettoriale
    /*
        C = A + B;
        cout << "Coordinate PUNTO A:  " << A.getX() << " , " << A.getY() << endl;
        cout << "Coordinate PUNTO B:  " << B.getX() << " , " << B.getY() << endl;
        cout << "Coordinate PUNTO C (A+B) con overload operator+ : " << C.getX() << " , " << C.getY() << endl;
    */
    //incremento vettoriale
    A += B;
    cout << A.getX() << " , " << A.getY() << endl;
    // sarebbe stata ammessa anche la chiamata alla funzione
    // A.operator+=B
    // tradotta dal compilatore in
    // operator+=(&A, B);

}


