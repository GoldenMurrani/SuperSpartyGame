/**
 * @file SpartyTest.cpp
 * @author Yousif Murrani
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Sparty.h>

using namespace std;

/// Temp image for sparty
const wstring SpartyImage = L"images/gnome.png";

TEST(TestSparty, Construct)
{
    // Constructs a game object
    Game game;
    Game* gameTest = game.GetGameTest();
    std::shared_ptr<Level> level = gameTest -> GetLevel();
    Level* levelTest = level ->GetLevelTest();
    gameTest -> Clear();

    Sparty sparty_obj(gameTest, SpartyImage);

}

TEST(TestSparty, Falling)
{
    Game game;
    Game* gameTest = game.GetGameTest();
    std::shared_ptr<Level> level = gameTest -> GetLevel();
    Level* levelTest = level ->GetLevelTest();
    gameTest -> Clear();
    gameTest->SetLevel(0);

    ASSERT_TRUE(gameTest->GetCurrentLevel() == 0);


    gameTest -> GetSparty() -> SetLocation(400, 400);

    ASSERT_TRUE(gameTest->GetSparty()->GetX() == 400);
    ASSERT_TRUE(gameTest->GetSparty()->GetY() == 400);

    gameTest->Update(.001);

    gameTest -> GetSparty() -> SetLocation(2000, 2000);

    gameTest->Update(.001);

    ASSERT_TRUE(gameTest->GetSparty()->GetX() != 400);
    ASSERT_TRUE(gameTest->GetSparty()->GetY() != 400);

    double startY = 572;
    double startX = 468;

    ASSERT_TRUE (gameTest->GetSparty()->GetY() == startY);
    ASSERT_TRUE (gameTest->GetSparty()->GetX() == startX);

}
