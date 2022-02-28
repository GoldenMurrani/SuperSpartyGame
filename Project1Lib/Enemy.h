/**
 * @file Enemy.h
 * @author Michael Than
 *
 * Base class for Enemy item.
 */

#ifndef PROJECT1_ENEMY_H
#define PROJECT1_ENEMY_H

#include "Item.h"

/**
* Base class for Enemy item.
*/
class Enemy : public Item{
private:
//    /// The underlying Enemy image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// The bitmap we can display for this Enemy
//    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Enemy() = delete;

    /// Copy constructor (disabled)
    Enemy(const Enemy &) = delete;

    /// Assignment operator
    void operator=(const Enemy &) = delete;

    /// Enemy constructor
    Enemy(Game* game, const std::wstring &filename);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitEnemy(this); }
};

#endif //PROJECT1_ENEMY_H
