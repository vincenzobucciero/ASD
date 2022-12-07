//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_MANAGER_H
#define ASD_MANAGER_H

/*
 * Un manager è un impiegato cui viene corrisposto
    un bonus oltre al salario
 */
#include "Impiegato.h"
#include <iostream>

class Manager : public Impiegato {
private:
    double bonus;
public:
    Manager(string nome, double salario, double bonus): Impiegato(nome,salario),bonus(bonus) {

    }
    ~Manager() {

    }

    void setBonus(double bonus);
    double getBonus() {
        return bonus;
    }

    //ridefinizione metodo classe base
    void getInfo();
};

void Manager::setBonus(double bonus) {
    this->bonus = bonus;
}

void Manager::getInfo() {
    cout << "Sono un manager:  " << getNome() << " con salario €" << getSalario() << " con bonus €" << getBonus() << endl;
}

#endif //ASD_MANAGER_H
