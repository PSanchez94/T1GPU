/*
@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#ifndef PUNTO_HPP
#define PUNTO_HPP


#include <iostream>


template <class numType>
class Punto {
    numType x, y;

public:
    // Constructors
    Punto() : x(0), y(0) { };
    Punto(numType x, numType y) : x(x), y(y) { };

    // Getters
    numType getX() { return x; }
    numType getY() { return y; }

    // TODO: Do we need setters?
};


#endif //PUNTO_HPP
