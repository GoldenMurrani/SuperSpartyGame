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
 * @param Level Level the money is a member of
 * @param filename File that sets mItem to bitmap
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
        //mGame ->RemoveItem(this);
        mGame -> GetSparty() ->SetStopUpdate();
        return false;
    }

    return false;

}