/**
 * @file ReversePower.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "ReversePower.h"
#include "Game.h"

using namespace std;


/**
* ReversePower Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
*/
ReversePower::ReversePower(Level* level, const wstring& filename, Game* game)
        :Item(level, filename)
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
    if (check==true) {
        ReverseDirections();
        //mGame->RemoveItem(this);
        mGame->GetSparty()->SetStopUpdate();
        collected = true;
        return false;
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

/**
* Handle updates for ReversePower
* @param elapsed the time before last update
*/
void ReversePower::Update(double elapsed)
{
    if (collected)
    {
        if (GetY() < 1050)
        {
            SetLocation(GetX(), GetY() + 25);
        }
    }
}

