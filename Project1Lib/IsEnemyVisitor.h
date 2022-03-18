/**
 * @file IsEnemyVisitor.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_ISENEMYVISITOR_H
#define PROJECT1_ISENEMYVISITOR_H

#include "ItemVisitor.h"

class IsEnemyVisitor : public ItemVisitor{
public:
    virtual void VisitEnemy(Enemy *enemy) override;

    bool IsEnemy() { return mIsEnemy; }

private:
    bool mIsEnemy = false;
};

#endif //PROJECT1_ISENEMYVISITOR_H
