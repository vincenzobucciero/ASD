//
// Created by vincenzo on 07/12/22.
//

#ifndef ASD_POLYMORF_H
#define ASD_POLYMORF_H

#include <iostream>

using namespace std;

class Parent {
public:
    void doA () {
        cout << "doA in Parent" << endl;
    }
    //dichiarata virtual per effettuare polimorfismo
    virtual void doB () {
        cout << "doB in Parent" << endl;
    }
};

class Child : public Parent {
public:
    void doA () {
        cout << "doA in Child" << endl;
    }
    void doB () {
        cout << "doB in Child" << endl;
    }
};

#endif //ASD_POLYMORF_H
