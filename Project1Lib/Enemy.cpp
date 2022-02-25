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
const wstring ItemImageName = L"images/UofM.png";

/**
 * Constructor
 * @param game Game the Enemy is a member of
 */
Enemy::Enemy(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}
