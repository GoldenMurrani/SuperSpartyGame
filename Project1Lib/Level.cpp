/**
 * @file Level.cpp
 * @author malpi
 */




#include "pch.h"
#include "Level.h"
#include "Declerations.h"
#include "Platform.h"

using namespace::std;

/**
 * Constructor
 * @param game Game that is being ran
 */
Level::Level(Game* game) : mGame(game)
{
}

/**
 * Loads in the Xml file
 * @param filename File that is being worked on
 */
void Level::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if (!xmlDoc.Load(filename)) {
        wxMessageBox(L"Unable to load Aquarium file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for (; child; child = child->GetNext()) {
        auto name = child->GetName();
        if (name=="declarations") {
            XmlDeclare(child);
        }

            if (name==L"items") {
                //XmlItem(child);
            }
    }
}

/**
 * Iterates over Declaration node
 * @param node Node that is being worked on
 */
void Level::XmlDeclare(wxXmlNode* node)
{
    auto child = node->GetChildren();
    for (; child; child = child->GetNext()) {
      XmlType(child);

    }

}

/**
 *  Sends declarations out to constructors and saves item pointers
 * @param node
 */
void Level::XmlType(wxXmlNode* node)
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
vector<std::wstring> Level::GetNodeChildren(wxXmlNode *node)
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
    for (auto nodeItems : attributes)
    {
        nodeItems = imagePath + nodeItems;

        //Convert to wstring for bitmap
        std::wstring newString = nodeItems.wxString::ToStdWstring();
        finalAttributes.push_back(newString);



    }
    return finalAttributes;

}
//auto leftImage = node->GetAttribute(L"left-image");
//auto midImage = node->GetAttribute(L"mid-image");
//auto rightImage = node->GetAttribute(L"right-image");
//mPlatformLeftImage1 = leftImage;
//mPlatformMidImage1  = midImage;