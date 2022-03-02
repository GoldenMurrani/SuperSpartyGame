/**
 * @file Door.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "Door.h"
#include "Game.h"

using namespace std;

/// Door filename
const wstring DoorImageName = L"images/door.png";

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