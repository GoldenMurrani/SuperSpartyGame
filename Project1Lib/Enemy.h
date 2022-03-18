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

    ///enemy speed in y direction
    int mSpeedY = 50;

    /// Game the level door object is being loaded into
    Game *mGame;
public:
    /// Default constructor (disabled)
    Enemy() = delete;

    /// Copy constructor (disabled)
    Enemy(const Enemy &) = delete;

    /// Assignment operator
    void operator=(const Enemy &) = delete;

    /// Enemy constructor
    Enemy(Level* level, const std::wstring& filename, Game* game);

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitEnemy(this); }

    void Update(double elapsed) override;

    void XmlLoad(wxXmlNode *node) override;

    bool CollisionTest(Item* item) override;
};

#endif //PROJECT1_ENEMY_H
