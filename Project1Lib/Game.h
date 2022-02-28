/**
 * @file Game.h
 * @author Zongyuan Li
 *
 *  Main class that will represent our game.
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <memory>
#include <random>
#include "Item.h"
#include "Sparty.h"
#include "Background.h"
#include "Level.h"

/**
 * Main class that will represent our game
 */

class Game {

private:
    /// scale for game window
    double mScale;

    /// Sparty item
    std::shared_ptr<Sparty> mSparty;

    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Background item
    std::shared_ptr<Background> mBackground;

     ///
    std::shared_ptr<Level> mLevel0;

public:
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    Game();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void Update(double elapsed);

    void Clear();

    void Accept(ItemVisitor* visitor);

    /**
     * Get the sparty character in game
     * @return the shared pointer of the sparty item in game
     */
    std::shared_ptr<Sparty> GetSparty() {return mSparty; }

//    void XmlItem(wxXmlNode* node);
//
//    void Save(const wxString& filename);
//
//    void Load(const wxString& filename);

//    /**
//     * Get the width of the game
//     * @return Aquarium width in pixels
//     */
//    int GetWidth() const { return mBackground->GetWidth(); }
//
//    /**
//     * Get the height of the aquarium
//     * @return Aquarium height in pixels
//     */
//    int GetHeight() const { return mBackground->GetHeight(); }

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

};

#endif //PROJECT1_GAME_H
