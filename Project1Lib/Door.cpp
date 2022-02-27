/**
 * @file Door.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "Door.h"
#include "Game.h"

using namespace std;

/// Door filename
const wstring DoorImageName = L"images/door.png";

/**
 * Constructor
 * @param game Game this door is a member of
 * @param filename the name of image file
 */
Door::Door(Game *game, const std::wstring &filename) : Item(game, filename)
{
}
