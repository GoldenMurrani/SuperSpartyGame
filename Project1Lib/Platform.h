/**
 * @file Platform.h
 * @author Vijay
 *
 * Base class for the item platform.
 */

#ifndef PROJECT1_PLATFORM_H
#define PROJECT1_PLATFORM_H
#include "Item.h"


/**
* Base class for the item platform.
*/

class Platform : public Item {
private:
    /// The game window this item in going to be in
    Game *mGame;
    /// The underlying Platform image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this platform
    std::unique_ptr<wxBitmap> mItemBitmap;
    /// Item location in the Game
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item
public:
    /// Default constructor (disabled)
    Platform() = delete;

    /// Copy constructor (disabled)
    Platform(const Platform&) = delete;

    /// Assignment operator
    void operator=(const Platform&) = delete;
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
     * Get the width of the Wall
     * @return Wall width in pixels
     */
    int GetWidth() const { return mItemBitmap->GetWidth(); }

    /**
     * Get the height of the Wall
     * @return Wall height in pixels
     */
    int GetHeight() const { return mItemBitmap->GetHeight(); }

    //void OnDraw(wxDC *dc);

};

#endif //PROJECT1_PLATFORM_H
