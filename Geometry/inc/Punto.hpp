/*
@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#ifndef PUNTO_HPP
#define PUNTO_HPP

#include "TwoDPoint.hpp"


/*
Class implementation of a point in two dimensions, X and Y.
/**/
template <class numType>
class Punto : public TwoDPoint<numType> {
    using TwoDPoint<numType>::x;
    using TwoDPoint<numType>::y;


private:
    typedef TwoDPoint<numType> inherited;


public:
    // Constructors
    using TwoDPoint<numType>::TwoDPoint;
    ~Punto() = default;

    // Sum point operator
    Punto<numType> operator+(const Punto<numType> &p) {
        x += p.getX(); y += p.getY();
        return *this;
    }

    // Sum by scalar operator
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

    // cout operator
    friend std::ostream &operator<<( std::ostream &output, const Punto<numType> &p ) {
        output << "Punto: " << "X: " << p.x << ", Y: " << p.y << std::endl;
        return output;
    }
};


#endif //PUNTO_HPP
