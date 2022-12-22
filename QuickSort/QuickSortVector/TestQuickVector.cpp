//
// creator by vincenzo on 22/12/22
//

//test for quicksort with vector

#include "QuickSortVector.h"
#include <vector>
#include <iostream>

using namespace std;

int main () {
    vector<int> vec = {8,4,5,2,6};

    vector<int>::iterator it;

    cout << "Vector prima sort:  " << endl;
    for(it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }

    QuickSortVector<int>::quicksortVector(vec.begin(), vec.end()-1);

    cout << "\nVector dopo sort:  " << endl;
    for(it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }

}