/**
 * @file Scoreboard.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Scoreboard.h"
/**
* Scoreboard Constructor
 *
*/
Scoreboard::Scoreboard()
{
}
/**
* Scoreboard destructor
*/
Scoreboard::~Scoreboard()
{
}
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
    wxFont font(wxSize(0,50), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font,wxColour(0,0,90));
    graphics->DrawText(L"$",1500,20);

}
/**
 * Function to add the value of Cash by the score multiplier
 */
 void Scoreboard::AddScore(int value)
 {
     mCash = mCash + int(mIncrease * double(value));
 }
