/**
 * @file PowerUp.h
 * @author Yousif Murrani
 *
 * Base class for the item PowerUp.
 */

#ifndef PROJECT1_POWERUP_H
#define PROJECT1_POWERUP_H

#include "Item.h"

/**
*  Base class for the item PowerUp.
*/
class PowerUp : public Item
{
private:
    /// The game window this item in going to be in
    Game *mGame;

    /// Bool if the powerup was collected
    bool mCollected = false;

    /// X and Y value of the text
    int mTextX = -1000;
    int mTextY = -1000;

    /// Height and Width of the Font
    int mFontHeight = 25;
    int mFontWidth = 50;
public:
    /// Default constructor (disabled)
    PowerUp() = delete;

    /// Copy constructor (disabled)
    PowerUp(const PowerUp&) = delete;

    /// Assignment operator
    void operator=(const PowerUp&) = delete;

    PowerUp(Level* level, const std::wstring &filename, Game* game);

     void XmlLoad(wxXmlNode *node) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPowerUp(this); }

    bool CollisionTest(Item* item) override;

    void TuitionUp();

    void Update(double elapsed);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //PROJECT1_POWERUP_H
