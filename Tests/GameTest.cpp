/**
 * @file GameTest.cpp
 * @author Yousif Murrani
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Door.h>

#include <Door.h>
#include <Enemy.h>
#include <Money.h>
#include <Wall.h>

using namespace std;

///door image temporary
const wstring DoorImageName = L"images/door.png";




class TestVisitor : public ItemVisitor
{
public:
    virtual void VisitDoor(Door* door) override { mNumDoors++; }
    virtual void VisitEnemy(Enemy* enemy) override { mNumEnemy++; }
    virtual void VisitMoney(Money* money) override { mNumMoney++; }
    virtual void VisitWall(Wall* wall) override { mNumWall++; }

    int mNumDoors = 0;
    int mNumEnemy = 0;
    int mNumMoney = 0;
    int mNumWall = 0;
};

TEST(TestGame, Construct)
{
    Game game;
}

TEST(TestGame, Iterator)
{
    // Construct a game object
    Game game;
    Game* gameTest = game.GetGameTest();
    Level level(gameTest);
    Level* levelTest = level.GetLevelTest();
    gameTest -> Clear();

    // Add some items
    auto item1 = make_shared<Door>(levelTest, DoorImageName, gameTest);
    auto item2 = make_shared<Door>(levelTest, DoorImageName, gameTest);
    auto item3 = make_shared<Door>(levelTest, DoorImageName, gameTest);

    gameTest->Add(item1);
    gameTest->Add(item2);
    gameTest->Add(item3);

    // Begin points to the first item
    auto iter1 = gameTest->begin();

    // End points after the last item
    auto iter2 = gameTest->end();
    ASSERT_EQ(item1, *iter1) << L"First item correct";

    ++iter1;
    ASSERT_EQ(item2, *iter1) << L"Second item correct";

    ++iter1;
    ASSERT_EQ(item3, *iter1) << L"Third item correct";

    ++iter1;
    ASSERT_FALSE(iter1 != iter2);
}

TEST(GameTest, Visitor)
{
    // Construct a game object
    Game game;
    Game* gameTest = game.GetGameTest();
    Level level(gameTest);
    Level* levelTest = level.GetLevelTest();
    gameTest -> Clear();

    // Add some item of each type
    auto item1 = make_shared<Door>(levelTest, DoorImageName,gameTest);
    auto item2 = make_shared<Enemy>(levelTest, DoorImageName, gameTest);
    auto item3 = make_shared<Wall>(levelTest, DoorImageName);
    auto item4 = make_shared<Door>(levelTest, DoorImageName, gameTest);

    gameTest->Add(item1);
    gameTest->Add(item2);
    gameTest->Add(item3);
    gameTest->Add(item4);


    TestVisitor visitor;
    gameTest->Accept(&visitor);
    ASSERT_EQ(2, visitor.mNumDoors) <<
                                        L"Visitor number of doors";
    ASSERT_EQ(1, visitor.mNumEnemy) <<
                                        L"Visitor number of enemy";
    ASSERT_EQ(0, visitor.mNumMoney) <<
                                     L"Visitor number of money";
    ASSERT_EQ(1, visitor.mNumWall) <<
                                    L"Visitor number of walls";
}