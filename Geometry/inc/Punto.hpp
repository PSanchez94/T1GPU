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

    // Destructor
    ~Punto() = default;

    // Getters
    numType getX() const { return x; }
    numType getY() const { return y; }

    // Setters
    void setX(numType in_x) { x = in_x; }
    void setY(numType in_y) { y = in_y; }
    void setXY(numType in_x, numType in_y) { setX(in_x); setY(in_y); }

    // Equal operators
    bool operator==(const Punto<numType> &rp) const {
        return (this->x == rp.getX()) && (this->y == rp.getY());
    }

    bool operator!=(const Punto<numType> &p) const {
        return !(*this == p);
    }

    // Sum point operator
    Punto<numType> operator+(const Punto<numType> &p) {
        x += p.getX(); y += p.getY();
        return *this;
    }

    // Sum scalar operator
    Punto<numType> operator+(const numType &n) {
        x += n; y += n;
        return *this;
    }

    // Subtraction point operator
    Punto<numType> operator-(const Punto<numType> &p) {
        x -= p.getX(); y -= p.getY();
        return *this;
    }

    // Subtraction by scalar operator
    Punto<numType> operator-(const numType &n) {
        x -= n; y -= n;
        return *this;
    }

    // Multiplication by scalar operator
    Punto<numType> operator*(const numType &n) {
        x *= n; y *= n;
        return *this;
    }

    // cin operator

    // cout operator


};


#endif //PUNTO_HPP
