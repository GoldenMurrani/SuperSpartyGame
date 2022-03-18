/**
 * @file Scoreboard.h
 * @author Yousif Murrani
 *
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

#include "Game.h"

/**
 * Class for the scoreboard
 */
class Scoreboard
{
private:
    /// variable for how much money has been collected
    int mCash;

    /// Item location on screen
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// the percent of money to be increased
    double mIncrease = 1.0;

    /// the game this scoreboard is in
    Game* mGame;
public:
    /// Initialize a timer
     void SetTime();

    Scoreboard(Game* game);

    virtual ~Scoreboard();

     /**
      * Resets the amount of cash to 0
     */
     void ResetCash() { mCash = 0; }

     void Draw(std::shared_ptr<wxGraphicsContext> graphics);

     void AddScore(int value);

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

#endif //PROJECT1_SCOREBOARD_H
