/**
 * @file Timer.h
 * @author Vijay
 *
 *
 */

#ifndef PROJECT1_TIMER_H
#define PROJECT1_TIMER_H

#include "Game.h"

/**
 * base timer class
 */
class Timer {
private:

    /// second counter
    double mCountSec = 0;

    /// minute number to show on screen
    int mMinute = 0;
    /// second number to show on screen
    int mSecond = 0;

    /// Game timer is a part of
    Game* mGame;

public:
    ~Timer();

    Timer(Game* game);

    /// Default constructor (disabled)
    Timer() = delete;

    /// Copy constructor (disabled)
    Timer(const Timer&) = delete;

    void Update(double elapsed);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Reset();

};

#endif //PROJECT1_TIMER_H
