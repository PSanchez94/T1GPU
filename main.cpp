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

    while (!(cin >> *lp)) {
        cin.clear();
        cin.ignore(40,'\n');
        std::cout << "Invalid argument. Does not seem to be a number.\n";
        std::cout << "Try to input a Punto again.\n";
    }
    while (!(cin >> *mp)) {
        cin.clear();
        cin.ignore(40,'\n');
        std::cout << "Invalid argument. Does not seem to be a number.\n";
        std::cout << "Try to input a Punto again.\n";
    }
    while (!(cin >> *rp)) {
        cin.clear();
        cin.ignore(40,'\n');
        std::cout << "Invalid argument. Does not seem to be a number.\n";
        std::cout << "Try to input a Punto again.\n";
    }

    main_poligono = new Poligono<float>(lp, mp, rp);
    cout << *main_poligono;

    cout << "Endless loop." << endl;
    while (true) {
        cout << "Enter X and Y values to append to the Poligono." << endl;
        cin >> *main_poligono;
        cout << *main_poligono;
    }
}
