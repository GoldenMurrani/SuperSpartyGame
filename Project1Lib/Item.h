/**
 * @file Item.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include "Game.h"

class Game;

class Item {
private:
    /// The game window this item in going to be in
    Game mGame;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying fish image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mItemBitmap;

    bool mMirror = false;   ///< True mirrors the item image

protected:
    Item(Game *game, const std::wstring &filename);

public:
    virtual ~Item();

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;


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


    void Draw(wxDC *dc);

    bool HitTest(int x, int y);

    double DistanceTo(std::shared_ptr<Item> item);

    /**
    * Get the pointer to the Game object
    * @return Pointer to Game object
    */
    Game *GetGame() { return mGame;  }

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

    /**
     * Get the width of the item
     * @return Item width in pixels
     */
    int GetWidth() {return mItemBitmap->GetWidth(); }

    /**
     * Get the height of the item
     * @return Item height in pixels
     */
    int GetHeight() {return mItemBitmap->GetHeight(); }
};
};

#endif //PROJECT1_ITEM_H
