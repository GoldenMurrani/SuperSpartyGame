
/**
 * @file Sparty.h
 * @author Michael Than
 *
 * Base class for the item Spartu.
 */

#ifndef PROJECT1_SPARTY_H
#define PROJECT1_SPARTY_H

#include "Item.h"

/// Gravity in virtual pixels per second per second
const double Gravity = 1000.0;

/// Jump Speed of sparty
const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 20;

class Game;

/**
* Base class for the item Spartu.
*/
class Sparty : public Item{
private:
    /// the amount of money this sparty have
    int mMoney = 0;

    /// sparty velocity in x direction
    double mXVel = 0;

    /// sparty velocity in y direction
    double mYVel = 0;

    /// boolean to determine if sparty is on the ground or not
    bool mIsGround = true;

    /// Stops the rest of the update if a certain collision condition is met
    bool mStopUpdate = false;

    /// tracker to keep track of the moved distance
    double mMovedDistance = 0;

    /// Horizontal character speed in pixels per second
    double mHorizontalSpeed = 500.00;

    /// If sparty dies this becomes true
    bool mDead = false;

    /// the game this sparty is in
    Game* mGame;

    /// Speed Multiplier
    double mSpeedMult = 1;

public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    Sparty(Game* game, const std::wstring &filename);

    /**
     * Gets the horizonatl speed of sparty
     * @return the horizontal speed of sparty
     */
    double GetSpeed() { return mHorizontalSpeed; }

    /**
     *  Gets the speed mult
     * @return Speed multiplier
     */
    double GetSpeedMult() {return mSpeedMult;};

    /**
     *  Sets the mult for Speed mult
     */
    void SetSpeedMult(int num)
    {
        mSpeedMult = num;
    }

    /**
     * Reverses the speed of Sparty
     */
    void ReverseSpeed() { mHorizontalSpeed = mHorizontalSpeed * -1; }



    /**
     * Sets mDead to true when he dies or loses
     * @param dead the boolean to determine whether sparty is dead or not
     */
    void SetDead(bool dead){mDead = dead;};

    /**
     * Gets mDead
     * @return mDead bool
     */
    bool GetDead(){return mDead;};

    /**
     * Sets mStopUpdate to true
     */
    void SetStopUpdate(){mStopUpdate = true;};

    /**
     * Sets mStopUpdate to true
     * @return whether the sparty is stopped update
     */
    bool GetStopUpdate(){return mStopUpdate;};

    /**
     * Handle updates for sparty
     * @param elapsed the time before last update
     */
     void Update(double elapsed);

    /**
     * Updates the Y velocity of the sparty item.
     * @param vel the value we want the velocity to be
     */
    void SetYVel(int vel) { mYVel = vel; }

    /**
     * Updates the X velocity of the sparty item.
     * @param vel the value we want the velocity to be
     */
    void SetXVel(int vel) { mXVel = vel; }

    /**
     * set the sparty is on the ground or not
     * @param isGround true if sparty is on the ground, false otherwise
     */
    void SetIsGround(bool isGround) {mIsGround = isGround; }

    /**
     * to see if the sparty is on the ground or not
     * @return true if sparty is on the ground, false otherwise
     */
    bool IsGround() {return mIsGround; }

    void SpartyReset();
};

#endif //PROJECT1_SPARTY_H
