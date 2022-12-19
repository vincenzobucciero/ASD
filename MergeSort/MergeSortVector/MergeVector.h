//
// Created by vincenzo on 19/12/22.
//

#ifndef ASD_MERGEVECTOR_H
#define ASD_MERGEVECTOR_H

#include <iostream>
#include <vector>

using namespace std;

//Riscrivere il Merge Sort utilizzando il contenitore Vector ed un iteratore

template <typename T>
class MergeVector {
private:
    static void merge(typename vector<T>::iterator begin, typename vector<T>::iterator med, typename vector<T>::iterator end);
public:
    static void MergeSortVector(typename  vector<T>::iterator begin, typename vector<T>::iterator end);
};


template <typename T>
void MergeVector<T>::merge(typename vector<T>::iterator begin, typename vector<T>::iterator med, typename vector<T>::iterator end) {
    //n indica la distanza tra left e right, cioe il size del vector
    auto n = end-begin;

    auto indice = (int) (n/2)-1;

    vector<T> aux(n);
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;
    typename vector<T>::iterator k;

    for (i = med-1; i != begin-1; i--)
        aux.at(indice--) = *i;

    indice = n;

    for (j = med; j != end; j++)
        aux.at(indice--) = *j;

    // a differenza del classico merge qui prima di andare a fare la fusione dei vector ordinati
    // prima ho bisogno di far puntare i rispettivi iteratori al posto giusto, quindi:
    // i punta al primo elemento del vector e j all'ultimo elemento
    i = aux.begin();
    j = aux.end() - 1;

    for ( k = begin; k != end; k++ )
        if ( *j < *i )
            *k = *j--;
        else
            *k = *i++;
}

template<typename T>
void MergeVector<T>::MergeSortVector(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
    //non posso passare come parametro l'array intero perché non si aggiorna
    //si preferisce dunque lavorare unicamente con gli iteratori
    auto size = end-begin;

    if(size >= 2)
    {
        auto med = begin;
        advance(med,size/2);

        MergeSortVector(begin, end);
        MergeSortVector(med, end);
        merge(begin, med, end);
    }
}

#endif //ASD_MERGEVECTOR_H
