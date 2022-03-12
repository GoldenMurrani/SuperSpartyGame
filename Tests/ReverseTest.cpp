/**
 * @file ReverseTest.cpp
 * @author Yousif Murrani
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <ReversePower.h>

using namespace std;

/// reverse power up image for test
const wstring ReverseArrows = L"images/arrows.png";

TEST(ReversePowerUp, ReversePower)
{
    // Construct a game object
    Game game;
    Game* gameTest = game.GetGameTest();
    std::shared_ptr<Level> level = gameTest -> GetLevel();
    Level* levelTest = level ->GetLevelTest();
    gameTest -> Clear();

    // Add reverse power item
    auto item1 = make_shared<ReversePower>(levelTest, ReverseArrows, gameTest);

    ASSERT_TRUE (gameTest ->GetCurrentLevel() == 0);

    item1->SetLocation(200, 200);
    gameTest->GetSparty()->SetLocation(190, 200);

    ASSERT_TRUE(gameTest->GetSparty()->GetSpeed() == 300);

    gameTest ->Add(item1);
    levelTest ->Add(item1);
    gameTest ->Add(gameTest->GetSparty());
    gameTest ->Update(0.001);
    gameTest->GetSparty()->SetLocation(230, 200);
    gameTest ->Update(0.001);

    ASSERT_TRUE(gameTest->GetSparty()->GetSpeed() == 300);

}