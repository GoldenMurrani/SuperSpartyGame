/**
 * @file Background.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Background.h"
#include <wx/graphics.h>

/// Background file
const std::wstring BackgroundImage = L"images/backgroundColorDesert.png";

/**
 * Constructor
 * @param game
 */
Background::Background(Game* game) : Item(game, BackgroundImage)
{

}

/**
* Draws the background
 * @param scrollX Offset to move background
 * @param graphics Bitmap object
*/
void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX)
{
    int wid = mBackground->GetWidth();
    int hit = mBackground->GetHeight();
    graphics->DrawBitmap(*mBackground,
            (int)GetX() - wid / 2 + scrollX, (int)GetY() - hit / 2,
            wid + 1, hit);
}