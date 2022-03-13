/**
 * @file Sparty.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include "Item.h"
#include <string>

using namespace std;

const double animeSwapDistance = 200;

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
    //Collision check function
    mStopUpdate = false;
    double currentX = GetX();
    //Sideways Movement
    double newX = currentX + mXVel * elapsed;

    double currentY = GetY();
    //new Y speed
    mYVel = mYVel + Gravity * elapsed;
    double newY = currentY + mYVel * elapsed;

    //check for y direction
    SetLocation(currentX, newY);

    auto collideItem = GetGame()->CollisionTest(this);
    //Jumping
    if (collideItem)
    {
        newY = currentY;
        if (mYVel > 0)
            SetIsGround(true);
        mYVel = 0;
    }

    SetLocation(newX, newY);
    collideItem = GetGame()->CollisionTest(this);
    if (mStopUpdate == false) {


        //horizontal moving
        if (collideItem) {
            newX = currentX;
            mXVel = 0;
        }
        SetLocation(newX, newY);

        //Anime Part
        double distanceX = newX-currentX;

        if (mIsGround)
            mMovedDistance += abs(distanceX);

        if (mXVel>0) {
            if (mMovedDistance<animeSwapDistance/2)
                SetImage(L"images/gnome-walk-right-1.png");
            else if (mMovedDistance<animeSwapDistance)
                SetImage(L"images/gnome-walk-right-2.png");
            else
                mMovedDistance = 0;
        }
        else if (mXVel<0) {
            if (mMovedDistance<animeSwapDistance/2)
                SetImage(L"images/gnome-walk-left-1.png");
            else if (mMovedDistance<animeSwapDistance)
                SetImage(L"images/gnome-walk-left-2.png");
            else
                mMovedDistance = 0;
        }
        else
            SetImage(L"images/gnome.png");


        // Reset level if Sparty falls below a certain height
        if (currentY>1500) {
            Game* currentGame = GetGame();
            currentGame->SetLevel(currentGame->GetCurrentLevel());
        }
    }
}
