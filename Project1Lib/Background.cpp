/**
 * @file Background.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Background.h"
#include "Level.h"

using namespace std;

/// Background filename
const wstring BackgroundImageName = L"images/backgroundColorGrass.png";

/**
 * Constructor
 * @param game game this item is in
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