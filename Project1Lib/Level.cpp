/**
 * @file Level.cpp
 * @author malpi
 */

#include "Level.h"



#include "pch.h"
#include "Level.h"
#include "Declerations.h"

using namespace::std;

Level::Level(Game* game) : mGame(game)
{
    //mDeclerations
}


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

void Level::XmlDeclare(wxXmlNode* node)
{
    auto child = node->GetChildren();
    for (; child; child = child->GetNext()) {
      //mDeclerations-> XmlType(child);

    }

}