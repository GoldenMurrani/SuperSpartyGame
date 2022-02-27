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
 * @param game game this item is a member of
 * @param filename the name of image file
*/
PowerUp::PowerUp(Game* game, const std::wstring &filename) : Item(game, filename)
{
}