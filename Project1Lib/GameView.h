/**
 * @file GameView.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

class GameView : public wxWindow{
private:
    /// An object that describes our Game
    Game mGame;
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);

public:
    void Initialize(wxFrame *parent);

    void OnTimer(wxTimerEvent& event);
};

#endif //PROJECT1_GAMEVIEW_H