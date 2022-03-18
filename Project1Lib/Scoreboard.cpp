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
* Scoreboard Constructor
 * @param game the game this scoreboard is in
 *
*/
Scoreboard::Scoreboard(Game* game)
{
    mGame = game;
    mCash = 0;
}

/**
* Scoreboard deconstructor
*/
Scoreboard::~Scoreboard()
{
}

/**
 * Function to draw scoreboard on screen
 * @param graphics the graphic this scoreboard need to be draw on
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    wxFont font(wxSize(0,50), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font,wxColour(0,0,90));
     wxString score = wxString::Format(wxT("$%i"), mCash);
    graphics->DrawText(score, mGame->GetSparty()->GetX()+200 ,20);
}

/**
 * Function to add the value of Cash by the score multiplier
 * @param value the value need to be added to our scoreboard
 */
void Scoreboard::AddScore(int value)
{
    mCash = mCash + int(mIncrease * double(value));
}


