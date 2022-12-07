//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_OPERATOR_H
#define ASD_OPERATOR_H

#include <iostream>

class Punto {
private:
    double x;
    double y;
public:
    Punto(double X, double Y) {
        this->x = X;
        this->y = Y;
    }

    //inizializza coordinate del punto
    Punto() {
        x = y = 0.0;
    }

    void setX (double X) {
        x = X;
    }
    void setY (double Y) {
        y = Y;
    }
    double getX () {
        return x;
    }
    double getY () {
        return y;
    }
    //Overload operatore + (incremento vettoriale)
    void operator+=(Punto p2) {
        x += p2.getX();
        y += p2.getY();
    }
};

//Overload dell'operatore + (somma vettoriale)
/*
Punto operator+ (Punto p1, Punto p2) {
    //variabile temporanea
    Punto Temp;
    Temp.setX(p1.getX() + p2.getX());
    Temp.setY(p1.getY() + p2.getY());
    return Temp;
}
*/

//Overload operatore + (incremento vettoriale)



#endif //ASD_OPERATOR_H
