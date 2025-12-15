/*
	Nguyen, Minh Thang (Team Leader)

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

void displayMenu()
{
	cout << string(45, '*') << "\n"
		<< "\t\tMAIN MENU\n"
		<< string(45, '*') << "\n\n"
		<< "Select one of the following:\n\n"
		<< "\t1: Print all bots\n"
		<< "\t2: Print all clubs\n"
		<< "\t3: Print a bot's votes from a club\n"
		<< "\t4: Print a bot's total votes\n"
		<< "\t5: Print winner\n"
		<< "\t6: Print final results\n"
		<< "\t7: To exit\n\n";
}

// Definition function exitMessage
void exitMessage()
{
	cout << "\n" << string(45, '-') << "\n" << string(2, ' ') 
		 << "Thanks for running the STEM Bot Election!\n"
		 << string(3, ' ') << "May the best bot serve wisely. Goodbye!\n"
		 << string(45, '-') << "\n";
}

// Definition function noDataMessage
void noDataMessage()
{
	cerr << "\n\t*** No data is available.\n"
		<< "\t*** Please contact the administrator." << endl;
}

// Definition function processMenu
void processMenu(const BotList& botList, const Election& election)
{
	cout << "Enter your choice: ";
	char userChoice;
	cin >> userChoice;
	while (userChoice != '7')
	{
		switch (userChoice)
		{
		case '1':
			// Print all bots
			if (botList.isEmpty())
			{
				noDataMessage();
			}
			else
			{
				botList.printAllBotsInfo();
			}
			break;

		case '2':
			// Print all clubs
			if (election.noDataFound())
			{
				noDataMessage();
			}
			else
			{
				election.printAllClubs();
			}
			break;

		case '3':
			// Print a bot's votes from a club
			if (election.noDataFound())
			{
				noDataMessage();
			}
			else
			{
				cout << "\nEnter bot's name: ";
				string botName;
				cin >> botName;
				cout << "Enter club's name: ";
				string clubName;
				cin >> clubName;
				election.printBotVotesFromClub(botName, clubName);
			}
			break;

		case '4':
			// Print a bot's total votes
			if (election.noDataFound())
			{
				noDataMessage();
			}
			else
			{
				cout << "\nEnter bot's name: ";
				string botName;
				cin >> botName;
				election.printBotTotalVotes(botName);
			}
			break;

		case '5':
			// Print winner
			if (election.noDataFound())
			{
				noDataMessage();
			}
			else
			{
				election.printWinner();
			}
			break;

		case '6':
			// Print final results
			if (election.noDataFound())
			{
				noDataMessage();
			}
			else
			{
				election.printFinalResults();
			}
			break;
		};
		cout << "\n";
		system("Pause");
		cout << "\n";
		displayMenu();
		cout << "Enter your choice: ";
		cin >> userChoice;
	};
	exitMessage();
}
