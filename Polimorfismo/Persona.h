//
// Created by vincenzo on 07/12/22.
//

/*
 *  Mostra il polimorfismo in azione con una classe Persona
    e due classi derivate Studente e Professore ognuna
    delle quali risponde in maniera diversa allo stesso
    metodo di print
 */

#ifndef ASD_PERSONA_H
#define ASD_PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
public:
    Persona (string s) : nome(s) { }
    virtual void Print() {
        cout << "Persona -> Il mio nome è:  " << nome << endl;
    }
protected:
    string nome;
};

class Studente : public Persona {
public:
    Studente (string s, float m) : Persona(s),media(m) { }
    void Print () {
        cout << "Studente -> Il mio nome è:  " << nome << " e la mia media è " << media << endl;
    }
private:
    float media;
};

class Professore : public Persona {
public:
    Professore (string s, int p) : Persona(s), pubblicazioni(p) { }
    void Print () {
        cout << "Professore -> Il mio nome è:  " << nome << " e le mie pubblicazioni sono " << pubblicazioni << endl;
    }
private:
    int pubblicazioni;
};

#endif //ASD_PERSONA_H
