/**
 * @file Background.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Background.h"
#include "Level.h"

using namespace std;

/**
 * Constructor
 * @param level level this item is in
 * @param filename the name of image file
 */
Background::Background(Level* level, const std::wstring &filename) : Item(level, filename)
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
void Background::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

/**
 * override collision test to disable the effect from background
 * @param item item need to be collision test
 * @return false because we don't want to consider background collision
 */
bool Background::CollisionTest(Item* item)
{
    return false;
}