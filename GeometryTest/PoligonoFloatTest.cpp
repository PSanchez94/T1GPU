/*

@date: 29-04-2021.
@author: Pablo Sanchez
/**/

#include <gtest/gtest.h>

#include "Poligono.hpp"


class PoligonoFloatTest : public::testing::Test {
protected:
    Punto<float>* lp = new Punto<float>(0.0, 0.0);
    Punto<float>* lmp = new Punto<float>(2.0, 0.0);
    Punto<float>* rmp = new Punto<float>(2.0, 2.0);
    Punto<float>* rp = new Punto<float>(0.0, 2.0);

    Poligono<float>* _actual_poligono = new Poligono<float>(lp, lmp, rmp);


    void SetUp() override {
        _actual_poligono->addPunto(rp);
    }

    void TearDown() override {
        delete _actual_poligono;
    }

};

TEST_F(PoligonoFloatTest, TestArea) {
    EXPECT_FLOAT_EQ(_actual_poligono->area(), 4.0);
}

TEST_F(PoligonoFloatTest, Test_isCCW) {
    std::cout << *_actual_poligono;
    EXPECT_TRUE(_actual_poligono->isCCW());
}