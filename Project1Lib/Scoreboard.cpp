/**
 * @file Scoreboard.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Scoreboard.h"

/**
 * Function to initialize a timer
 */
void Scoreboard::SetTime()
{

}

/**
 * Function to reset the timer to 0
 */
void Scoreboard::ResetTimer()
{

}

/**
 * Function to draw scoreboard on screen
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mWidth;
    double hit = mHeight;
    graphics->DrawBitmap(*mItemBitmap,
            ((double)GetX()) - wid / 2, (double)GetY() - hit / 2,
            wid, hit);
}
/**
 * Function to draw player score on screen
 */
void Scoreboard::DrawScore(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mWidth;
    double hit = mHeight;

    //graphics->DrawText(mCash, (GetX()+700)/2 - wid / 2, 70 - hit / 2);

}