//
// Created by vincenzo on 04/12/22.
//

/*
 *  È un Contenitore: ha un attributo capacita che definisce la
    capienza dell'anfora, un metodo getCapacita() che restituisce
    questo valore, un metodo riempi() per riempirla, un metodo
    svuota() per svuotarla, due metodi isVuota() e isPiena() che
    restituiscono lo stato dell'anfora ed un metodo
    spostaContenuto(Anfora) che sposta l'acqua nell'anfora
    passata come argomento.
 */

#ifndef ASD_ANFORA_H
#define ASD_ANFORA_H

#include "Contenitore.h"
#include <iostream>

using namespace std;

class Anfora: public Contenitore {
private:
    int const capacita;

    //metodi privati poichè utilizzati solo dalla classe Anfora
    bool isVuota();
    bool isPiena();
public:
    Anfora(int capacita, int qt);
    ~Anfora();

    int getCapacita () {
        return capacita;
    }

    void riempi ();
    void svuota ();

    //Anfora passata come argomento
    void spostaContenuto (Anfora &a);
};

//quando vine definito un oggetto di una classe derivata, viene sempre invocato il cpstruttore della classe base
Anfora::Anfora(int capacita, int qt): Contenitore(qt),capacita(capacita) {

}

Anfora::~Anfora() {

}

bool Anfora::isPiena() {
    if (this -> getQt() == this -> getCapacita())
        return true;
    else
        return false;
}

bool Anfora::isVuota() {
    if (this -> getQt() == 0)
        return true;
    else
        return false;
}

void Anfora::riempi() {
    this -> versa(this -> getCapacita() - this -> getQt());
}

void Anfora::svuota() {
    this ->togli(this -> getQt());
}

void Anfora::spostaContenuto(Anfora &a) {
    //Se l'anfora dal quale prendiamo acqua non è vuota
    if (!this -> isVuota()) {
        //Se l'anfora dove mettiamo acqua non è piena
        if (!a.isPiena()){
            //prendo i lt che posso inserire nell'anfora passata in input
            //nel caso sia vuota, prendo la capacita
            int lt = a.getCapacita() - a.getQt();
            // nel caso in cui questi litri siamo maggiori di quello che
            // dobbiamo andare a versare allora versa
            // la qt presente nell'Anfora che usiamo per versare
            if (lt > this -> getQt())
                lt = this -> getQt();

            a.versa(lt);
            this ->togli(lt);
        }
    }
}

#endif //ASD_ANFORA_H
