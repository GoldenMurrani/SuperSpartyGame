/**
 * @file Game.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include <wx/graphics.h>

#include "Game.h"
#include "Sparty.h"
#include "Scoreboard.h"
#include "Timer.h"
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
const wstring Level3 = L"levels/level3.xml";

const double ScreenDuration = 3;
/**
 * Game Constructor
 */
Game::Game()
{
    mScoreBoard = make_shared<Scoreboard>(this);
    mTimer = make_shared<Timer>(this);
    mSparty = make_shared<Sparty>(this, GnomeImageName);
    mMoneyMult = 0;
    mLevel0 = make_shared<Level>(this);
    mLevel0 ->Load(Level0);
    mLevels.push_back(mLevel0);
    mLevel1 = make_shared<Level>(this);
    mLevel1 ->Load(Level1);
    mLevels.push_back(mLevel1);
    mLevel2 = make_shared<Level>(this);
    mLevel2 ->Load(Level2);
    mLevels.push_back(mLevel2);
    mLevel3 = make_shared<Level>(this);
    mLevel3 ->Load(Level3);
    mLevels.push_back(mLevel3);
    SetLevel(0);
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

    mGraphics = graphics;
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
    mSparty -> Draw(graphics);
    mScoreBoard->Draw(graphics);
    mTimer->Draw(graphics);
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
    if (mPlaying)
    {
        for (auto item : mItems)
        {
            item->Update(elapsed);
        }
        mSparty->Update(elapsed);
        //mScoreBoard -> Update(elapsed);
        mTimer ->Update(elapsed);
    }
    else
    {
        mDuration += elapsed;
        if (mDuration >= ScreenDuration)
        {
            mDuration = 0;
            SetLevel(mCurrentLevel);
            if (mNewLevel)
                mNewLevel = false;
            else if (!mSparty->GetDead()) {
                mPlaying = true;
            }
            else
                mSparty->SetDead(false);
        }
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
    mPlaying = false;
}


/**
 * Sets Items up in the game
 */
void Game::SetItems()
{
    Clear();
    auto checkSpeed = mSparty -> GetSpeed();
    // Undo previous power ups or debuffs from different levels
    if (checkSpeed < 0)
    {
        mSparty ->ReverseSpeed();
    }
    mStartx = mLevels[mCurrentLevel]->GetStartX();
    mStartY = mLevels[mCurrentLevel]->GetStartY();

    for (auto item : mLevels[mCurrentLevel]->GetItems())
    {
        mItems.push_back(item);
    }

    mSparty ->SetLocation(mStartx, mStartY);
    mSparty ->SetXVel(0);
    mSparty ->SetYVel(0);
}

shared_ptr<Item> Game::CollisionTest(Item* item)
{
    for (auto levelItem : mItems)
    {
        if (levelItem->GetX() == item->GetX() && levelItem->GetY() == item->GetY())
            continue;
        if (levelItem->CollisionTest(item))
        {
            return levelItem;
        }
        if (mSparty -> GetStopUpdate() == true)
        {
            return nullptr;
        }

    }
    return nullptr;
}

void Game::RemoveItem(Item* item)
{
  for (std::shared_ptr<Item> items : mItems)
  {
      if (items -> GetX() == item ->GetX() && items -> GetY() == item ->GetY()) {
          auto loc = find(std::begin(mItems), std::end(mItems), items);
          mItems.erase(loc);
          break;
      }
  }

}

/**
 * Handles the score
 * @param value value added to the score
 */
void Game::AddScore(int value){
     mScoreBoard->AddScore(value);
}

void Game::DrawScreen(std::shared_ptr<wxGraphicsContext> graphics, wxString info, int width, int height)
{
    wxFont font(wxSize(70 / mScale, 70 / mScale),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    graphics->SetFont(font,wxColour(0,0,90));
    graphics->DrawText(info,width / mScale / 2 - 20 * info.size() / mScale,height / mScale / 2 - 100 / mScale);
}

