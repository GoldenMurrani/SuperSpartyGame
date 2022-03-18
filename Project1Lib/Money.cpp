/**
 * @file Money.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Money.h"
#include "Game.h"
#include <string>

using namespace std;

/**
 * Constructor
 * @param level Level the money is a member of
 * @param filename File that sets mItem to bitmap
 * @param game the game this money is in
 */
Money::Money(Level *level, const std::wstring &filename , Game* game) : Item(level, filename)
{
    mGame = game;
}

/**
 * Function that loads in the XML node for the money item and gets the value and id
 * @param node to load in
 */
void Money::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    auto idType = node->GetAttribute(L"id");
    if (idType == L"i008")
    {
        mMoneyValue = 100 + (100 * mGame->GetMult());
    }
    else
    {
        mMoneyValue = 1000 + (1000 * mGame->GetMult());
    }

}

/**
 * Collision test between item and money object
 * @param item to test collision against
 * @return true if there was a collision, false if there was not
 */
bool Money::CollisionTest(Item* item)
{
    bool check = Item::CollisionTest(item);
    if (check == true)
    {
        if (mCollected == false)
        {
            mGame->AddScore(mMoneyValue);
        }
        mCollected = true;
        return false;
    }

    return false;
}

/**
*  Handle updates for Money
* @param elapsed the time before last update
*/
void Money::Update(double elapsed)
{
    if (mCollected)
    {
        if (GetY() > -1000)
        {
            SetLocation(GetX(), GetY() - 50);
        }
        else{
            mCollected = false;
        }
    }
}

/**
 * Override draw function to show up money text
 * @param graphics the graphic we draw on
 */
void Money::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
    if (mCollected)
    {
        wxFont font(wxSize(GetWidth(), GetHeight()),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);

        graphics->SetFont(font,wxColour(0,0,90));
        graphics->DrawText("Money",GetX(), GetY());
    }
}

