/**
 * @file Background.cpp
 * @author Yousif Murrani
 */

#include "pch.h"
#include "Background.h"

using namespace std;

/// Background filename
const wstring BackgroundImageName = L"images/backgroundColorGrass.png";

/**
 * Constructor
 * @param game game this item is in
 * @param filename the name of image file
 */
Background::Background(Game* game, const std::wstring &filename) : Item(game, filename)
{
}
