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

/**
 * Platform constructor
 * @param level Level platform was a part of
 * @param leftFilename  Left platform image
 * @param midFilename Middle platform image
 * @param rightFilename Right platform image
 */
Platform::Platform(Level* level, std::wstring leftFilename, std::wstring midFilename, std::wstring rightFilename) :Item(level, leftFilename)
{
    mLeftImage = make_unique<wxImage>(leftFilename, wxBITMAP_TYPE_ANY);
    mLeftBitmap = make_unique<wxBitmap>(*mLeftImage);
    mMiddleImage = make_unique<wxImage>(midFilename, wxBITMAP_TYPE_ANY);
    mMiddleBitmap = make_unique<wxBitmap>(*mMiddleImage);
    mRightImage = make_unique<wxImage>(rightFilename, wxBITMAP_TYPE_ANY);
    mRightBitmap = make_unique<wxBitmap>(*mRightImage);
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
    graphics->DrawBitmap(*mLeftBitmap,
            ((double)GetX()-wid) - wid / 2, (double)GetY() - hit / 2,
            1.04 * wid, hit);
    graphics->DrawBitmap(*mMiddleBitmap,
            ((double)GetX()) - wid / 2, (double)GetY() - hit / 2,
            1.05 * wid, hit);
    graphics->DrawBitmap(*mRightBitmap,
            ((double)GetX()+wid) - wid / 2, (double)GetY() - hit / 2,
            1.04 * wid, hit);
}
