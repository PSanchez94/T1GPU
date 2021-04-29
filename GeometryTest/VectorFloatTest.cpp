/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Vector.hpp"


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