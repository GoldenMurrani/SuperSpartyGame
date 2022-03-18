/**
 * @file IsEnemyVisitor.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "IsEnemyVisitor.h"
#include "Enemy.h"


/** Visit a Enemy object
* @param enemy Enemy we are visiting */
void IsEnemyVisitor::VisitEnemy(Enemy* enemy)
{
    mIsEnemy = true;
}
