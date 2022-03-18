/**
 * @file ReversePower.h
 * @author Yousif Murrani
 *
 * Base class for the Reverse Direction power up item
 */

#ifndef PROJECT1_REVERSEPOWER_H
#define PROJECT1_REVERSEPOWER_H

#include "Item.h"


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
    ReversePower(Level* level, const std::wstring& filename, Game* game);

    void XmlLoad(wxXmlNode *node) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitReversePower(this); }

    bool CollisionTest(Item* item) override;

    void ReverseDirections();

    void Update(double elapsed);

};

#endif //PROJECT1_REVERSEPOWER_H
