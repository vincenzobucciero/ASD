//
// Created by vincenzo on 04/12/22.
//

/*
 *  Generico contenitore d'acqua: ha un attributo qt che memorizza
    la quantità d'acqua, un metodo versa(lt) per versare acqua, un
    metodo togli(lt) per togliere acqua ed un metodo getQt() che
    restituisce il valore di qt.
 */

#ifndef ASD_CONTENITORE_H
#define ASD_CONTENITORE_H

#include <iostream>

using namespace std;

class Contenitore {
private:
    int qt;
public:
    //costruttore
    Contenitore(int qt);
    //distruttore: chiamati secondo l'ordine che si ottiene risalendo via via le gerarchie delle classi
    ~Contenitore();

    int getQt () {
        return qt;
    }
protected:
    void versa(int lt);
    void togli(int lt);
};

Contenitore::Contenitore(int qt) {
    this -> qt = qt;
}

Contenitore::~Contenitore() {

}

void Contenitore::versa(int lt) {
    this -> qt = qt + lt;
}

void Contenitore::togli(int lt) {
    this -> qt = qt - lt;
}

#endif //ASD_CONTENITORE_H
