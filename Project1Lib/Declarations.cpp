/**
 * @file Declerations.cpp
 * @author malpi
 */

#include "pch.h"
#include "Declarations.h"
#include "Platform.h"
#include "Item.h"

using namespace::std;

Declarations::Declarations(Level* level)
{

}

/**
 *  Sends declarations out to constructors and saves item pointers
 * @param node
 *

void Declarations::XmlType(wxXmlNode* node)
{
    shared_ptr<Item> item;
    vector<std::wstring> nodeChildren;
    auto name = node->GetName();
    if (node !=nullptr)
    {
        nodeChildren = GetNodeChildren(node);
    }
    if (name == "platform")
    {
        auto idType = node->GetAttribute(L"id");
        if (idType == "i004")
        {
            item = make_shared<Platform>(this, nodeChildren[0], nodeChildren[1], nodeChildren[2]);
        }
        else
        {
            item = make_shared<Platform>(this, nodeChildren[0], nodeChildren[1], nodeChildren[2]);
        }

    }

}
/**
 *  Gets children for all declarations and makes them viable.
 *
 * @param node Node that function is working on
 * @return A vector of all the contents of the node.
 */
vector<std::wstring> Declarations::GetNodeChildren(wxXmlNode *node)
{
    vector<wxString> attributes;
    vector<wstring> finalAttributes;
    wxString imagePath = "images/";

    auto name = node->GetName();
    //Gets platform children
    if (name=="platform")
    {
        auto leftImage = node->GetAttribute(L"left-image");
        auto midImage = node->GetAttribute(L"mid-image");
        auto rightImage = node->GetAttribute(L"right-image");
        attributes.insert(attributes.end(), { leftImage, midImage, rightImage});
    }
    if (name=="villain")
    {
        auto image = node->GetAttribute(L"image");
        attributes.insert(attributes.end(), { image });
    }
    if (name=="door")
    {
        auto image = node->GetAttribute(L"image");
        attributes.insert(attributes.end(), { image });
    }

    for (auto nodeItems : attributes)
    {
        nodeItems = imagePath + nodeItems;

        //Convert to wstring for bitmap
        std::wstring newString = nodeItems.wxString::ToStdWstring();
        finalAttributes.push_back(newString);



    }
    return finalAttributes;

}



