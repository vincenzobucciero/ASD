//
// Created by vincenzo on 16/12/22.
//

/*
 *  Un'azienda è quotata in borsa.
 *  Si supponga di avere un array A[1...N] contenente la quotazione
 *  delle azioni in un periodo di N giorni e che A[1]<A[N]. È possibile dimostrare
 *  che esiste almeno una coppia di giorni consecutivi i, i+1 tali che A[i]<A[i+1].

 *  Progettare ed implementare un algoritmo divide-et-impera che
 *  trovi un indice i che verifichi la condizione data.

 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search(vector<int> vec, int inizio, int fine) {
    if (inizio +1 == fine || vec.at(inizio) < vec.at(inizio+1))     //caso base
        return inizio;
    //se non ci troviamo nel caso base, calcoliamo il mediano
    int mediano = (inizio+fine)/2;

    //a questo punto, se la condizione della traccia, è verificata, effettuo la ricerca nel sottoarray di sx
    //altrimenti proseguo nel sottoarray di destra

    if (vec.at(inizio) < vec.at(mediano))
        return search(vec, inizio, mediano-1);
    return search(vec, mediano+1, fine);
}

int main() {

    /*
     * Approccio divide-et-impera
     * Divisione del problema originale in sottoproblemi di dimensione minore
     * fino ad arrivare al caso base, tutto risolvibile tramite chiamate ricorsive.
     *
     * Prendere come parametri in input, l'array ordinato e come indici l'inizio e la fine dell'array
     * Inizialmente controllo il caso base cioè che nel vector ci siano solo due elementi,
     * o anche se abbiamo gia trovato la soluzione, ricordandoci che in realà noi usciremo dal loop
     * della ricorsione soltanto quando uno dei due casi base si verificherà.

     */

    vector<int> vec = {15,24,10,1,36,58};

    int ris = search(vec,0,6);

    cout << ris << endl;
    cout << vec.at(ris) << endl;
    cout << vec.at(ris+1) << endl;
}

