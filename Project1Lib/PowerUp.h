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
    PowerUp(Level* level, const std::wstring &filename);

    /**
     * Load attributes for an item node
     *
     * Base class, override for specific items
     */
     void XmlLoad(wxXmlNode *node);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitPowerUp(this); }
};

#endif //PROJECT1_POWERUP_H
