/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#ifndef VECTOR_HPP
#define VECTOR_HPP

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

public:
    // Constructors
    using TwoDPoint<numType>::TwoDPoint;
    ~Vector() = default;

    // cout operator
    friend std::ostream &operator<<( std::ostream &output, const Vector<numType> &v ) {
        output << "Vector: " << "X: " << v.x << ", Y: " << v.y << std::endl;
        return output;
    }
};


#endif //VECTOR_HPP
