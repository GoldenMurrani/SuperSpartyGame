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
    Background(Level *level, const std::wstring &filename);

    void XmlLoad(wxXmlNode* node) override;

    bool CollisionTest(Item* item) override;
};

#endif //PROJECT1_BACKGROUND_H
