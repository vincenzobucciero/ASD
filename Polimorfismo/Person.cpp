//
// Created by vincenzo on 07/12/22.
//

/*
 *  Mostra il polimorfismo in azione con una classe Persona
    e due classi derivate Studente e Professore ognuna
    delle quali risponde in maniera diversa allo stesso
    metodo di print.
 */

#include <iostream>
#include "Persona.h"

using namespace std;

int main () {
    Persona* pers;
    Persona x (string("Giuseppe"));
    pers = &x;
    pers->Print();

    Studente y (string("Vincenzo"), 27.85);
    pers = &y;
    pers->Print();

    Professore z (string("Giovanni"), 124);
    pers = &z;
    pers->Print();

    return 0;
}