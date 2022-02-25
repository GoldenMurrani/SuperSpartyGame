/**
 * @file Money.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Money.h"
#include "Game.h"
#include <string>

using namespace std;
/// Money image files
const wstring MoneyImageName = L"images/money100.png";
const wstring MoneyTwoImageName = L"images/money1000.png";

/**
 * Constructor
 * @param game Game the money is a member of
 */
Money::Money(Game *game, const std::wstring &filename) : Item(game, filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}