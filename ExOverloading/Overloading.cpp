//
// Created by vincenzo on 04/12/22.
//


//Example of overloading function

#include <iostream>
#include <cmath>

using namespace std;

int Radice (int x) {
    return sqrt(x);
}

//Overloading
double Radice (double y) {
    return sqrt(y);
}

int main () {
    //tipo variabile auto -> compilatore capisce autonomamente
    auto A = 625;   //int
    auto B = 56.3225;   //double

    cout << "La Radice quadrata di " << A << " è: " << Radice(A) << endl;
    cout << "La Radice quadrata di " << B << " è: " << Radice(B) << endl;

    return 0;
}