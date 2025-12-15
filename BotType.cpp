/*
	Nguyen, Minh Thang (Team Leader)

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "BotType.h"

#include <iostream>
#include <iomanip>

using namespace std;

string BotType::getBotName() const
{
	return name;
}

string BotType::getBotAbility() const
{
	return ability;
}

string BotType::getBotTrait() const
{
	return trait;
}

void BotType::printBotName() const
{
	cout << "Bot name: " << name << "\n";
}

void BotType::printBotInfo() const
{
	cout << "\t" << left << setw(17) << name
		 << "(" << ability << ", " << trait << ")\n";
}

bool BotType::operator<(const BotType& otherBot) const
{
	return name < otherBot.name;
}
