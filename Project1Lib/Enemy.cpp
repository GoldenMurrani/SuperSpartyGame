/**
 * @file Enemy.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Enemy.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game Game the Enemy is a member of
 * @param filename file that the enemy is assigned to
 */
Enemy::Enemy(Level *level, const std::wstring &filename) : Item(level, filename)
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

    //auto collideItem = GetGame()->GetLevel()->CollisionTest(this);
    if ((mSpeedY > 0 && GetY() >= 1024) || (mSpeedY < 0 && GetY() <= 0))
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