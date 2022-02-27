/**
 * @file Money.cpp
 * @author Vijay
 */
#include "pch.h"
#include "Money.h"
#include "Game.h"
#include <string>

using namespace std;
/// Money image file 1000
const wstring MoneyImageName = L"images/money100.png";
/// Initialization of money file 1000
const wstring MoneyTwoImageName = L"images/money1000.png";

/**
 * Constructor
 * @param game Game the money is a member of
 * @param filename File that sets mItem to bitmap
 */
Money::Money(Game *game, const std::wstring &filename) : Item(game, filename)
{
}