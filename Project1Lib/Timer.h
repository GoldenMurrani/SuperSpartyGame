/**
 * @file Timer.h
 * @author Vijay
 *
 *
 */

#ifndef PROJECT1_TIMER_H
#define PROJECT1_TIMER_H

#include "Game.h"

class Timer {
private:

    double mCountSec = 0.0;
    int mMinute = 0;
    int mSecond = 0;

    std::unique_ptr<wxImage> mItemImage;
    std::unique_ptr<wxBitmap> mItemBitmap;
    /// Item location on screen
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item
    double mWidth = 0;

    double mHeight = 0;

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
    /**
   * The X location of the item
   * @return X location in pixels
   */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

};

#endif //PROJECT1_TIMER_H
