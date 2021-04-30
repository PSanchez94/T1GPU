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
    EXPECT_EQ(*_actual_list.getHead()->p, lp);
    EXPECT_EQ(*_actual_list.getHead()->next->p, mp);
    EXPECT_EQ(*_actual_list.getHead()->prev->p, rp);
    EXPECT_EQ(_actual_list.getSize(), 3);
}

TEST_F(PoligonoListFloatTest, TestAddPunto) {
    Punto<float> fourth_p = Punto<float>(4.0, 4.0);

    _actual_list.addPunto(&fourth_p);

    EXPECT_EQ(*_actual_list.getHead()->prev->prev->p, rp);
    EXPECT_EQ(*_actual_list.getHead()->prev->p, fourth_p);
    EXPECT_EQ(*_actual_list.getHead()->prev->next->p, lp);
    EXPECT_EQ(_actual_list.getSize(), 4);
}

/*
TEST_F(PoligonoListFloatTest, TestRemovePunto) {
    Punto<float> fourth_p = Punto<float>(4.0, 4.0);
    Punto<float> fifth_p = Punto<float>(5.0, 5.0);

    _actual_list.addPunto(&fourth_p);
    _actual_list.addPunto(&fifth_p);

    EXPECT_EQ(*_actual_list.getHead()->prev->prev->p, rp);
    EXPECT_EQ(*_actual_list.getHead()->prev->p, fourth_p);
    EXPECT_EQ(*_actual_list.getHead()->prev->next->p, lp);
    EXPECT_EQ(_actual_list.getSize(), 4);
}
/**/