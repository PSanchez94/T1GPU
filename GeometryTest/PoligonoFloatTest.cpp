/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Poligono.hpp"


class VectorFloatTest : public::testing::Test {
protected:
    Punto<float> lp = Punto<float>(1.0, 1.0);
    Punto<float> mp = Punto<float>(2.0, 2.0);
    Punto<float> rp = Punto<float>(3.0, 3.0);

    Poligono<float> _actual_poligono = Poligono<float>(&lp, &mp, &rp);

    void SetUp() override { }

    void TearDown() override { }

};
