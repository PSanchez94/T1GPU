/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>

#include "TwoDPoint.hpp"


/*
Class implementation of a point in two dimensions, X and Y.
/**/
template <class numType>
class Vector : public TwoDPoint<numType> {
    using TwoDPoint<numType>::x;
    using TwoDPoint<numType>::y;

private:
    typedef TwoDPoint<numType> inherited;

    // Normalize
    void normalize() {
        numType length = sqrt(x*x + y*y);
        x /= length; y /= length;
    }

public:
    // Constructors
    using TwoDPoint<numType>::TwoDPoint;
    ~Vector() = default;
    // Construction from two points
    Vector(TwoDPoint<numType> *lp, TwoDPoint<numType> *rp) {
        x = rp->getX() - lp->getX();
        y = rp->getY() - lp->getY();
        normalize();
    }

    // cout operator
    friend std::ostream &operator<<( std::ostream &output, const Vector<numType> &v ) {
        output << "Vector: " << "X: " << v.x << ", Y: " << v.y << std::endl;
        return output;
    }

    /*
    // Producto punto
    numType prodPunto(Vector<numType> *v) {
        return (x * v->X) + (y * v->Y);
    };

    // Producto cruz
    numType prodCruz(Vector<numType> *v) {
        return (x * v->Y) - (y * v->X);
    };
    /**/
};


#endif //VECTOR_HPP
