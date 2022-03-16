/**
 * @file ReversePower.h
 * @author Yousif Murrani
 *
 * Base class for the Reverse Direction power up item
 */

#ifndef PROJECT1_REVERSEPOWER_H
#define PROJECT1_REVERSEPOWER_H

#include "Item.h"

using namespace std;

/**
 * Class for the reverse power up item
 */
class ReversePower : public Item
{
private:

    /// Bool if the powerup was collected or not.
    bool mCollected = false;

    /// Game this item is in
    Game* mGame;
public:
    /// Default constructor (disabled)
    ReversePower() = delete;

    /// Copy constructor (disabled)
    ReversePower(const ReversePower&) = delete;

    /// Assignment operator
    void operator=(const ReversePower&) = delete;

    /**
    * Constructor
    */
    ReversePower(Level* level, const wstring& filename, Game* game);

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
    void Accept(ItemVisitor* visitor) override { visitor->VisitReversePower(this); }

    /**
     * Collision test for reverse item
     * @param item to test collision against
     */
    bool CollisionTest(Item* item) override;

    /**
     * Reverse directions for Sparty
     */
     void ReverseDirections();

    /**
    * Handle updates for ReversePower
    * @param elapsed the time before last update
    */
    void Update(double elapsed);

};

#endif //PROJECT1_REVERSEPOWER_H
