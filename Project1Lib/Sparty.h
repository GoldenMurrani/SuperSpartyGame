
/**
 * @file Sparty.h
 * @author Michael Than
 *
 *
 */

#ifndef PROJECT1_SPARTY_H
#define PROJECT1_SPARTY_H

#include "Item.h"

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

    Sparty(Game* game, const std::wstring &filename);

    void Draw(wxDC* dc);
};

#endif //PROJECT1_SPARTY_H
