/*
	Nguyen, Minh Thang (Team Leader)

    Fall 2025
    CS A250 - C++ 2

    Bot Elections
*/

#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <sstream>  

using namespace std;

void readBotData(BotList& botList)
{
    ifstream inputFile("bots.csv");
    if(!inputFile)
    {
        cerr << "*** Error opening bots.csv." << endl;
	}
    else
    {
        string line;
		getline(inputFile, line); // Skip header line

        string botName, botAbility, botTrait;
        istringstream lineStream;
        while (getline(inputFile, line))
        {
            lineStream.str(line);
			getline(lineStream, botName, ',');
			getline(lineStream, botAbility, ',');
			getline(lineStream, botTrait, ',');
			botList.insertBot(BotType(botName, botAbility, botTrait));
            lineStream.clear(); // Clear to store a new line
        }
		inputFile.close();
    }
}

void readElectionResults(Election& electionResults)
{
    ifstream inputFile("votes.csv");
    if(!inputFile)
    {
        cerr << "*** Error opening votes.csv." << endl;
    }
    else
    {
        string line;
        // Read clubs from the first line
        getline(inputFile, line);

        istringstream lineStream(line);
        string clubName;
        vector<string> clubs;
		clubs.reserve(NUMS_CLUBS); // Reserve space for efficiency
        // Skip the first entry which is "Bot Name"
        getline(lineStream, clubName, ',');
        while (getline(lineStream, clubName, ','))
        {
            clubs.push_back(clubName);
        }
        electionResults.addClubs(clubs);

		// Read bot votes from the remaining lines
        string botName, botVotes;
        vector<int> votesForBot;
		votesForBot.reserve(NUMS_CLUBS); // Reserve space for efficiency
        while (getline(inputFile, line))
        {
			lineStream.clear(); // Clear to store a new line
            lineStream.str(line);
            getline(lineStream, botName, ',');
			votesForBot.clear(); // Clear previous votes
            while (getline(lineStream, botVotes, ','))
            {
                votesForBot.push_back(stoi(botVotes));
            }
            electionResults.addBots(botName, votesForBot);
        }
        inputFile.close();
    }
}