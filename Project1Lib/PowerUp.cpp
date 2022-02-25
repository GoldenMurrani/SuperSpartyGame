/**
 * @file PowerUp.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "PowerUp.h"

using namespace std;

/// PowerUp filename and image
const wstring powerUpImage = L"images/stanley.png";

/**
* PowerUp Constructor
*/
PowerUp::PowerUp(Game* game) : Item(game, powerUpImage)
{

}