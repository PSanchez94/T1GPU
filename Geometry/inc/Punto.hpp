/*
@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#ifndef PUNTO_HPP
#define PUNTO_HPP


#include <iostream>

/*
Class implementation of a point in two dimensions, X and Y.
/**/
template <class numType>
class Punto {
    numType x, y;

public:
    // Constructors
    Punto() : x(0), y(0) { };
    Punto(numType x, numType y) : x(x), y(y) { };

    // Getters
    numType getX() const { return x; }
    numType getY() const { return y; }

    // Setters
    void setX(numType in_x) { x = in_x; }
    void setY(numType in_y) { y = in_y; }

    // Equal operators
    bool operator==(const Punto<numType> &rp) const {
        return (this->getX() == rp.getX()) && (this->getY() == rp.getY());
    }

    bool operator!=(const Punto<numType> &p) const {
        return !(*this == p);
    }

    // Sum operator
    /*
    Punto<numType> operator+(Punto<numType> p) {
        return ;
    }
    /**/

    // Substraction operator
};


#endif //PUNTO_HPP
