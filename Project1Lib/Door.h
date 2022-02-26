/**
 * @file Door.h
 * @author Zongyuan Li
 *
 *Base class for door item
 */

#ifndef PROJECT1_DOOR_H
#define PROJECT1_DOOR_H

#include "Item.h"

/**
* Base class for Door item.
*/
class Door : public Item {
private:

public:
    /// Default constructor (disabled)
    Door() = delete;

    /// Copy constructor (disabled)
    Door(const Door&) = delete;

    /// Assignment operator
    void operator=(const Door&) = delete;

    Door(Game* game);
};

#endif //PROJECT1_DOOR_H
