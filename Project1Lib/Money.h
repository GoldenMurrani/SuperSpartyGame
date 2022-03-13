/**
 * @file Money.h
 * @author Vijay
 *
 * Base class for the item money.
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H
#include "Item.h"

/**
* Base class for the item money.
*/
class Money : public Item{
private:

    double mMoneyValue = 0;

public:
    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;

    Money(Level* level, const std::wstring& filename);

    //void OnClear();

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitMoney(this); }

    void XmlLoad(wxXmlNode* node) override;


};

#endif //PROJECT1_MONEY_H
