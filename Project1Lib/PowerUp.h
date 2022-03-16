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


    /**
     * Constructor
     */
    PowerUp(Level* level, const std::wstring &filename, Game* game);

    /**
     * Load attributes for an item node
     *
     * Base class, override for specific items
     */
     void XmlLoad(wxXmlNode *node) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPowerUp(this); }

    /**
     * Collision test for tuition item
     * @param item to test collision against
     * @return bool to see if there was a collision or not
     */
    bool CollisionTest(Item* item) override;

    /**
     * Increases the amount per money item
     */
    void TuitionUp();

    /**
    * Handle updates for PowerUp
    * @param elapsed the time before last update
    */
    void Update(double elapsed);
};

#endif //PROJECT1_POWERUP_H
