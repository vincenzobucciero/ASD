//
// created by vincenzo on 30/12/22
//

/*
    • Dato un array di n elementi, trovare il massimo numero di
        elementi distinti dopo aver rimosso k elementi (k<=n)
*/

//ELIMINARE I NUMERI CHE SI RIPETONO PIU VOLTE
//EX. A = [5,4,4,3,4,6,2,1,2]  => PER K = 2  => A = [5,3,4,6,2,1,2]

#include <iostream>
#include <vector>
#include <map>

#include "/home/vincenzo/Scrivania/asd/ASD/PriorityQueue/Esercizio02/MaxPriorityQueue.h"

using namespace std;

int main() {
    vector<int> seq = {5,4,4,3,4,6,2,1,2};
    const int k = 2;

    cout << "K =  " << k << endl;

    //per contare le occorrenze uìsi utilizza una mappa
    map<int, int> amap;
    map<int, int>::iterator cii;
    int num;

    //conto occorrenze
    for(int i = 0; i < seq.size(); i++) {
        num = seq.at(i);

        cii = amap.find(num);
        if ( cii == amap.end())
            amap.insert(make_pair(num,1));
        else   
            amap.at(num)++;
    }

    map<int,int>::iterator it;
    for ( it = amap.begin(); it != amap.end(); it++)
        cout << "map [" << it->first << "] = " << it->second << endl;


    MaxPriorityQueue<int> maxQueue;
    for ( cii = amap.begin(); cii != amap.end(); cii++)
        maxQueue.queueInsert(cii->second);

    maxQueue.printAsciiTree();

    vector<int>::iterator its = seq.begin();

    int z = 0;
    while (seq.size() > k){
        cout << endl << "i=" << z++ << endl;

        for (int l=0; l<k; l++){
            int max = maxQueue.maximum(), j = 0;

            its = seq.begin();
            cii = amap.begin();

            while ( max != cii->second ) cii++;
            while ( cii->first != *its ) its++;

            seq.erase(its);
            cii->second--;
            maxQueue.decreaseKey(0,max-1);
        }

        for ( int i=0; i<seq.size(); i++)
            cout << "seq [" << i << "] = " << seq.at(i) << endl;
        
    }

  return 0;
}