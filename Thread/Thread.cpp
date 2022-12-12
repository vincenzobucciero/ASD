//
// Created by vincenzo on 12/12/22.
//


//task -> calcolo potenzialmente eseguibile in concorrenza con altri
//thread -> rappresemtazione system-level di una task in un programma

#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

//dichiaarzione mutex, oggetto usato per rappresentare il diritto di accedere in maniera esclusiva ad una risorsa
mutex mymutex;

void Funz1 () {
    mymutex.lock();
    cout << "Sono il primo thread" << endl;
    mymutex.unlock();
}
void Funz2 () {
    mymutex.lock();
    cout << "Sono il secondo thread" << endl;
    mymutex.unlock();
}

int main () {
    //parametro passato per indirizzo
    thread th1 { Funz1 };
    thread th2 { Funz2 };

    th1.join();
    th2.join();
}



