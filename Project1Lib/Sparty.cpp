/**
 * @file Sparty.cpp
 * @author Michael Than
 */

#include "pch.h"
#include "Sparty.h"
#include "Game.h"
#include <String>

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

/**
 * Draw this Sparty
 * @param dc Device context to draw on
 */
void Sparty::Draw(wxDC *dc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    dc->DrawBitmap(*mItemBitmap,
            int(GetX() - wid / 2),
            int(GetY() - hit / 2));
}
