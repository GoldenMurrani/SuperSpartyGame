/**
 * @file IsPlatformVisitor.cpp
 * @author Zongyuan Li
 */

#include "pch.h"
#include "Platform.h"
#include "IsPlatformVisitor.h"

/** Visit a TileBuilding object
* @param building building tile we are visiting
*/
void IsPlatformVisitor::VisitPlatform(Platform *platform)
{
    mIsPlatform = true;
}