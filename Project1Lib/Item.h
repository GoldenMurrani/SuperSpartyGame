/**
 * @file Item.h
 * @author Zongyuan Li
 *
 * Base class for items
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include "ItemVisitor.h"

class Level;
class Game;

/**
* Base class for items
*/
class Item {
private:
    /// The game window this item in going to be in
    Game *mGame;

    /// Item location on screen
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap;

protected:
    Item(Game *game, const std::wstring &filename);
    Item(Level* level, const std::wstring& filename, const std::wstring& filename2, const std::wstring& filename3);
    Item(Level* level, const std::wstring& filename);

    Item(Level* p_level);

public:
    virtual ~Item();

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

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    bool HitTest(int x, int y);

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
    virtual int GetWidth() {return mItemBitmap->GetWidth(); }

    /**
     * Get the height of the item
     * @return Item height in pixels
     */
    virtual int GetHeight() {return mItemBitmap->GetHeight(); }

    /**
    * Accept a visitor
     * @param visitor The visitor we accept
     */
    virtual void Accept(ItemVisitor* visitor) {};

    virtual void XmlLoad(wxXmlNode* node);

    virtual bool CollisionTest(Item* item);

    void SetImage(const std::wstring& file);
};


#endif //PROJECT1_ITEM_H
