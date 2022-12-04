//
// Created by vincenzo on 04/12/22.
//

/*
 *  Risolve l'indovinello: ha due attributi anfora una da 3 lt ed una
    da 5 lt ed un metodo risolvi() che risolve l'indovinello mostrando
    a video il contenuto delle due anfore ad ogni passo della
    risoluzione.
        – Es.: Riempi anfora A: A=3 B=0

     Soluzione
        1- versa 5 litri
        2- versa da 5 litri nell'anfora da 3
        3- svuota anfora da tre
        4- metti da 5 a 3 quindi avremo 2 litri in quella da tre e quella da 5 vuota
        5- riempi 5 litri
        6- metti un litro da 5 a 3
        7- l'anfora con capacita 5 litri avra esattamente 4 litri al suo interno
 */

#ifndef ASD_INDOVINELLO_H
#define ASD_INDOVINELLO_H

#include "Contenitore.h"
#include "Anfora.h"
#include <iostream>

using namespace std;

class Indovinello {
private:
    Anfora tre;
    Anfora cinque;
    void printInfo();
public:
    Indovinello();
    ~Indovinello();

    void risolvi();
};

Indovinello::Indovinello(): tre(3,0), cinque(5,0) {

}

Indovinello::~Indovinello() {

}

void Indovinello::risolvi() {

    cout << "\n***1- Riempi l'Anfora da 5 litri***" << endl;
    cinque.riempi();

    printInfo();

    cout << "***2- Svuota Anfora da 5 in quella da 3***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();

    cout << "***3- Svuota l'Anfora da 3 litri***" << endl;
    tre.svuota();

    printInfo();

    cout << "***4- Metti i due litri rimanenti dell'Anfora da 5 in quella da 3***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();

    cout << "***5- Riempi l'Anfora da 5***" << endl;
    cinque.riempi();

    printInfo();

    cout << "***6- Sposta il conenuto dell'Anfora di 5 in quella da tre***" << endl;
    cinque.spostaContenuto(tre);

    printInfo();

    cout << "Fine...Indovinello risolto" << endl;
}

void Indovinello::printInfo() {
    cout << "Ora abbiamo Nell'Anfora da 5 litri: " << cinque.getQt() << " litri" << endl;
    cout << "Ora abbiamo Nell'Anfora da 3 litri: " << tre.getQt() << " litri" << endl << endl;
}

#endif //ASD_INDOVINELLO_H
