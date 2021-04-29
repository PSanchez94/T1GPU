/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Vector.hpp"
#include "Punto.hpp"


class VectorFloatTest : public::testing::Test {
protected:

    Vector<float> _actual_float_vector;
    Vector<float> _expected_float_vector;

    void SetUp() override { }

    void TearDown() override { }

};


TEST_F(VectorFloatTest, TestDefaultConstructor) {
    EXPECT_EQ(_actual_float_vector.getX(), 0);
    EXPECT_EQ(_actual_float_vector.getY(), 0);
}

TEST_F(VectorFloatTest, TestTwoDPointConstructor) {
    Punto<float> lpunto = Punto<float>(0.0, 0.0);
    Punto<float> rpunto = Punto<float>(10.0, 0.0);
    _actual_float_vector = Vector<float>(&lpunto, &rpunto);

    _expected_float_vector.setXY(1.0, 0.0);

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
    _expected_float_vector.setXY(10.0, 10.0);

    std::istringstream in("10.0 10.0");
    in >> _actual_float_vector;

    EXPECT_EQ(_actual_float_vector, _expected_float_vector);
}

TEST_F(VectorFloatTest, TestFloatCout) {
    _actual_float_vector.setXY(15.0, 15.0);

    testing::internal::CaptureStdout();
    std::cout << _actual_float_vector;

    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Vector: X: 15, Y: 15\n");
}

/*
TEST_F(VectorFloatTest, TestFloatCout) {

    EXPECT_EQ();
}

TEST_F(VectorFloatTest, TestFloatCout) {

    EXPECT_EQ();
}
/**/