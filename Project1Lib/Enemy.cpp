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

/**
 * Draw this Enemy
 * @param dc Device context to draw on
 */
void Enemy::Draw(wxDC *dc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    dc->DrawBitmap(*mItemBitmap,
            int(GetX() - wid / 2),
            int(GetY() - hit / 2));
}
