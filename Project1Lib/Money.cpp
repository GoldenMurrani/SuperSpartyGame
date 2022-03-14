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

bool Money::CollisionTest(Item* item)
{

    bool check = Item::CollisionTest(item);
    if (check == true)
    {
        mGame ->RemoveItem(this);
        mGame -> GetSparty() ->SetStopUpdate();
        return false;
    }

    return false;

}