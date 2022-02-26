/**
 * @file Background.h
 * @author Yousif Murrani
 *
 *
 */

#ifndef PROJECT1_BACKGROUND_H
#define PROJECT1_BACKGROUND_H

#include "Item.h"

class Background : public Item
{
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// The underlying background image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this background
    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    /// Background constructor
    Background(Game *game);

    /// Draw function
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int scrollX);
};

#endif //PROJECT1_BACKGROUND_H
