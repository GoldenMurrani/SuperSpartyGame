/**
 * @file Sparty.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include <string>

using namespace std;


/**
 * Constructor
 * @param game Game the sparty is a member of
 * @param filename File that sets mItem to bitmap
 */
Sparty::Sparty(Game *game, const std::wstring &filename) : Item(game, filename)
{
}

/**
* Handle updates for sparty
* @param elapsed the time before last update
*/
void Sparty::Update(double elapsed)
{
    double currentX = GetX();
    //Sideways Movement
    double newX = currentX + mXVel * elapsed;

    double currentY = GetY();
    //new Y spped
    mYVel = mYVel + Gravity * elapsed;
    double newY = currentY + mYVel * elapsed;

    //check for y direction
    SetLocation(currentX, newY);

    auto collideItem = GetGame()->GetLevel()->CollisionTest(this);
    //Jumping
    if (collideItem)
    {
//        if (mYVel > 0)
//            newY = currentY + Epsilon;
//        else
//            newY = currentY - Epsilon;
        newY = currentY;
        mYVel = 0;
        SetIsGround(true);
    }

    SetLocation(newX, newY);
    collideItem = GetGame()->GetLevel()->CollisionTest(this);
    //horizontal moving
    if (collideItem)
    {
//        if (mXVel > 0)
//            newX = currentX - Epsilon;
//        else
//            newX = currentX + Epsilon;
        newX = currentX;
        mXVel = 0;
    }
    SetLocation(newX, newY);
}