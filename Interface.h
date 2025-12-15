/*
	Nguyen, Minh Thang (Team Leader)

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Election.h"
#include "BotList.h"

void displayMenu();
void exitMessage();
void noDataMessage();
void processMenu(const BotList& botList, const Election& election);

#endif