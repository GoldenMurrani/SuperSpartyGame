/**
 * @file EnemyTest.cpp
 * @author Matthew Hofmann
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Enemy.h>

using namespace::std;
///door image temporary
const wstring EnemyImage = L"images/door.png";


TEST(TestEnemy, Enemy)
{
    // Construct a game object and level object level 0
    Game game;
    Game* gameTest = game.GetGameTest();
    std::shared_ptr<Level> level = gameTest -> GetLevel();
    Level* levelTest = level ->GetLevelTest();
    gameTest -> Clear();
    gameTest ->SetLevel(0);

    // Add some items
    auto item1 = make_shared<Enemy>(levelTest, EnemyImage, gameTest);

    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 0);

    item1->SetLocation(500, 500);
    gameTest -> GetSparty() ->SetLocation(500, 500);

    gameTest ->Add(item1);
    levelTest ->Add(item1);

    ASSERT_TRUE (gameTest ->GetSparty() -> GetX() == 500);
    ASSERT_TRUE (gameTest ->GetSparty() -> GetY() == 500);

    gameTest ->Update(5);
    // Should reset level and not be at postion x 500 y 500
    ASSERT_TRUE (gameTest ->GetSparty() -> GetX() != 500);
    ASSERT_TRUE (gameTest -> GetSparty() -> GetY() != 500);
    double startY = 572;
    double startX = 468;

    ASSERT_TRUE (gameTest ->GetSparty() -> GetY() == startY);
    ASSERT_TRUE (gameTest -> GetSparty() -> GetX() == startX);
}