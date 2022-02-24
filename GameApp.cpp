/**
 * @file GameApp.cpp
 * @author ymurr
 */

#include "pch.h"
#include "GameApp.h"

/**
* Initialize application
*/

bool GameApp::OnInit()
{
    if(!wxApp::OnInit())
        return false;

    return true;
}