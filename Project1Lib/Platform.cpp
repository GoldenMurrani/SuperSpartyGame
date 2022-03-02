/**
 * @file Platform.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Platform.h"
#include "Game.h"
#include "Level.h"
#include <string>
#include <wx/graphics.h>


using namespace std;

Platform::Platform(Level* level, std::wstring filename, std::wstring filename2, std::wstring filename3) :Item(level, filename)
{

    mItemImage1 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap1 = make_unique<wxBitmap>(*mItemImage1);
    mItemImage2 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap2 = make_unique<wxBitmap>(*mItemImage2);
    mItemImage3 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap3 = make_unique<wxBitmap>(*mItemImage3);

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
void Platform::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"width", L"0").ToCDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);

}

/**
 * Draw this item
 * @param graphics graphic this item is going to be drawn on
 */
void Platform::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mWidth/3;
    double hit = mHeight;
    graphics->DrawBitmap(*mItemBitmap1,
            ((int)GetX()-wid) - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
    graphics->DrawBitmap(*mItemBitmap2,
            ((int)GetX()) - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
    graphics->DrawBitmap(*mItemBitmap3,
            ((int)GetX()+wid) - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);

}
