/**
 * @file GameView.cpp
 * @author Zongyuan Li
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include "GameView.h"
#include "ids.h"

using namespace std;
/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the game view class.
 * @param parent The parent window for this class
 */
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);

    mStopWatch.Start();
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

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mGame.OnDraw(&dc);
}


/**
 * timing handler
 * @param event time event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}