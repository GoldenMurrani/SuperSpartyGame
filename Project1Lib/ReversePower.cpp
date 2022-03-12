/**
 * @file ReversePower.cpp
 * @author ymurr
 */

#include "pch.h"
#include "ReversePower.h"
#include "Game.h"

using namespace std;

/// Collision distance for reverse power up
const double CollisionDistance = 20;

/**
* ReversePower Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
*/
ReversePower::ReversePower(Level *level, const wstring &filename, Game* game) : Item(level, filename)
{
    mGame = game;
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
/**
 * Function to check collision between sparty and reverse item
 * @param item that is colliding
 * @return true if there is a collision, false if not
 */
bool ReversePower::CollisionTest(Item* item)
{
    double dx = item->GetX() - GetX();
    double dy = item->GetY() - GetY();
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < CollisionDistance) {
        ReverseDirections();
        return true;
    }

    return false;
}

/**
 * Function to reverse directions of sparty
 */
void ReversePower::ReverseDirections()
{
    mGame->GetSparty()->ReverseSpeed();
}
