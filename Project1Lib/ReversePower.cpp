/**
 * @file ReversePower.cpp
 * @author ymurr
 */

#include "pch.h"
#include "ReversePower.h"

using namespace std;

/**
* ReversePower Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
*/
ReversePower::ReversePower(Level *level, const std::wstring &filename) : Item(level, filename)
{
}

/**
 * Loads attributes for item node
 *
 * Base class, override for specific items
 * @param node Node that is being loaded in
 */
void ReversePower::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
}

