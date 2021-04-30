/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#include <cmath>

#include <gtest/gtest.h>

#include "Vector.hpp"
#include "Punto.hpp"


class VectorFloatTest : public::testing::Test {
protected:
    Punto<float> lpunto = Punto<float>(0.0, 0.0);
    Punto<float> rpunto = Punto<float>(1.0, 1.0);

    Vector<float> _actual_float_vector;
    Vector<float> _expected_float_vector;

    float _vec_val = 1/sqrt(2);

    void SetUp() override { }

    void TearDown() override { }

};


TEST_F(VectorFloatTest, TestDefaultConstructor) {
    EXPECT_EQ(_actual_float_vector.getX(), 0);
    EXPECT_EQ(_actual_float_vector.getY(), 0);
}

TEST_F(VectorFloatTest, TestTwoDPointConstructor) {
    _actual_float_vector = Vector<float>(&lpunto, &rpunto);

    _expected_float_vector.setXY(_vec_val, _vec_val);

    EXPECT_EQ(_actual_float_vector, _expected_float_vector);

    rpunto.setXY(0.0, 10.0);
    _expected_float_vector.setXY(0.0, 1.0);

    _actual_float_vector = Vector<float>(&lpunto, &rpunto);
    EXPECT_EQ(_actual_float_vector, _expected_float_vector);


    rpunto.setXY(0.0, -10.0);
    _expected_float_vector.setXY(0.0, -1.0);

    _actual_float_vector = Vector<float>(&lpunto, &rpunto);
    EXPECT_EQ(_actual_float_vector, _expected_float_vector);

    rpunto.setXY(-10.0, 0.0);
    _expected_float_vector.setXY(-1.0, 0.0);

    _actual_float_vector = Vector<float>(&lpunto, &rpunto);
    EXPECT_EQ(_actual_float_vector, _expected_float_vector);
}

TEST_F(VectorFloatTest, TestFloatCin) {
    _expected_float_vector.setXY(0.5, 0.5);

    std::istringstream in("0.5 0.5");
    in >> _actual_float_vector;

    EXPECT_EQ(_actual_float_vector, _expected_float_vector);
}

TEST_F(VectorFloatTest, TestFloatCout) {
    _actual_float_vector.setXY(15.0, 15.0);

    testing::internal::CaptureStdout();
    std::cout << _actual_float_vector;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Vector: X: 0.707107, Y: 0.707107\n");
}

TEST_F(VectorFloatTest, TestFloatProductoCruz) {
    _actual_float_vector.setXY(1.0, 1.0);

    Vector<float> in_float_vector = Vector<float>(&lpunto, &rpunto);

    EXPECT_FLOAT_EQ(_actual_float_vector.prodPunto(&in_float_vector), 1.0);
}


TEST_F(VectorFloatTest, TestFloatProductoPunto) {
    _actual_float_vector.setXY(1.0, 1.0);
    rpunto = Punto<float>(-1.0, -1.0);
    Vector<float> in_float_vector = Vector<float>(&lpunto, &rpunto);
    EXPECT_FLOAT_EQ(_actual_float_vector.prodPunto(&in_float_vector), -1.0);
}
