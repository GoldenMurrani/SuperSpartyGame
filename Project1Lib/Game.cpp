/**
 * @file Game.cpp
 * @author Zongyuan Li
 */


#include "pch.h"
#include <wx/graphics.h>
#include "Game.h"
#include "Sparty.h"
#include "Background.h"
#include "Enemy.h"

using namespace std;

/// Game area height in virtual pixels
const static int Height = 1024;

///gnome image temporary
const wstring GnomeImageName = L"images/gnome.png";

///enemy image temporary
const wstring EnemyImageName = L"images/UofM.png";

/// Temp image background
const wstring BackgroundImageName = L"images/backgroundColorGrass.png";

/// Level 0 file loacation
const wstring Level0 = L"levels/level0.xml";
const wstring Level1 = L"levels/level1.xml";
const wstring Level2 = L"levels/level2.xml";

/**
 * Game Constructor
 */
Game::Game()
{
    //mBackground = make_shared<Background>(this, BackgroundImageName);
    //mBackground->SetLocation(512,512);
    mSparty = make_shared<Sparty>(this, GnomeImageName);
    mLevel0 = make_shared<Level>(this);
    mLevel0 ->Load(Level0);
    mLevels.push_back(mLevel0);
    mLevel1 = make_shared<Level>(this);
    mLevel1 ->Load(Level1);
    mLevels.push_back(mLevel1);
    mLevel2 = make_shared<Level>(this);
    mLevel2 ->Load(Level2);
    mLevels.push_back(mLevel2);

}


/**
 * Draw the game
 * @param graphics The device context to draw on
 * @param width width of the window
 * @param height height of the window
 */
void Game::OnDraw(shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    mScale = double(height) / double(Height);
    graphics->Scale(mScale, mScale);

    auto virtualWidth = (double)width/mScale;
    // Compute the amount to scroll in the X dimension
    auto xOffset = (double)-mSparty->GetX() + virtualWidth / 2.0f;

    graphics->PushState();
    graphics->Translate(xOffset, 0);

    //
    // Draw in virtual pixels on the graphics context
    //

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }

    graphics->PopState();
}

/**
 * Add an item to the game
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
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
      //      return *i;
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
    mLevels[mCurrentLevel]->CollisionTest(mSparty);
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

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Sets the current Level
 * @param numLevel
 */
void Game::SetLevel(int numLevel)
{
    mCurrentLevel = numLevel;
    SetItems();
}

void Game::SetItems()
{
    Clear();
    mWidth = mLevels[mCurrentLevel]->GetWidth();
    mHeight = mLevels[mCurrentLevel]->GetHeight();
    mStartx = mLevels[mCurrentLevel]->GetStartX();
    mStartY = mLevels[mCurrentLevel]->GetStartY();
    for (auto item : mLevels[mCurrentLevel]->GetItems())
    {
        mItems.push_back(item);
    }

    Add(mSparty);
    mSparty ->SetLocation(mStartx, mStartY);
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


