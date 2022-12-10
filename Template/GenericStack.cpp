//
// Created by vincenzo on 09/12/22.
//

#include "Stack.h"
#include <iostream>

using namespace std;

int main () {
    int N;
    float F;
    Stack<int> Sti;
    Stack<float> Stf;
    Sti.push(25);
    Stf.push(3.141592);
    if (Sti.pop(N) ) cout << N << endl;
    if (Stf.pop(F) ) cout << F << endl;

    return 0;
}
