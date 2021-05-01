/*

@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#include <iostream>
#include <sstream>

#include "Poligono.hpp"

Poligono<float>* main_poligono;

int main() {
    Punto<float>* lp = new Punto<float>();
    Punto<float>* mp = new Punto<float>();
    Punto<float>* rp = new Punto<float>();

    std::cout << "Implementation of Poligono Class" << std::endl;
    std::cout << "A Poligono must have at least 3 points." << std::endl;
    std::cout << "Enter X and Y values for the first 3 Puntos." << std::endl;
    std::cout << "Press enter when done." << std::endl;

    std::cin >> *lp >> *mp >> *rp;

    main_poligono = new Poligono<float>(lp, mp, rp);
    std::cout << *main_poligono;

    std::cout << "Press enter to end the program or input X and Y values" << std::endl;
    std::cout << "to append a Punto to the Poligono." << std::endl;

    while (true) {
        std::cin >> *main_poligono;
        std::cout << *main_poligono;
    }

    return 0;
}
