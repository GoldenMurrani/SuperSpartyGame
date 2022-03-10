
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

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 300.00;

const double JumpSpeed = -800;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/**
* Base class for the item Spartu.
*/
class Sparty : public Item{
private:
    /// the amount of money this sparty have
    int mMoney = 0;

    double mXVel = 0;
    double mYVel = 0;

    bool mIsGround = true;

    double mMovedDistance = 0;
public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    Sparty(Game* game, const std::wstring &filename);

    /**
     * get the amount of money this sparty have
     * @return int indicates the amount of money this sparty have
     */
    int GetMoney() { return mMoney; }

    /**
     * increase money this sparty have
     * @param amount the amount to be increased
     */
    void IncreaseMoney(int amount) {mMoney += amount; }

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

    void SetIsGround(bool isGround) {mIsGround = isGround; }

    bool IsGround() {return mIsGround; }
};

#endif //PROJECT1_SPARTY_H
