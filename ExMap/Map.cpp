//
// Created by vincenzo on 12/12/22.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main () {
    map<string, int> amap;
    amap["Primo"] = 1;
    amap["Secondo"] = 2;
    cout << amap.size() << endl;
    amap["Terzo"] = 3;
    amap["Quarto"] = 4;
    //metodo per inserire
    amap.insert(pair<string, int>(string("Quinto"), 5));
    //metodo per inserire
    amap.insert(make_pair("Sesto", 6));
    cout << amap.size() << endl;

    map<string, int>::iterator it;
    for (it = amap.begin(); it != amap.end() ; ++it) {
        cout << "map:  " << it->first << " " << it->second << endl;
    }


    //Metodo di ricerca che restituisce il valore passando alla find la chiave
    cout << amap.find("Terzo")->second << endl;
    //Metodo di ricerca che restituisce il valore
    cout << amap.at("Quinto") << endl;

    amap.clear();

    return 0;
}
