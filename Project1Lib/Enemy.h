/**
 * @file Enemy.h
 * @author Michael Than
 *
 * Base class for Enemy item.
 */

#ifndef PROJECT1_ENEMY_H
#define PROJECT1_ENEMY_H

#include "Item.h"

/**
* Base class for Enemy item.
*/
class Enemy : public Item{
private:
//    /// The underlying Enemy image
//    std::unique_ptr<wxImage> mItemImage;
//
//    /// The bitmap we can display for this Enemy
//    std::unique_ptr<wxBitmap> mItemBitmap;
    int mSpeedY = 50;
public:
    /// Default constructor (disabled)
    Enemy() = delete;

    /// Copy constructor (disabled)
    Enemy(const Enemy &) = delete;

    /// Assignment operator
    void operator=(const Enemy &) = delete;

    /// Enemy constructor
    Enemy(Level* level, const std::wstring &filename);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitEnemy(this); }

    /**
    * Handle updates in time of our enemy
    *
    * This is called before we draw and allows us to
    * move our enemy. We add our speed times the amount
     * of time that has elapsed.
    * @param elapsed Time elapsed since the class call
     */
    void Update(double elapsed);

    /**
    * Load the attributes for an item node.
     *
     * This is the  base class version that loads the attributes
     * common to all items. Override this to load custom attributes
    * for specific items.
    *
    * @param node The Xml node we are loading the item from
     */
    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_ENEMY_H
