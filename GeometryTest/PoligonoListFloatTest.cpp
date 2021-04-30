/*

@date: 30-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Poligono.hpp"

class PoligonoListFloatTest : public::testing::Test {
protected:

    Punto<float> lp = Punto<float>(1.0, 1.0);
    Punto<float> mp = Punto<float>(2.0, 2.0);
    Punto<float> rp = Punto<float>(3.0, 3.0);

    PoligonoList<float> _actual_list = PoligonoList<float>(&lp, &mp, &rp);

    void SetUp() override { }

    void TearDown() override { }

};


TEST_F(PoligonoListFloatTest, TestDefaultConstructor) {
    std::cout << *_actual_list.getHead();
    EXPECT_EQ(_actual_list.getSize(), 3);
}