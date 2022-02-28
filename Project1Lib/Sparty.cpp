/**
 * @file Sparty.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include <string>

using namespace std;

/// Sparty filename
const wstring GnomeImageName = L"images/gnome.png";

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
    SetLocation(GetX() + xVel * elapsed,GetY() + yVel * elapsed);
}