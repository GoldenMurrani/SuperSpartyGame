/**
 * @file Game.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <memory>
#include <random>
#include "Item.h"

/**
 * Main class that will represent our game
 */

class Game {

private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

public:
    void OnDraw(wxDC *dc);

    Game();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void Update(double elapsed);

    void Clear();

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
};

#endif //PROJECT1_GAME_H
