//
// created by vincenzo on 02/01/23
//

/*
    • Progettare ed implementare un algoritmo che dato in input un
        array di stringhe le ordini in modo che ogni stringa sia una
        sottostringa delle successive

    • Es.: [palmare, re, spalmare, mare]

        re
        mare
        palmare
        spalmare
*/

#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CountingSortString {
    private:
        static int getMaxString(vector<string> A);
        static bool isSubString(vector<string> *A);
    public:
        static void countingSortString(vector<string> *A);
        static void printArray(vector<string> A);
};

int CountingSortString::getMaxString(vector<string> A) {
    int max = A.at(0).length();

    for(int i = 1; i < A.size(); i++) {
        if(A.at(i).length() > max)
            max = A.at(i).length();
    }

    return max;
}

bool CountingSortString::isSubString(vector<string> *A) {
    for(int i = 0; i < A->size()-1; i++) {
        auto it = A->at(i+1).find(A->at(i));
        if(it == string::npos)
            return false;
    }
    return true;
}

void CountingSortString::countingSortString(vector<string> *A) {
    int sizeA = A->size();
    int max = getMaxString(*A);
    int sizeC = max+1;

    vector<int> count(sizeC);
    vector<string> output(sizeA);

    for(int i = 0; i < sizeC; i++)
        count.at(i) = 0;
    for(int i = 0; i < sizeA; i++)
        count.at(A->at(i).length())++;
    for(int i = 1; i < sizeC; i++)
        count.at(i) += count.at(i-1);
    for(int i = sizeA-1; i >= 0; i--) {
        output.at(count.at(A->at(i).length())-1) = A->at(i);
        count.at(A->at(i).length())--;
    }

    if(isSubString(A)) {
        for(int i = 0; i < sizeA; i++)
            A->at(i) = output.at(i);
    } else 
        cout << "non è una sottostringa" << endl;
}

void CountingSortString::printArray(vector<string> A) {
    cout << endl;
    for(auto i : A)
        cout << i << " ";
    cout << endl;
}




#endif //SUBSTRING_H