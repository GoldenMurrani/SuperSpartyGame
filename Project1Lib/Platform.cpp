/**
 * @file Platform.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Platform.h"
#include "Game.h"
#include "Level.h"
#include <string>

using namespace std;

Platform::Platform(Level* level, std::wstring filename, std::wstring filename2, std::wstring filename3) :Item(level, filename, filename2, filename3)
{

    //auto leftImage = node->GetAttribute(L"left-image");
    //auto midImage = node->GetAttribute(L"mid-image");
    //auto rightImage = node->GetAttribute(L"right-image");
    //mPlatformLeftImage = leftImage;
    //mPlatformMidImage  = midImage;
    //mPlatformRightImage  = rightImage;


}


/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Platform::XmlLoad(wxXmlNode *node)
{
    Item::XmlLoad(node);
    node->GetAttribute(L"width", L"0").ToCDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);

}