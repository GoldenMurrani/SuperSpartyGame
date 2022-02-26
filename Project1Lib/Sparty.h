
/**
 * @file Sparty.h
 * @author Michael Than
 *
 * Base class for the item Spartu.
 */

#ifndef PROJECT1_SPARTY_H
#define PROJECT1_SPARTY_H

#include "Item.h"

/**
* Base class for the item Spartu.
*/
class Sparty : public Item{
private:
    /// The underlying sparty image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this sparty
    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Sparty() = delete;

    /// Copy constructor (disabled)
    Sparty(const Sparty &) = delete;

    /// Assignment operator
    void operator=(const Sparty &) = delete;

    /// Sparty constructor
    Sparty(Game* game, const std::wstring &filename);
};

#endif //PROJECT1_SPARTY_H
