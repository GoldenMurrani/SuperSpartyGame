/**
 * @file ItemTest.cpp
 * @author Yousif Murrani
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>

using namespace std;

/** Mock class for testing item class */
//class ItemMock : public Item
//{
//public:
//    ItemMock(Game *game) : Item(game) {}
//};

//TEST(ItemTest, Construct)
//{
//    Game game;
//    ItemMock item(&game);
//}

//TEST(ItemTest, GettersSetters)
//{
//    Game game;
//    ItemMock item(&game);
//
//    // Tests SetLocation, GetX, GetY
//    item.SetLocation(100, 100);
//    ASSERT_NEAR(100, item.GetX(), 0.0001);
//    ASSERT_NEAR(100, item.GetX(), 0.0001);
//
//    // Test a second location
//    item.SetLocation(233, -79);
//    ASSERT_NEAR(233, item.GetX(), 0.0001);
//    ASSERT_NEAR(-79, item.GetY(), 0.0001);
//}