/*
	Nguyen, Minh Thang (Team Leader)

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "BotList.h"

#include <iostream>
#include <iomanip>

using namespace std;

void BotList::insertBot(const BotType& theBot)
{
	botList.insert(theBot);
}

int BotList::getCount() const
{
	return static_cast<int>(botList.size());
}

bool BotList::getBotByName(const string& name, 
							BotType& outBot) const
{
	if (!botList.empty())
	{
		BotType temporaryBot(name, "", "");
		auto positionIterator = botList.find(temporaryBot);

		if(positionIterator != botList.end())
		{
			outBot = *positionIterator;
			return true;
		}
	}
	return false;
}

bool BotList::isEmpty() const
{
	return botList.empty();
}

void BotList::printAllBotsNames() const
{
	for (const auto& bot : botList)
	{
		bot.printBotName();
	}
}

void BotList::printAllBotsInfo() const
{
	cout << "\n\t" << left << setw(17) << "BOT NAME" 
		 << "(ability, trait)\n\t"
		 << string(34, '-') << "\n";
	for (const auto& bot : botList)
	{
		bot.printBotInfo();
	}
}