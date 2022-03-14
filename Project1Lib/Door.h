/**
 * @file Door.h
 * @author Zongyuan Li
 *
 *Base class for door item
 */

#ifndef PROJECT1_DOOR_H
#define PROJECT1_DOOR_H

#include "Item.h"

class Game;

/**
* Base class for Door item.
*/
class Door : public Item {
private:
    /// Game the level door object is being loaded into
    Game *mGame;
public:
    /// Default constructor (disabled)
    Door() = delete;

    /// Copy constructor (disabled)
    Door(const Door&) = delete;

    Door(Level* Level, const std::wstring&, Game* game);

    /// Assignment operator
    void operator=(const Door&) = delete;


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
    void XmlLoad(wxXmlNode *node) override ;

    /**
     * Collision test for all door items
     * @param item to test collsion with
     * @return bool for if there was a collision or not
     */
    bool CollisionTest(Item* item) override;

    /**
     * Starts the next level of the game
     */
    void NextLevel();
};

#endif //PROJECT1_DOOR_H
