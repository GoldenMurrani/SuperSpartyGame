/**
 * @file MainFrame.cpp
 * @author malpi
 */

#include "pch.h"
#include "MainFrame.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Game",
            wxDefaultPosition,  wxSize( 1000,800 ));

}