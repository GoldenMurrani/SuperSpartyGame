/**
 * @file Enemy.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Enemy.h"
#include "Game.h"
#include <string>

using namespace std;

/**
 * Constructor
 * @param level Level the Enemy is a member of
 * @param filename file that the enemy is assigned to
 * @param game the game this enemy is in
 */
Enemy::Enemy(Level *level, const std::wstring &filename,Game* game) : Item(level, filename)
{
    mGame = game;
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

    // add code to switch directions when colliding with something
    if (mGame->CollisionTest(this) != nullptr)
    {
        if (mSpeedY > 0)
            SetLocation(GetX(), GetY() - Epsilon);
        else if (mSpeedY < 0)
            SetLocation(GetX(), GetY() + Epsilon);
        mSpeedY = -mSpeedY;
    }

    if (mSpeedY > 0 && GetY() >= 1024)
    {
        mSpeedY = -mSpeedY;
    }
    if (mSpeedY < 0 && GetY() <= 0)
    {
        mSpeedY = -mSpeedY;
    }
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Enemy::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * override collision test to let item respond
 * @param item item need to be collision tested
 * @return true if collided, false otherwise
 */
bool Enemy::CollisionTest(Item* item)
{
    bool check = Item::CollisionTest(item);
    if (check == true)
    {
        mGame -> GetSparty() ->SetStopUpdate();
        mGame -> GetSparty() -> SetDead(true);
        return true;
    }

    return false;
}