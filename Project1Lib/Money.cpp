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
Money::Money(Level *level, const std::wstring &filename) : Item(level, filename)
{
}
void Money::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    auto idType = node->GetAttribute(L"id");
    if (idType == L"i008")
    {
        mMoneyValue = 100;
    }
    else
    {
        mMoneyValue = 1000;
    }

}