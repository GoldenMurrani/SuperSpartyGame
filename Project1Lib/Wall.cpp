/**
 * @file Wall.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Wall.h"
#include "Game.h"
#include <string>
using namespace std;

/// Wall image file 1
const wstring wallOneImageName = L"images/wall1.png";
/// Wall image file 2
const wstring wallTwoImageName = L"images/wall2.png";

/**
 * Constructor
 * @param game Game the Enemy is a member of
 * @param filename File that sets mItem to bitmap
 */
Wall::Wall(Game *game, const std::wstring &filename) : Item(game, filename)
{
}
