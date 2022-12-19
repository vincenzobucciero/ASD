//
// Created by vincenzo on 19/12/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
void merge(vector<T>& v, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<T> L(n1), R(n2);
    for (i = 0; i < n1; i++) {
        L[i] = v[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = v[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}
template <typename T>
void mergeSort(vector<T>& v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
template <typename T>
void mergeSort(vector<T>& v) {
    mergeSort(v, 0, v.size() - 1);
}
template <typename T>
void mergeSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    vector<T> v(begin, end);
    mergeSort(v);
    for (int i = 0; i < v.size(); i++) {
        *(begin + i) = v[i];
    }
}

int main() {
    vector<int> v = {12, 11, 13, 5, 6, 7};
    //errore
    mergeSort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}