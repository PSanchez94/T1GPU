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


TEST_F(PuntoTest, TestFloatDefaultConstructor) {
    EXPECT_EQ(_float_punto.getX(), 0);
    EXPECT_EQ(_float_punto.getY(), 0);
}

TEST_F(PuntoTest, TestFloatType) {
    EXPECT_EQ(typeid(float), typeid(_float_punto.getX()));
    EXPECT_EQ(typeid(float), typeid(_float_punto.getY()));
}

TEST_F(PuntoTest, TestFloatConstructorWithValues) {
    Punto<float> float_punto = Punto<float>(10.0, 10.0);

    EXPECT_EQ(float_punto.getX(), 10.0);
    EXPECT_EQ(float_punto.getY(), 10.0);
}

TEST_F(PuntoTest, TestFloatConstructorWithVariables) {
    float x = 10.0;
    float y = 10.0;

    Punto<float> float_punto = Punto<float>(x, y);

    EXPECT_EQ(float_punto.getX(), x);
    EXPECT_EQ(float_punto.getY(), y);
}

TEST_F(PuntoTest, TestFloatSettersWithValues) {
    _float_punto.setX(10.0);
    _float_punto.setY(10.0);

    EXPECT_EQ(_float_punto.getX(), 10.0);
    EXPECT_EQ(_float_punto.getY(), 10.0);
}

TEST_F(PuntoTest, TestFloatSettersWithVariables) {
    float x = 10.0;
    float y = 10.0;

    _float_punto.setX(x);
    _float_punto.setY(y);

    EXPECT_EQ(_float_punto.getX(), x);
    EXPECT_EQ(_float_punto.getY(), y);
}

