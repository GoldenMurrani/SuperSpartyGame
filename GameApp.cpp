/**
 * @file GameApp.cpp
 * @author ymurr
 */

#include "pch.h"
#include "GameApp.h"
#include <MainFrame.h>

/**
* Initialize application
*/

bool GameApp::OnInit()
{
    if(!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);
}