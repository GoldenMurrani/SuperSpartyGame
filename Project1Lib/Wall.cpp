/**
 * @file Wall.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Wall.h"
#include "Level.h"
#include <string>
#include <wx/graphics.h>

using namespace std;

/// Wall image file 1
const wstring wallOneImageName = L"images/wall1.png";
/// Wall image file 2
const wstring wallTwoImageName = L"images/wall2.png";

/**
 * Constructor
 * @param game Game the Enemy is a member of
 * @param filename File that sets mItem to bitmap
 */
Wall::Wall(Level *level, const std::wstring &filename) : Item(level, filename)
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
void Wall::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"width", L"0").ToCDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}

/**
 * Draw this item
 * @param graphics graphic this item is going to be drawn on
 */
void Wall::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mWidth;
    double hit = mHeight;
    graphics->DrawBitmap(*mItemBitmap,
            ((int)GetX()) - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
}