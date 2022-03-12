/**
 * @file Level.cpp
 * @author Matthew Hofmann
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Level.h>
TEST(TestLevel, Level)
{
// Construct a game object and level object 0
Game game;
Game* gameTest = game.GetGameTest();
std::shared_ptr<Level> level = gameTest->GetLevel();
Level* levelTest = level->GetLevelTest();
// Level is loaded in as game opens up and current level is set
ASSERT_TRUE (gameTest ->GetCurrentLevel() == 1 || gameTest -> GetCurrentLevel() == 0);
ASSERT_TRUE (gameTest -> GetItemVecSize() != 0);

//Check set level works
gameTest ->SetLevel(2);
// Starting position for level 2 of Sparty
ASSERT_TRUE (gameTest -> GetSparty()-> GetX() == 788);
ASSERT_TRUE (gameTest -> GetSparty()-> GetY() == 796);


}