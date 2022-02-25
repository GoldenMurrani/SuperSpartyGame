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
const wstring ItemImageName = L"images/gnome.png";

/**
 * Constructor
 * @param game Game the sparty is a member of
 */
Sparty::Sparty(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}
