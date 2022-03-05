/**
 * @file PowerUp.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "PowerUp.h"

using namespace std;

/**
* PowerUp Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
*/
PowerUp::PowerUp(Level *level, const std::wstring &filename) : Item(level, filename)
{
}

/**
 * Loads attributes for item node
 *
 * Base class, override for specific items
 * @param node Node that is being loaded in
 */
 void PowerUp::XmlLoad(wxXmlNode *node)
{
     Item::XmlLoad(node);
}
