/**
 * @file ItemVisitor.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_ITEMVISITOR_H
#define PROJECT1_ITEMVISITOR_H

class Background;
class Door;
class Enemy;
class Money;
class Platform;
class PowerUp;
class Wall;
class ReversePower;

/**
 * Item visitor base class
 */
class ItemVisitor {
public:
    virtual ~ItemVisitor() {}

    /**
     * Visit a door object
     * @param door Door we are visiting
     */
    virtual void VisitDoor(Door* door) {}

    /**
     * Visit a Enemy object
     * @param enemy Enemy we are visiting
     */
    virtual void VisitEnemy(Enemy* enemy) {}

    /**
     * Visit a Money object
     * @param money Money we are visiting
     */
    virtual void VisitMoney(Money* money) {}

    /**
     * Visit a Platform object
     * @param platform Platform we are visiting
     */
    virtual void VisitPlatform(Platform* platform) {}

    /**
     * Visit a power up object
     * @param powerUp power up object we are visiting
     */
    virtual void VisitPowerUp(PowerUp* powerUp) {}

    /**
     * Visit a wall object
     * @param wall Wall we are visiting
     */
    virtual void VisitWall(Wall* wall) {}

    /**
     * Visit a reverse power up object
     * @param reverse powerup we are visiting
     */
     virtual void VisitReversePower(ReversePower* reversePower) {}
};

#endif //PROJECT1_ITEMVISITOR_H
