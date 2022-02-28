/**
 * @file MoneyVisitor.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "MoneyVisitor.h"

/// money amount for one money item
const int Amount = 10;

/**
 * Visit a Money object and collect it
 * @param money money item we are visiting
 */
void MoneyVisitor::VisitMoney(Money *money)
{
    mSparty->IncreaseMoney(Amount + Amount * mIncreasePercent / 10);
}

/**
 * Visit a Power up object and activate it
 * @param powerUp power up item we are visiting
 */
void MoneyVisitor::VisitPowerUp(PowerUp* powerUp)
{
    mIncreasePercent += 1;
}