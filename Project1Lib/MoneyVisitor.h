/**
 * @file MoneyVisitor.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_MONEYVISITOR_H
#define PROJECT1_MONEYVISITOR_H

#include "Sparty.h"

/**
 * class of deal with money calculation
 */
class MoneyVisitor : public ItemVisitor{
private:
    /// Sparty item
    std::shared_ptr<Sparty> mSparty;

    /// int indicates the percent of money amount should be increased
    int mIncreasePercent = 0;

public:
    void VisitMoney(Money* money) override;
    void VisitPowerUp(PowerUp* powerUp) override;
};

#endif //PROJECT1_MONEYVISITOR_H
