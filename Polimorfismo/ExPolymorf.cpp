//
// Created by vincenzo on 07/12/22.
//

#include <iostream>
#include "Polymorf.h"

using namespace std;

int main () {
    Parent* p1 = new Parent();
    Parent* p2 = new Child();
    Child* ch = new Child();

    p1->doA();
    p2->doA();
    ch->doA();

    p1->doB();
    p2->doB();
    ch->doB();
}
