//
// Created by vincenzo on 19/12/22.
//

#include <iostream>
#include <vector>
#include "MergeSort.h"

using namespace std;


int main(){
    vector<int> A = {9,7,3,1};
    //typename vector<int>::iterator it = A;

    Algoritmi<int> :: mergeSort(A.begin(), A.end());

    for(auto &v:A)
        cout<<v<<" ";


    return 0;
}