//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_IMPIEGATO_H
#define ASD_IMPIEGATO_H

/*
 * Progettare ed implementare una lista (linked list) di
    impiegati di un'azienda. Un impiegato ha un nome ed un
    salario.
 */

#include <iostream>

using namespace std;

class Impiegato {
private:
    string nome;
    double salario;
public:
    Impiegato(string nome, double salario);
    ~Impiegato();

    void setNome(string nome);
    void setSalario(double salario);
    string getNome() {
        return nome;
    }
    double getSalario() {
        return salario;
    }

    //metodo virtual per sfruttare polimorfismo
    virtual void getInfo();

    //Overload operatore+
    Impiegato operator+(Impiegato Imp1);
};

Impiegato::Impiegato(string nome, double salario) {
    this->nome = nome;
    this->salario = salario;
}

Impiegato::~Impiegato() {

}

void Impiegato::setNome(string nome) {
    this->nome = nome;
}
void Impiegato::setSalario(double salario) {
    this->salario = salario;
}
void Impiegato::getInfo() {
    cout << "Sono un impiegato:  " << nome << " con salario €" << salario << endl;
}

//overload dell'operatore + per la somma dei salari
Impiegato Impiegato::operator+(Impiegato Imp1) {
    Impiegato Temp("", 0);
    Temp.setSalario(this->getSalario() + Imp1.getSalario());
    return Temp;
}

#endif //ASD_IMPIEGATO_H
