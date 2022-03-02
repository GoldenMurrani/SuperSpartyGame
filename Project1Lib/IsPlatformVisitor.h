/**
 * @file IsPlatformVisitor.h
 * @author Zongyuan Li
 *
 *
 */

#ifndef PROJECT1_ISPLATFORMVISITOR_H
#define PROJECT1_ISPLATFORMVISITOR_H

#include "ItemVisitor.h"

class IsPlatformVisitor  :
        public ItemVisitor
{
public:
    virtual void VisitPlatform(Platform *platform) override;

    /**
     * check to see if the current tile is a building
     * @return true if current tile is a building, false otherwose
     */
    bool IsPlatform() { return mIsPlatform; }

private:
    bool mIsPlatform = false;  ///<boolean to determine the tile type, if it's a building, it's true
};

#endif //PROJECT1_ISPLATFORMVISITOR_H
