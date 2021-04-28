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

    // Setters
    numType setX(numType in_x) { x = in_x; }
    numType setY(numType in_y) { y = in_y; }
};


#endif //PUNTO_HPP
