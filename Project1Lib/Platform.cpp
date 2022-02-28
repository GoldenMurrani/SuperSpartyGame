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

Platform::Platform(Level* level, std::wstring filename, std::wstring filename2, std::wstring filename3) :Item(mLevel, filename, filename2, filename3)
{

    //auto leftImage = node->GetAttribute(L"left-image");
    //auto midImage = node->GetAttribute(L"mid-image");
    //auto rightImage = node->GetAttribute(L"right-image");
    //mPlatformLeftImage = leftImage;
    //mPlatformMidImage  = midImage;
    //mPlatformRightImage  = rightImage;


}


/// Platform image files
//const wstring platformImageName = L"images/platformIndustrial_057.png";
//const wstring platformTwoImageName = L"images/platformIndustrial_059.png";
//const wstring platformThreeImageName = L"images/platformIndustrial_060.png";
//const wstring platformFourImageName = L"images/platformIndustrial_061.png";/
//const wstring snowImageName = L"images/snow.png";
//const wstring snowLeftImageName = L"images/snowLeft.png";
//const wstring snowMidImageName = L"images/snowMid.png";
//const wstring snowRightImageName = L"images/snowRight.png";