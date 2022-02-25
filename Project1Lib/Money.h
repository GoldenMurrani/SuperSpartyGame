/**
 * @file Money.h
 * @author Vijay
 *
 *
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H
#include "Item.h"
class Money : public Item{
private:
    /// The underlying money image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this money
    std::unique_ptr<wxBitmap> mItemBitmap;
public:
    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;

    Money(Game* game, const std::wstring &filename);

    void OnClear();

};

#endif //PROJECT1_MONEY_H
