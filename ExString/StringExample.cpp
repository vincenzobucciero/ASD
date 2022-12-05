//
// Created by vincenzo on 05/12/22.
//

//How to use string

#include <iostream>
#include <string>   //gestione delle stringhe

using namespace std;

int main () {
    //dichiarazione variabile tipo stringa
    string s1;
    string s2;
    //dichiarazione e inizializzazione
    string s3 = "Ciao a tutti!";
    //altro modo per inizializzare
    string s4 ("Io sono ");

    s2 = "funzionante";

    s1 = s3 + " " + s4;     //concatenazione di stringhe

    s1 += "Un programma C++ " ;      //appending di una stringa

    cout << s1 + s2 + " !";

    //confronto tra stringhe
    string s5 = "giaguaro";
    string s6 = "giaguaro";

    if (s5 == s6) cout << "\n" + s5 << " é uguale a " << s6 << endl;
    if (s5 < s6) cout << s5 << " precede " << s6 << endl;
    if (s5 > s6) cout << s5 << " segue " << s6 << endl;

    //lunghezza stringa .size()
    string s7 ("Ciao Mondo");
    cout << "la lunghezza di " + s7 + " con .size() è: " << s7.size();
    //lunghezza stringa .length()
    cout << "\nla lunghezza di " + s7 + " con .length è: " << s7.length();

    //cancellazione di una stringa
    string s8 = "Mi chiamo Vincenzo";
    cout << "\n Stringa originale: " + s8 + " -> " ;
    s8.erase(0, 2);     //cancella n caratteri a partire dall'i-esimo'
    cout << "Stringa tagliata con s8.erase[0, 2]: " + s8 << endl;
    //s8.erase(n) -> cancella i caratteri della stringa dopo n-esimo
    //s8.erase() -> cancella tutta la stringa

    //s8.insert() -> permette di inserire caratteri all’ interno di una stringa
    //s8.c_str() -> restituisce l'array di char
    //s8.find() -> permette di cercare una sottostringa in una stringa
    //s8.replace() -> permette di sostituire una sottostringa in una stringa

    string s9 = "45ABC";
    string s10 = "3.145625.32";
    string s11 = "words";

    //stoi() -> string to integer
    int N1 = stoi(s9); cout << N1 << endl;
    //stof() -> string to float
    float N2 = stof(s10); cout << N2 << endl;
    //genera errore
    //int N3 = stoi(s11); cout << N3 << endl;



    return 0;
}
