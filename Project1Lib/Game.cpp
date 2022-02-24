/**
 * @file Game.cpp
 * @author Zongyuan Li
 */


#include "pch.h"
#include "Game.h"

using namespace std;

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Game::OnDraw(wxDC* dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);
    for (auto item: mItems)
    {
        item->Draw(dc);
    }
}

/**
 * Game Constructor
 */
Game::Game()
{
    mBackground = make_unique<wxBitmap>(
            L"images/backgroundColorDesert.png", wxBITMAP_TYPE_ANY);
}

/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(100, 100);
    bool checkedAll = false;
    while (!checkedAll)
    {
        checkedAll = true;
        for (auto fish: mItems)
        {
            if (fish->DistanceTo(item)<1)
            {
                item->SetLocation(item->GetX()+10, item->GetY()+10);
                checkedAll = false;
                break;
            }
        }
    }
    mItems.push_back(item);
}

/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i!=mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return nullptr;
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}

/**
 * Clear the aquarium data.
 *
 * Deletes all known items in the aquarium.
 */
void Game::Clear()
{
    mItems.clear();
}

///**
// * Save the aquarium as a .aqua XML file.
// *
// * Open an XML file and stream the aquarium data to it.
// *
// * @param filename The filename of the file to save the aquarium to
// */
//void Game::Save(const wxString& filename)
//{
//    wxXmlDocument xmlDoc;
//
//    auto root = new wxXmlNode(wxXML_ELEMENT_NODE, L"aqua");
//    xmlDoc.SetRoot(root);
//
//    // Iterate over all items and save them
//    for (auto item: mItems) {
//        item->XmlSave(root);
//    }
//
//    if (!xmlDoc.Save(filename, wxXML_NO_INDENTATION)) {
//        wxMessageBox(L"Write to XML failed");
//        return;
//    }
//}
//
///**
// * Load the aquarium from a .aqua XML file.
// *
// * Opens the XML file and reads the nodes, creating items as appropriate.
// *
// * @param filename The filename of the file to load the aquarium from.
// */
//void Game::Load(const wxString &filename)
//{
//    wxXmlDocument xmlDoc;
//    if(!xmlDoc.Load(filename))
//    {
//        wxMessageBox(L"Unable to load Aquarium file");
//        return;
//    }
//
//    Clear();
//    // Get the XML document root node
//    auto root = xmlDoc.GetRoot();
//
//    //
//    // Traverse the children of the root
//    // node of the XML document in memory!!!!
//    //
//    auto child = root->GetChildren();
//    for( ; child; child=child->GetNext())
//    {
//        auto name = child->GetName();
//        if(name == L"item")
//        {
//            XmlItem(child);
//        }
//    }
//}

///**
// * Handle a node of type item.
// * @param node XML node
// */
//void Game::XmlItem(wxXmlNode *node)
//{
//    // A pointer for the item we are loading
//    shared_ptr<Item> item;
//
//    // We have an item. What type?
//    auto type = node->GetAttribute(L"type");
//    if (type == L"beta")
//    {
//        item = make_shared<FishBeta>(this);
//    }
//    if (type == L"goldeen")
//    {
//        item = make_shared<FishGoldeen>(this);
//    }
//    if (type == L"magikarp")
//    {
//        item = make_shared<FishMagikarp>(this);
//    }
//    if (type == L"castle")
//    {
//        item = make_shared<DecorCastle>(this);
//    }
//
//    if (item != nullptr)
//    {
//        Add(item);
//        item->XmlLoad(node);
//    }
//}


