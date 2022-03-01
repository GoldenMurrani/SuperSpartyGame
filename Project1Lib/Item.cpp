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
    mItemImage1 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap1 = make_unique<wxBitmap>(*mItemImage1);
}


/**
 * Constructor
 * @param level The level this item is a member of
 * @param filename The name of the file to display for this item
 */
Item::Item(Level* level, const std::wstring& filename)
{
    mItemImage1 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap1 = make_unique<wxBitmap>(*mItemImage1);
}



/**
 * Constructor
 * @param Level The game this item is a member of
 * @param filename The name of the file to display for this item
 * @param filename2 The name of the file to display for this item
 * @param filename3 The name of the file to display for this item
 */
Item::Item(Level* level, const std::wstring & filename, const std::wstring& filename2, const std::wstring& filename3)
{
    mItemImage1 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap1 = make_unique<wxBitmap>(*mItemImage1);
    mItemImage2 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap2 = make_unique<wxBitmap>(*mItemImage2);
    mItemImage3 = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
    mItemBitmap3 = make_unique<wxBitmap>(*mItemImage3);
}
/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Compute the distance from this item to another item
 * @param item Item we are computing the distance to
 * @return Distance in pixels
 */
double Item::DistanceTo(std::shared_ptr<Item> item)
{
    auto dx = item->GetX() - GetX();
    auto dy = item->GetY() - GetY();
    return sqrt(dx * dx + dy * dy);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
    double wid = mItemBitmap1->GetWidth();
    double hit = mItemBitmap1->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mItemImage1->IsTransparent((int)testX, (int)testY);
}

/**
 * Draw this item
 * @param graphics graphic this item is going to be drawn on
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    int wid = mItemBitmap1->GetWidth();
    int hit = mItemBitmap1->GetHeight();
    graphics->DrawBitmap(*mItemBitmap1,
            (int)GetX() - wid / 2, (int)GetY() - hit / 2,
            wid + 1, hit);
}

Item::Item(Level* p_level)
{

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
}