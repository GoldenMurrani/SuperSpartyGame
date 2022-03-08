/**
 * @file Timer.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Timer.h"
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
void Timer::Draw(std::shared_ptr<wxGraphicsContext> graphics) {}
/**
 * Function to reset the timer
 */
void Timer::Reset()
{
    mMinute = 0.0, mSecond = 0.0;
}