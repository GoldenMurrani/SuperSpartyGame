/**
 * @file PowerUp.h
 * @author Yousif Murrani
 *
 * Base class for the item PowerUp.
 */

#ifndef PROJECT1_POWERUP_H
#define PROJECT1_POWERUP_H

#include "Item.h"

/**
* Base class for the item PowerUp.
*/
class PowerUp : public Item
{
private:
//    /// The game window this item in going to be in
//    Game *mGame;
//    /// The underlying Platform image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// The bitmap we can display for this platform
//    std::unique_ptr<wxBitmap> mItemBitmap;
//    /// Item location in the Game
//    double  mX = 0;     ///< X location for the center of the item
//    double  mY = 0;     ///< Y location for the center of the item
public:
    /// Default constructor (disabled)
    PowerUp() = delete;

    /// Copy constructor (disabled)
    PowerUp(const PowerUp&) = delete;

    /// Assignment operator
    void operator=(const PowerUp&) = delete;

//    /**
//    * The X location of the item
//    * @return X location in pixels
//    */
//    double GetX() const { return mX; }
//
//    /**
//     * The Y location of the item
//     * @return Y location in pixels
//     */
//    double GetY() const { return mY; }

    PowerUp(Game *game, const std::wstring &filename);
};

#endif //PROJECT1_POWERUP_H
