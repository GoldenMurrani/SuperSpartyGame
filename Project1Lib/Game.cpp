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

/// Level 0 file location
const wstring Level0 = L"levels/level0.xml";

/// Level 1 file location
const wstring Level1 = L"levels/level1.xml";

/// Level 2 file location
const wstring Level2 = L"levels/level2.xml";

/// Level 3 file location
const wstring Level3 = L"levels/level3.xml";

/// Time for pause time to last on death or complete level
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
    SetLevel(3);
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
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    if (mPlaying)
    {
        for (auto item : mItems)
        {
            if (item !=nullptr) {
                item->Update(elapsed);
            }
        }
        mSparty->Update(elapsed);
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
 * @param numLevel Level that is to be set in the game
 */
void Game::SetLevel(int numLevel)
{

    mCurrentLevel = numLevel;
    SetItems();
}


/**
 *  Sets Items up in the game
 */
void Game::SetItems()
{
    Clear();
    auto checkSpeed = mSparty -> GetSpeed();
    // Undo previous power ups or debuffs from different levels and scoreboard and timer

    mPlaying = false;
    mTimer -> Reset();
    mScoreBoard -> ResetCash();
    mMoneyMult = 0;
    if (mSparty -> GetSpeedMult() != 1) {
        mSparty->SetSpeedMult(1);
    }
    if (checkSpeed < 0)
    {
        mSparty ->ReverseSpeed();
    }
    mStartx = mLevels[mCurrentLevel]->GetStartX();
    mStartY = mLevels[mCurrentLevel]->GetStartY();

    for (auto item : mLevels[mCurrentLevel]->GetItems())
    {
        mItems.push_back(item);
        item-> SetPosition();
    }

    mSparty -> SpartyReset();
    mSparty ->SetLocation(mStartx, mStartY);
    mSparty ->SetXVel(0);
    mSparty ->SetYVel(0);
}

/**
 * Checks if sparty collides with and item in mItems
 * @param item The item that is assumed to have collided with Spartu
 * @return The item pointer if it did collide, nullptr if it didn't
 */
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
        if (mSparty -> GetStopUpdate())
        {
            return nullptr;
        }
    }
    return nullptr;
}

/**
 * Removes item from mItems
 * @param item The items that is to be removed
 */
void Game::RemoveItem(Item* item)
{
  for (std::shared_ptr<Item> items : mItems)
  {
      if (items -> GetX() == item ->GetX() && items -> GetY() == item ->GetY()) {
          auto loc = find(std::begin(mItems), std::end(mItems), items);
          mItems.erase(loc);
          mItems.push_back(items);
          mItems.pop_back();

          break;
      }
  }

}

/**
 * Handles the score
 * @param value value added to the score
 */
void Game::AddScore(int value){
     mScoreBoard->AddScore(value*(1+mMoneyMult));
}

/**
 * Draws the screens after death or level completion or loading
 * @param graphics The device context to draw on
 * @param info The message that is to be drawn on screen
 * @param width The width of the message
 * @param height The height of the message
 */
void Game::DrawScreen(std::shared_ptr<wxGraphicsContext> graphics, wxString info, int width, int height)
{
    wxFont font(wxSize(70 / mScale, 70 / mScale),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    graphics->SetFont(font,wxColour(0,0,90));
    graphics->DrawText(info,width / mScale / 2 - 20 * info.size() / mScale,height / mScale / 2 - 100 / mScale);
}

