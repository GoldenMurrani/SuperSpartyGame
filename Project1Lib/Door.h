/**
 * @file Door.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_DOOR_H
#define PROJECT1_DOOR_H

#include "Item.h"

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
