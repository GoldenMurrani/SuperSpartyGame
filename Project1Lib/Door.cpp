/**
 * @file Door.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "Door.h"
#include "Game.h"

using namespace std;

/// Collision distance for the door in pixels
const double CollisionDistance = 20;

/**
 * Constructor
 * @param game Game this door is a member of
 * @param filename the name of image file
 */
Door::Door(Level *Level, const std::wstring &filename) : Item(Level, filename)
{
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Door::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * override collision test to let item go into door
 * @param item item need to be collision tested
 * @return true if collided, false otherwise
 */
bool Door::CollisionTest(Item* item)
{
    // Collision for door is different
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance)
    {
        return true;
    }
    return false;
}