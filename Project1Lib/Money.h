/**
 * @file Money.h
 * @author Vijay
 *
 * Base class for the item money.
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H
#include "Item.h"


class Game;
/**
* Base class for the item money.
*/
class Money : public Item
{
private:

    /// Value of the money
    int mMoneyValue = 0;

    /// Bool if the money was collected
    bool mCollected = false;

    /// Game item is in
    Game *mGame;

public:
    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;

    Money(Level* level, const std::wstring& filename, Game* game);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitMoney(this); }

    void XmlLoad(wxXmlNode* node) override;

    bool CollisionTest(Item* item) override;

    void Update(double elapsed) override;

};

#endif //PROJECT1_MONEY_H
