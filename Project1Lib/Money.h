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

    double mMoneyValue = 0;

    Game *mGame;

public:
    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;

    Money(Level* level, const std::wstring& filename, Game* game);

    //void OnClear();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitMoney(this); }

    /**
     * Loads in the XML node for the money item
     * @param node to load in
     */
    void XmlLoad(wxXmlNode* node) override;

    /**
     * Checks collision between item and money
     * @param item to test collision with
     * @return bool if there was a collision or not
     */
    bool CollisionTest(Item* item) override;

    /**
     * Sets the Money Value
     */
     void SetMoney() { mMoneyValue = mMoneyValue + (mMoneyValue * .10); }

};

#endif //PROJECT1_MONEY_H
