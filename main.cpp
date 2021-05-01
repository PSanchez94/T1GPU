/*

@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#include <iostream>
#include <sstream>

#include "Poligono.hpp"

using namespace std;

Poligono<float>* main_poligono;

int main() {
    Punto<float>* lp = new Punto<float>();
    Punto<float>* mp = new Punto<float>();
    Punto<float>* rp = new Punto<float>();

    cout << "Implementation of Poligono Class" << endl;
    cout << "A Poligono must have at least 3 points." << endl;
    cout << "Enter X and Y values for the first 3 Puntos." << endl;
    cout << "Press enter when done." << endl;

    cin >> *lp >> *mp >> *rp;

    main_poligono = new Poligono<float>(lp, mp, rp);
    cout << *main_poligono;

    cout << "Press enter to end the program or input X and Y values" << endl;
    cout << "to append a Punto to the Poligono." << endl;

    while (true) {
        cin >> *main_poligono;
        cout << *main_poligono;
    }

    return 0;
}
