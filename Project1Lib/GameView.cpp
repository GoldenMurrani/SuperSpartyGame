/**
 * @file GameView.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "ids.h"
#include "GameView.h"

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
    wxBrush background(*wxWHITE);
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
    Refresh();
}

void GameView::AddMenus(wxFrame* mainFrame, wxMenuBar *menuBar, wxMenu* fileMenu, wxMenu* viewMenu)
{
    // The file and view menus are defined by MainFrame. You can
    // add things to them here.
    //  fileMenu->Append(...)
    //  viewMenu->Append(...)

    auto landscapingMenu = new wxMenu();
}

void GameView::OnKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_RIGHT:
        // right arrow pressed
        mGame.GetSparty()->SetXVel(HorizontalSpeed);
        break;

    case WXK_LEFT:
        // left arrow pressed
        mGame.GetSparty()->SetXVel(-HorizontalSpeed);
        break;

    case WXK_SPACE:
        // space bar pressed
        mGame.GetSparty()->SetYVel(JumpSpeed);
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