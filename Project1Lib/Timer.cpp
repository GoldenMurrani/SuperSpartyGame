/**
 * @file Timer.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Timer.h"

using namespace std;

/**
 * Timer constructor
 * @param game
 */
Timer::Timer(Game* game)
{
    mGame = game;
}


/**
* Timer destructor
*/
Timer::~Timer()
{
}
/**
 * Function to update the timer
 */
void Timer::Update(double elapsed)
{
    mCountSec += elapsed;
    if (mCountSec > 1)
    {
        mCountSec -= 1;
        mSecond += 1;
    }
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

    wxFont font(wxSize(0,50), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font,wxColour(0,64,0));

    wxString secs = wxString::Format(wxT("%02i:%02i"), mMinute, mSecond);


    graphics->DrawText(secs, mGame->GetSparty()->GetX()-300,20);

}
/**
 * Function to reset the timer
 */
void Timer::Reset()
{
    mMinute = 0, mSecond = 0;
}