/**
 * @file Wall.h
 * @author Vijay
 *
 * Base class for the item Wall.
 */

#ifndef PROJECT1_WALL_H
#define PROJECT1_WALL_H
#include "Item.h"

/**
* Base class for the item Wall.
*/
class Wall : public Item {
private:
//    /// The game window this item in going to be in
//    Game *mGame;
//    /// The underlying Wall image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// The bitmap we can display for this Wall
//    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Wall() = delete;

    /// Copy constructor (disabled)
    Wall(const Wall&) = delete;

    /// Assignment operator
    void operator=(const Wall&) = delete;

    Wall(Game* game, const std::wstring &filename);
//    /**
//     * Get the width of the Wall
//     * @return Wall width in pixels
//     */
//    int GetWidth() const { return mItemBitmap->GetWidth(); }
//
//    /**
//     * Get the height of the Wall
//     * @return Wall height in pixels
//     */
//    int GetHeight() const { return mItemBitmap->GetHeight(); }

    //void SpartyGnome();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitWall(this); }

};

#endif //PROJECT1_WALL_H
