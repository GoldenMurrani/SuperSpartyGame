/**
 * @file Declerations.cpp
 * @author malpi
 */

#include "pch.h"
#include "Declerations.h"
#include "Level.h"
#include "Platform.h"
#include "Item.h"

using namespace::std;


void Declerations::XmlType(wxXmlNode* node)
{

    auto name = node->GetName();
    if (name == "platform")
    {
        auto idType = node->GetAttribute(L"id");
        if (idType == "i004")
        {

            //auto leftImage = node->GetAttribute(L"left-image");
            //auto midImage = node->GetAttribute(L"mid-image");
            //auto rightImage = node->GetAttribute(L"right-image");
            //mPlatformLeftImage1 = leftImage;
            //mPlatformMidImage1  = midImage;

        }

    }


}


