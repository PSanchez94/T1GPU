/*

@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Punto.hpp"

class PuntoTest : public::testing::Test {
protected:

    Punto<float> _float_punto;

    void SetUp() override {

    }

    void TearDown() override {

    }

};


TEST_F(PuntoTest, TestDefaultFloatConstructor) {
    ASSERT_EQ(_float_punto.getX(), 0);
    ASSERT_EQ(_float_punto.getY(), 0);
}

TEST_F(PuntoTest, TestFloatConstructorWithValues) {
    Punto<float> float_punto = Punto<float>(10.0, 10.0);

    ASSERT_EQ(float_punto.getX(), 10.0);
    ASSERT_EQ(float_punto.getY(), 10.0);
}

TEST_F(PuntoTest, TestFloatConstructorWithVariables) {
    float x = 10.0;
    float y = 10.0;

    Punto<float> float_punto = Punto<float>(x, y);

    ASSERT_EQ(float_punto.getX(), x);
    ASSERT_EQ(float_punto.getY(), y);
}
