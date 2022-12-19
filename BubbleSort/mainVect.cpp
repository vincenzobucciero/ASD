//
// Created by vincenzo on 14/12/22.
//

//test for bubble sort with vector

#include "BubbleVect.h"


void visuaArrayVect(std::vector<int> A) {
    for (auto x: A) {
        cout << x << " ";
    }
}

int main () {
    vector<int> A = {8,7,5,1,4,3,19};
    std::cout << "Array prima dell 'ordinamento:  " << endl;
    visuaArrayVect(A);

    BubbleVect::bubblevect<int>(A.begin(), A.end()-1);
    std::cout << "\nArray dopo l'ordinamento:  " << endl;
    visuaArrayVect(A);
}
