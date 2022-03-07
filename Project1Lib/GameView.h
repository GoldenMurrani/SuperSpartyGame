/**
 * @file GameView.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

/**
Main class that will represent our game view
 */
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

    void OnLoadLevel0(wxCommandEvent& event);

    void OnLoadLevel1(wxCommandEvent& event);

    void OnLoadLevel2(wxCommandEvent& event);

    void OnPaint(wxPaintEvent& event);



public:
    void Initialize(wxFrame *parent);

    void OnTimer(wxTimerEvent& event);


    void OnKeyDown(wxKeyEvent& event);

    void OnKeyUp(wxKeyEvent& event);

    /**
    * Stop the timer so the window can close
    */
    void Stop() {mTimer.Stop();}
};

#endif //PROJECT1_GAMEVIEW_H
