//
// Created by vincenzo on 14/12/22.
//

//Test class for bubblesort

#include "Bubble.h"
#include <vector>

void visArrayVec(vector<int> vec) {
    for (auto x: vec) {
        std::cout << x << " ";
    }
}

void visArraySeq(int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
}


int main () {
    int a[] = {5, 12, 4, 7, 6, 9, 3,8};
    //cout << "\nArray prima dell'ordinamento:  " << endl;
    //Viasalizza array con vector ----> dichiarare vector<int> a = {5, 12, 4, 7, 6, 9, 3};
    //visArrayVec(a);
    Bubble::bubble(a,0,7);
    cout << "\nArray dopo l'ordinamento:  " << endl;
    visArraySeq(a,8);
    //richiamo metodo per contare gli scambi effettuati
    std::cout << "\nScambi effettuati:  " << Bubble::getCont()
    << endl;
}
