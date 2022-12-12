//
// Created by vincenzo on 12/12/22.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
int main () {
    vector<int> v;
    const int n = 10;
    for (int i = 1; i <= n ; ++i) {
        v.push_back(i);
    }
    for (int i = n-1; i >= 0 ; --i) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size();

    return 0;
}
*/

/*
int main () {
    //dichiarazione contenitore vector
    vector<int> v;
    //metodo .push_back(arg) per inserire elementi
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " , ";

    cout << endl;

    for (int i = 0; i < v.size(); ++i)
        v[i] = v[i] * 10;

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " , ";


    return 0;
}
 */


/*
 * COPIA DI FILE SU VETTORI DI STRINGHE
int main () {
    vector<string> v;

    ifstream in ("Vector.cpp");
    string line;

    while (getline(in, line))
        v.push_back(line);

    for (int i = 0; i < v.size(); ++i) {
        cout << i << ":  " << v[i] << endl;
    }

    return 0;
}
 */


/*
 * SEPARAZIONE DELLE PAROLE
int main () {
    vector<string> v;
    ifstream in ("GetWords.cpp");
    string word;

    while (in >> word)
        v.push_back(word);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    return 0;
}
 */
