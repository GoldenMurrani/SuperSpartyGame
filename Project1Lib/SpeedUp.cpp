/**
 * @file SpeedUp.cpp
 * @author Matthew Hofmann
 */

#include "pch.h"
#include "SpeedUp.h"
#include "Game.h"

/**
* Reverse Power Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
 * @param game thge game this power up is in
*/
SpeedUp::SpeedUp(Level *level, const std::wstring &filename, Game* game)
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
void SpeedUp::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * Function to check collision between sparty and speedup item
 * @param item that is colliding
 * @return true if there is a collision, false if not
 */
bool SpeedUp::CollisionTest(Item* item)
{
    bool check = Item::CollisionTest(item);
    if (check) {
        if (!mCollected)
        {
            mTextX = GetX();
            mTextY = GetY();
            Speed();
            mCollected = true;
            item -> SetCollected();
        }
    }
    return false;
}

/**
 *  Function to double the speed of Sparty
 */
void SpeedUp::Speed()
{
 if(mGame -> GetSparty()->GetSpeedMult() == 1) {
     mGame->GetSparty()->SetSpeedMult(2);
 }
 else{
     mGame->GetSparty()->SetSpeedMult(mGame -> GetSparty()->GetSpeedMult() + 0.5);
 }
}

/**
* Handle updates for Speed Up
* @param elapsed the time before last update
*/
void SpeedUp::Update(double elapsed)
{
    if (mCollected)
    {
        if (GetY() < 2000)
        {
            SetLocation(GetX(), GetY() + 50);
            mTextY -= 50;
            mFontHeight += 1;
            mFontWidth += 1;
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
 * Draws the text for when the speed power up is hit
 * @param graphics
 */
void SpeedUp::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Item::Draw(graphics);
    if (mCollected) {
        wxFont font(wxSize(mFontWidth, mFontHeight), wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);

        graphics->SetFont(font, wxColor(90, 0, 0));
        graphics->DrawText("Speed Boost!", mTextX, mTextY);
    }
}