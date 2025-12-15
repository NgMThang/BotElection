/*
	Nguyen, Minh Thang (Team Leader)

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "FileReader.h"
#include "BotList.h"
#include "Election.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
	// Create a BotList object and read bot data into it
	BotList myBotList;
	readBotData(myBotList);

	// Create an Election object and read election results into it
	Election myElection;
    readElectionResults(myElection);

	displayMenu();
	processMenu(myBotList, myElection);

    cout << endl;
    system("Pause");
    return 0;
}
