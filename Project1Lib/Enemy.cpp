/**
 * @file Enemy.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Enemy.h"
#include "Game.h"
#include <String>

using namespace std;

/// Enemy filename
const wstring EnemyImageName = L"images/UofM.png";

/**
 * Constructor
 * @param game Game the Enemy is a member of
 * @param filename file that the enemy is assigned to
 */
Enemy::Enemy(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mSpeedY = 50;
}

/**
 * Handle updates in time of our enemy
 *
 * This is called before we draw and allows us to
 * move our enemy. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Enemy::Update(double elapsed)
{
    SetLocation(GetX(),GetY() + mSpeedY * elapsed);
    if (mSpeedY > 0 && GetY() >= 1000)
    {
        mSpeedY = -mSpeedY;
    }
    if (mSpeedY < 0 && GetY() <= 0)
    {
        mSpeedY = -mSpeedY;
    }
    // add code to switch directions when colliding with something
}