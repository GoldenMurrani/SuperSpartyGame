/**
 * @file Background.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Background.h"

using namespace std;

/// Sparty filename
const wstring BackgroundImageName = L"images/backgroundColorGrass.png";

/**
 * Constructor
 * @param game
 */
Background::Background(Game* game) : Item(game, BackgroundImageName)
{
}
