/*

@date: 27-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Punto.hpp"

class PuntoFloatTest : public::testing::Test {
protected:

    Punto<float> _actual_float_punto;
    Punto<float> _expected_float_punto;

    void SetUp() override { }

    void TearDown() override { }

};


TEST_F(PuntoFloatTest, TestDefaultConstructor) {
    EXPECT_EQ(_actual_float_punto.getX(), 0);
    EXPECT_EQ(_actual_float_punto.getY(), 0);
}

TEST_F(PuntoFloatTest, TestType) {
    EXPECT_EQ(typeid(float), typeid(_actual_float_punto.getX()));
    EXPECT_EQ(typeid(float), typeid(_actual_float_punto.getY()));
}

TEST_F(PuntoFloatTest, TestConstructorWithValues) {
    _actual_float_punto = Punto<float>(10.0, 20.0);

    EXPECT_EQ(_actual_float_punto.getX(), 10.0);
    EXPECT_EQ(_actual_float_punto.getY(), 20.0);
}

TEST_F(PuntoFloatTest, TestConstructorWithVariables) {
    float x = 10.0;
    float y = 20.0;
    _actual_float_punto = Punto<float>(x, y);

    EXPECT_EQ(_actual_float_punto.getX(), x);
    EXPECT_EQ(_actual_float_punto.getY(), y);
}

TEST_F(PuntoFloatTest, TestSettersWithValues) {
    _actual_float_punto.setXY(10.0, 20.0);

    EXPECT_EQ(_actual_float_punto.getX(), 10.0);
    EXPECT_EQ(_actual_float_punto.getY(), 20.0);
}

TEST_F(PuntoFloatTest, TestSettersWithVariables) {
    float x = 10.0;
    float y = 10.0;
    _actual_float_punto.setXY(x, y);

    EXPECT_EQ(_actual_float_punto.getX(), x);
    EXPECT_EQ(_actual_float_punto.getY(), y);
}

TEST_F(PuntoFloatTest, TestEqualPoints) {
    _expected_float_punto = Punto<float>(10.0, 20.0);
    _actual_float_punto.setXY(10.0, 20.0);

    EXPECT_TRUE(_actual_float_punto == _expected_float_punto);

    _expected_float_punto.setXY(20.0, 10.0);

    EXPECT_TRUE(_actual_float_punto != _expected_float_punto);
}

TEST_F(PuntoFloatTest, TestSumTwoPoints) {
    _expected_float_punto.setXY(10.0, 10.0);
    Punto<float> float_punto = Punto<float>(5.0, 5.0);

    _actual_float_punto.setXY(5.0, 5.0);

    EXPECT_EQ(_actual_float_punto + float_punto, _expected_float_punto);
}

TEST_F(PuntoFloatTest, TestSumPointAndScalar) {
    _expected_float_punto.setXY(10.0, 10.0);
    float a_float = 5.0;

    _actual_float_punto.setXY(5.0, 5.0);

    EXPECT_EQ(_actual_float_punto + a_float, _expected_float_punto);
}

TEST_F(PuntoFloatTest, TestSubtractTwoPoints) {
    _expected_float_punto.setXY(10.0, 10.0);
    Punto<float> float_punto = Punto<float>(5.0, 5.0);

    _actual_float_punto.setXY(15.0, 15.0);

    EXPECT_EQ(_actual_float_punto - float_punto, _expected_float_punto);

    _expected_float_punto.setXY(-10.0, -10.0);
    float_punto = Punto<float>(20.0, 20.0);

    EXPECT_EQ(_actual_float_punto - float_punto, _expected_float_punto);
}

TEST_F(PuntoFloatTest, TestSubtractPointAndScalar) {
    _expected_float_punto.setXY(10.0, 10.0);
    float a_float = 5.0;

    _actual_float_punto.setXY(15.0, 15.0);

    EXPECT_EQ(_actual_float_punto - a_float, _expected_float_punto);

    _expected_float_punto.setXY(-10.0, -10.0);
    a_float = 20.0;

    EXPECT_EQ(_actual_float_punto - a_float, _expected_float_punto);
}

TEST_F(PuntoFloatTest, TestMultPointAndScalar) {
    _expected_float_punto.setXY(10.0, 10.0);
    float a_float = 2.0;

    _actual_float_punto.setXY(5.0, 5.0);

    EXPECT_EQ(_actual_float_punto * a_float, _expected_float_punto);
}