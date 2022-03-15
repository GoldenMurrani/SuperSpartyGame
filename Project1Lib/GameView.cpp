/**
 * @file GameView.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "ids.h"
#include "GameView.h"
#include "Game.h"

using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 10;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel0, this, IDM_LEVELZERO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel1, this, IDM_LEVELONE);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel2, this, IDM_LEVELTWO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLoadLevel3, this, IDM_LEVELTHREE);


    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);

    mStopWatch.Start();

    Bind(wxEVT_KEY_DOWN, &GameView::OnKeyDown, this);
    Bind(wxEVT_KEY_UP, &GameView::OnKeyUp, this);

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mGame.Update(elapsed);

    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
}


/**
 * timing handler
 * @param event time event
 */
void GameView::OnTimer(wxTimerEvent& event)
{

    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    //
    // Prevent tunnelling
    //
    while (elapsed > MaxElapsed)
    {
        mGame.Update(MaxElapsed);

        elapsed -= MaxElapsed;
    }

    // Consume any remaining time
    if (elapsed > 0)
    {
        mGame.Update(elapsed);
    }

    Refresh();
}

/**
 * Sets Level 0 after option is pressed
 * @param event
 */
void GameView::OnLoadLevel0(wxCommandEvent& event)
{
    mGame.SetLevel(0);
}

/**
 * Sets Level 0 after option is pressed
 * @param event
 */
void GameView::OnLoadLevel1(wxCommandEvent& event)
{
    mGame.SetLevel(1);
}

/**
 * Sets Level 0 after option is pressed
 * @param event
 */
void GameView::OnLoadLevel2(wxCommandEvent& event)
{
    mGame.SetLevel(2);
}

/**
 * Sets Level 3 after option is pressed
 * @param event
 */
 void GameView::OnLoadLevel3(wxCommandEvent& event)
 {
     mGame.SetLevel(3);
 }

void GameView::OnKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_RIGHT:
        // right arrow pressed
        mGame.GetSparty()->SetXVel(mGame.GetSparty()->GetSpeed());
        break;

    case WXK_LEFT:
        // left arrow pressed
        mGame.GetSparty()->SetXVel(-mGame.GetSparty()->GetSpeed());
        break;

    case WXK_SPACE:
        // space bar pressed
        if (mGame.GetSparty()->IsGround())
        {
            mGame.GetSparty()->SetIsGround(false);
            mGame.GetSparty()->SetYVel(JumpSpeed);
        }
        break;
    }
}
void GameView::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_RIGHT:
        mGame.GetSparty()->SetXVel(0);
        break;
    case WXK_LEFT:
        mGame.GetSparty()->SetXVel(0);
        break;
    }
}