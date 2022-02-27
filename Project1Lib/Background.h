/**
 * @file Background.h
 * @author Yousif Murrani
 *
 * Base class for moving background
 */

#ifndef PROJECT1_BACKGROUND_H
#define PROJECT1_BACKGROUND_H

#include "Item.h"
/**
* Base class for moving background
*/
class Background : public Item
{
private:

public:
    /// Default constructor (disabled)
    Background() = delete;

    /// Copy constructor (disabled)
    Background(const Background &) = delete;

    /// Assignment operator
    void operator=(const Background &) = delete;

    /// Background constructor
    Background(Game *game, const std::wstring &filename);
};

#endif //PROJECT1_BACKGROUND_H
