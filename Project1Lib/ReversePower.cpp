/**
 * @file ReversePower.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "ReversePower.h"
#include "Game.h"

using namespace std;

/**
* Reverse Power Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
 * @param game thge game this power up is in
*/
ReversePower::ReversePower(Level *level, const std::wstring &filename, Game* game)
        : Item(level, filename)
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
    bool check = Item::CollisionTest(item);
    if (check) {
        if (!mCollected)
        {
            ReverseDirections();
            mCollected = true;
            item -> SetCollected();
        }
    }
    return false;
}

/**
 *  Function to reverse directions of sparty
 */
void ReversePower::ReverseDirections()
{
    mGame->GetSparty()->ReverseSpeed();
}

/**
* Handle updates for ReversePower
* @param elapsed the time before last update
*/
void ReversePower::Update(double elapsed)
{
    if (mCollected)
    {
        if (GetY() < 1500)
        {
            SetLocation(GetX(), GetY() + 50);
        }
        else{
            mCollected = false;
        }
    }
}

