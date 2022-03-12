/**
 * @file DoorTest.cpp
 * @author Matthew Hofmann
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Door.h>

using namespace::std;
///door image temporary
const wstring DoorImageName = L"images/door.png";


TEST(TestDoor, Door)
{
    // Construct a game object
    Game game;
    Game* gameTest = game.GetGameTest();
    std::shared_ptr<Level> level = gameTest -> GetLevel();
    Level* levelTest = level ->GetLevelTest();
    gameTest -> Clear();


    // Add some items
    auto item1 = make_shared<Door>(levelTest, DoorImageName, gameTest);

    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 0);

    item1->SetLocation(500, 500);
    gameTest -> GetSparty() ->SetLocation(500, 500);

    gameTest ->Add(item1);
    levelTest ->Add(item1);
    gameTest ->Add(gameTest->GetSparty());
    gameTest ->Update(0.001);
    // Test Level 0 to Level 1
    ASSERT_TRUE (gameTest ->GetCurrentLevel() != 0);
    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 1);
    levelTest -> Clear();

    // Test Level 3 to Level 0
    gameTest ->SetLevel(3);
    gameTest -> Clear();
    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 3);
    // Init variables for other level
    std::shared_ptr<Level> level2 = gameTest -> GetLevel();
    Level* levelTest2= level2 ->GetLevelTest();
    auto item2 = make_shared<Door>(levelTest, DoorImageName, gameTest);

    item2->SetLocation(500, 500);
    gameTest -> GetSparty() ->SetLocation(500, 500);
    gameTest ->Add(item2);
    levelTest2 -> Clear();
    levelTest2 ->Add(item2);
    gameTest ->Add(gameTest->GetSparty());
    gameTest ->Update(0.001);

    ASSERT_TRUE (gameTest ->GetCurrentLevel() != 3);
    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 0);

}