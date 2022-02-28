/**
 * @file Scoreboard.h
 * @author Yousif Murrani
 *
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

/**
 * Class for the scoreboard
 */
class Scoreboard
{
private:
    /// variable for how much money has been collected
    int mCash;

public:
    /// Initialize a timer
    void SetTime();

    /// Reset a Timer
    void ResetTimer();

    /**
     * Gets the amount of cash collected
     */
     int GetCash() const { return mCash; }

     /**
      * Increases the amount of cash
      * @param x
      */
     void AdjustCash(int x) { mCash += x; }

     /**
      * Resets the amount of cash to 0
      */
     void ResetCash() { mCash = 0; }

     /// Draws the scoreboard on the screen
     void Draw();
};

#endif //PROJECT1_SCOREBOARD_H
