/**
 * @file Item.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include <wx/graphics.h>

#include "Item.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename The name of the file to display for this item
 */
Item::Item(Game *game, const std::wstring &filename) : mGame(game)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Constructor
 * @param level The level this item is a member of
 * @param filename The name of the file to display for this item
 */
Item::Item(Level* level, const std::wstring& filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Constructor
 * @param level The level this item is a member of
 * @param filename The name of the file to display for this item
 * @param filename2 The name of the file to display for this item
 * @param filename3 The name of the file to display for this item
 */
Item::Item(Level* level, const std::wstring & filename, const std::wstring& filename2, const std::wstring& filename3)
{
}

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Draw this item
 * @param graphics graphic this item is going to be drawn on
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int wid = mItemBitmap->GetWidth();
    int hit = mItemBitmap->GetHeight();
    graphics->DrawBitmap(*mItemBitmap,
            (int)GetX() - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
}

/**
 * function to set item's image
 * @param filename the image to be set to
 */
void Item::SetImage(const std::wstring& filename)
{
    mItemImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Item::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"x", L"0").ToDouble(&mX);
    node->GetAttribute(L"y", L"0").ToDouble(&mY);
    mStartX = mX;
    mStartY = mY;
}

/**
 *  collision test to see if the given item collide with this item
 * @param item the given item need to be collision tested
 * @return true if collided, false otherwise
 */
bool Item::CollisionTest(Item* item)
{

    if (!mCollected) {
        // Border for the item
        auto itemLeft = item->GetX()-item->GetWidth()/2;
        auto itemRight = item->GetX()+item->GetWidth()/2;
        auto itemTop = item->GetY()-item->GetHeight()/2;
        auto itemBottom = item->GetY()+item->GetHeight()/2;

        // For us
        auto ourLeft = GetX()-GetWidth()/2;
        auto ourRight = GetX()+GetWidth()/2;
        auto ourTop = GetY()-GetHeight()/2;
        auto ourBottom = GetY()+GetHeight()/2;

        // Test for all of the non-collision cases,
        // cases where there is a gap between the two items
        if (ourRight<itemLeft ||  // Completely to the left
                ourLeft>itemRight ||  // Completely to the right
                ourTop>itemBottom ||  // Completely below
                ourBottom<itemTop)    // Completely above
        {
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}

/**
 * function to set the item location back to start location
 */
void Item::SetPosition()
{
    mX = mStartX;
    mY = mStartY;
}