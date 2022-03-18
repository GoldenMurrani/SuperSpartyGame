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
* Base class for the item PowerUp.
*/
class PowerUp : public Item
{
private:
    /// The game window this item in going to be in
    Game *mGame;

    /// Bool if the powerup was collected
    bool mCollected = false;
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
};

#endif //PROJECT1_POWERUP_H
