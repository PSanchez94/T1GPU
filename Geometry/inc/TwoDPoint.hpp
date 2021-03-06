/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#ifndef TWODPOINT_HPP
#define TWODPOINT_HPP

/*
Abstract class for implementation of a point in two dimensions, X and Y.
Defines X, Y, getters and equal operators.
/**/
template <class numType>
class TwoDPoint {
protected:
    numType x, y;


public:
    // Constructors
    TwoDPoint() : x(0), y(0) { };
    TwoDPoint(numType x, numType y) : x(x), y(y) { };

    // Destructor
    ~TwoDPoint() = default;

    // Getters
    numType getX() const { return x; }
    numType getY() const { return y; }

    // Setters
    virtual void setXY(numType in_x, numType in_y) { };

    // Equal operators
    bool operator==(const TwoDPoint<numType> &rp) const {
        return (this->x == rp.getX()) && (this->y == rp.getY());
    }

    bool operator!=(const TwoDPoint<numType> &p) const {
        return !(*this == p);
    }

    // cin operator
    friend std::istream &operator>>( std::istream  &input, TwoDPoint<numType> &p ) {
        input >> p.x >> p.y;
        return input;
    }

    // cout operator
    friend std::ostream &operator<<( std::ostream &output, const TwoDPoint<numType> &p ) {
        output << "X: " << p.x << ", Y: " << p.y << std::endl;
        return output;
    }
};


#endif //TWODPOINT_HPP
