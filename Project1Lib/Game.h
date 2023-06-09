/**
 * @file Game.h
 * @author Zongyuan Li
 *
 *  Main class that will represent our game.
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <string>
#include <memory>
#include <random>
#include "Item.h"
#include "Sparty.h"
#include "Background.h"
#include "Level.h"
#include "Money.h"


class Scoreboard;
class Timer;

/**
 * Main class that will represent our game
 */
class Game {

private:
    /// scale for game window
    double mScale;

    /// Current Level
    int mCurrentLevel = 0;

    /// Sparty item
    std::shared_ptr<Sparty> mSparty;

    /// Money multiplier
    double mMoneyMult = 0;

    /// Scoreboard item
    std::shared_ptr<Scoreboard> mScoreBoard;

    /// Timer item
    std::shared_ptr<Timer> mTimer;

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

     /// Level zero
    std::shared_ptr<Level> mLevel0;

    /// Level one
    std::shared_ptr<Level> mLevel1;

    /// Level two
    std::shared_ptr<Level> mLevel2;

    /// Level three
    std::shared_ptr<Level> mLevel3;

    /// Contains all the levels to be selected from
    std::vector<std::shared_ptr<Level>> mLevels;

    /// Sparty start x loaction
    double mStartx = 0;

    /// Sparty start y loaction
    double mStartY = 0;

    /// The game is playing right now
   bool mPlaying = true;

   /// The duration count for update if the screen should be paused
   double mDuration = 0;

   /// Boolean that indicates if a new level should be loaded or not
   bool mNewLevel = false;

   //std::shared_ptr<wxGraphicsContext> mGraphics;


public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    Game();

    void Add(std::shared_ptr<Item> item);

    void Update(double elapsed);

    void Clear();

    void Accept(ItemVisitor* visitor);

    void SetLevel(int numLevel);

    /**
     * Gets a pointer of game
     * @return A pointer of the game class
     */
    Game* GetGameTest() {return this;};

    /**
     * Gets the size of mItems
     * @return Size of mItems
     */
    int GetItemVecSize(){return mLevels.size();}

    /**
     * Get the current level
     * @return the int of the current level
     */
     int GetCurrentLevel() { return mCurrentLevel; }

    /**
    * Get the current level
    * @param currentLevel int of the current level
    */
    void SetCurrentLevel(int currentLevel) { mCurrentLevel = currentLevel; }

    /**
     * Get the sparty character in game
     * @return the shared pointer of the sparty item in game
     */
    std::shared_ptr<Sparty> GetSparty() {return mSparty; }


    /**
     * Updates the money value
     */
     void AddMoneyValue() { mMoneyMult = mMoneyMult + .10; }

     /**
      * Gets the money multiplier
      * @return The money multiplier
      */
      double GetMult() { return mMoneyMult; }

    /** Iterator that iterates over the items */
    class Iter
    {
    public:
        /** Constructor
         * @param game The game we are iterating over
         * @param pos Position in the collection
         */
        Iter(Game* game, int pos) : mGame(game), mPos(pos) {}

        /**
         * Compare two iterators
         * @param other The other iterator we are comparing to
         * @return  true if this position is not equal to the other position
        */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /**
         * Get value at current position
         * @return Value at mPos in the collection
         */
        std::shared_ptr<Item> operator *() const { return mGame->mItems[mPos]; }

        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        Game* mGame;   ///< Game we are iterating over
        int mPos;       ///< Position in the collection
    };

    /**
     * Get an iterator for the beginning of the collection
     * @return Iter object at position 0
     */
    Iter begin() { return Iter(this, 0); }

    /**
     * Get an iterator for the end of the collection
     * @return Iter object at position past the end
     */
    Iter end() { return Iter(this, mItems.size()); }

    void SetItems();

    /**
     *  Gets the current level
     * @return Returns the current level as a pointer from the vector of levels
     */
    std::shared_ptr<Level> GetLevel(){return mLevels[mCurrentLevel]; }

    void RemoveItem(Item* item);

    std::shared_ptr<Item> CollisionTest(Item* item);

    /**
     * Set to false when game needs to be paused
     */
    void SetPlaying() { mPlaying = false;};

    void AddScore(int value);

    void DrawScreen(std::shared_ptr<wxGraphicsContext> graphics, wxString info, int width, int height);

    /**
     *  Returns the status of playing
     *  F@return The boolean that determines if game is in play or not
     */
    bool GetCurrentState(){return mPlaying; }

    /**
     * Sets the current state of the game to playing
     */
    void SetStatePlaying(){mPlaying = true; }

    /**
     * Returns the status if a new level should be loaded
     * @return The boolean that determines if a new level should be loaded or not
     */
    bool GetCurrentLevelState() {return mNewLevel; }

    /**
     * Sets the status of NewLevel
     * @param newLevel boolean that indicates if a new level should be loaded or not
     */
    void SetNewLevel(bool newLevel) {mNewLevel = newLevel; }
};

#endif //PROJECT1_GAME_H
