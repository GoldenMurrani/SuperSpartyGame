/**
 * @file Timer.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Timer.h"

/**
 * Timer constructor
 * @param game
 */
Timer::Timer(Game* game)
{
 game = mGame;
}

/**
 * Function to update the timer
 */
void Timer::Update(double elapsed)
{
    mSecond = mSecond + elapsed;
    if (mSecond >= 60)
    {
        mMinute += 1;
        mSecond -= 60;
    }
}
/**
 * Function to draw the timer on the screen
 */
void Timer::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    double wid = mWidth;
    double hit = mHeight;
    graphics->DrawBitmap(*mItemBitmap,
            ((double)GetX()) - wid / 2, (double)GetY() - hit / 2,
            wid, hit);
}
/**
 * Function to reset the timer
 */
void Timer::Reset()
{
    mMinute = 0.0, mSecond = 0.0;
}