/**
 * @file Level.h
 * @author Matthew Hofmann
 *
 *
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include "Item.h"
#include "Sparty.h"

class Game;



class Level {
private:

    /// Game object item is in
    Game *mGame;

    /// Vector that holds the levels Items
    std::vector<std::shared_ptr<Item>> mItems;

    /// Vector that hold the levels declarations
    std::vector<wxXmlNode*> mVecDec;

    /// Level width
    double mWidth = 0;

    /// Level height
    double mHeight = 0;

    /// Sparty start x loaction
    double mStartx = 0;

    /// Sparty start y loaction
    double mStartY = 0;



public:

    //double GetWidth() {return mWidth;};
    //double GetHeight() {return mHeight;};

    /**
     * Gets startX for the level
     * @return Starting X coordinate for level
     */
    double GetStartX() {return mStartx;};

    /**
    * Gets startX for the level
    * @return Starting X coordinate for level
    */
    double GetStartY() {return mStartY;};

    void Load(const wxString &filename);

   void XmlDeclare(wxXmlNode* node);

   /**
    * Used for tests and getting access to level pointer
    * @return Level pointer
    */
   Level*  GetLevelTest(){ return this;}

   std::vector<std::wstring> GetNodeChildren(wxXmlNode *node);

   Level(Game * game);

    void XmlLevel(wxXmlNode* node);

    std::vector<std::wstring> XmlType(wxString nodeName, wxString typeId);

    void XmlItem(wxXmlNode* node);

    void Add(std::shared_ptr<Item> item);

    void LevelInfoSetter(wxXmlNode* node);

    const std::vector<std::shared_ptr<Item>>& GetItems() {return mItems;};

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * @param city The city we are iterating over
         * @param pos Position in the collection
         */
        Iter(Level* level, int pos) : mLevel(level), mPos(pos) {}

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
        std::shared_ptr<Item> operator *() const { return mLevel->mItems[mPos]; }

        /**
         * Increment the iterator
         * @return Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        Level* mLevel;   ///< City we are iterating over
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

    Level();

    void Clear();
};

#endif //PROJECT1_LEVEL_H
