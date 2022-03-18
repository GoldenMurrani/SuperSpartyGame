/**
 * @file ReversePower.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "ReversePower.h"
#include "Game.h"
#include "IsEnemyVisitor.h"

using namespace std;

/**
* Reverse Power Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
 * @param game thge game this power up is in
*/
ReversePower::ReversePower(Level *level, const std::wstring &filename, Game* game)
        : Item(level, filename)
{
    mGame = game;
}

/**
 * Loads attributes for item node
 *
 * Base class, override for specific items
 * @param node Node that is being loaded in
 */
void ReversePower::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * Function to check collision between sparty and reverse item
 * @param item that is colliding
 * @return true if there is a collision, false if not
 */
bool ReversePower::CollisionTest(Item* item)
{
    bool check = Item::CollisionTest(item);
    if (check)
    {
        IsEnemyVisitor visitor;
        item->Accept(&visitor);
        if(!visitor.IsEnemy() && !mCollected)
        {
            mTextX = GetX();
            mTextY = GetY();
            ReverseDirections();
            mCollected = true;
            item -> SetCollected();
        }
        return false;
    }
    return false;
}

/**
 *  Function to reverse directions of sparty
 */
void ReversePower::ReverseDirections()
{
    mGame->GetSparty()->ReverseSpeed();
}

/**
* Handle updates for ReversePower
* @param elapsed the time before last update
*/
void ReversePower::Update(double elapsed)
{
    if (mCollected)
    {
        if (GetY() < 1500)
        {
            SetLocation(GetX(), GetY() + 50);
            mTextY -= 25;
            mFontHeight += 2;
            mFontWidth += 2;
        }
        else{
            mCollected = false;
            mTextX = -1000;
            mTextY = -1000;
            mFontHeight = 25;
            mFontWidth = 50;
        }
    }
}

/**
 * Override draw function to show up ReversePower text
 * @param graphics the graphic we draw on
 */
void ReversePower::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
    if (mCollected)
    {
        wxFont font(wxSize(mFontWidth, mFontHeight),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);

        graphics->SetFont(font,wxColour(0,90,0));
        graphics->DrawText("Movements Reversed!",mTextX, mTextY);
    }
}

