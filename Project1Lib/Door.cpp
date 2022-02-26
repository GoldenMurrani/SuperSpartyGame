/**
 * @file Door.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "Door.h"
#include "Game.h"
#include <string>
using namespace std;

/// Door filename
const wstring DoorImageName = L"images/door.png";

/**
 * Constructor
 * @param game Game this door is a member of
 */
Door::Door(Game *game) : Item(game, DoorImageName)
{
}
