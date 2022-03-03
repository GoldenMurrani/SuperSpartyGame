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

    Door(Level* Level, const std::wstring &filename);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitDoor(this); }

    /**
    * Load the attributes for an item node.
     *
     * This is the  base class version that loads the attributes
     * common to all items. Override this to load custom attributes
    * for specific items.
    *
    * @param node The Xml node we are loading the item from
     */
    void XmlLoad(wxXmlNode *node);

    bool CollisionTest(Item* item) override;
};

#endif //PROJECT1_DOOR_H
