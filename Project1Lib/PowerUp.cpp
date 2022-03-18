/**
 * @file PowerUp.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "PowerUp.h"
#include "Game.h"
#include "Money.h"

using namespace std;

/**
* PowerUp Constructor
 * @param level level this item is a member of
 * @param filename the name of image file
 * @param game thge game this power up is in
*/
PowerUp::PowerUp(Level *level, const std::wstring &filename, Game* game)
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
 void PowerUp::XmlLoad(wxXmlNode *node)
{
     Item::XmlLoad(node);
}

/**
 *  Function to check collision between sparty and tuition power-up item
 * @param item that is colliding
 * @return true if there is a collision, false if not
 */
bool PowerUp::CollisionTest(Item* item)
{
    bool check = Item::CollisionTest(item);
    if (check==true) {
        if (!mCollected) {
            TuitionUp();
            mCollected = true;
            return false;
        }
    }
    return false;
}

/**
* Function that updates the value of the money items
*/
void PowerUp::TuitionUp()
{
    mGame->AddMoneyValue();
}

/**
* Handle updates for ReversePower
* @param elapsed the time before last update
*/
void PowerUp::Update(double elapsed)
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