/**
 * @file Enemy.h
 * @author Michael Than
 *
 *
 */

#ifndef PROJECT1_ENEMY_H
#define PROJECT1_ENEMY_H

#include "Item.h"

class Enemy : public Item{
private:
    /// The underlying Enemy image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this Enemy
    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Enemy() = delete;

    /// Copy constructor (disabled)
    Enemy(const Enemy &) = delete;

    /// Assignment operator
    void operator=(const Enemy &) = delete;

    Enemy(Game* game, const std::wstring &filename);

    void Draw(wxDC* dc);
};

#endif //PROJECT1_ENEMY_H
