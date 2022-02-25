/**
 * @file Wall.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Wall.h"
#include "Game.h"
#include <string>
using namespace std;

/// Wall image files
const wstring wallOneImageName = L"images/wall1.png";
const wstring wallTwoImageName = L"images/wall2.png";
/**
 * Constructor
 * @param game Game the Enemy is a member of
 */
Wall::Wall(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}
