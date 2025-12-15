/*
	Nguyen, Minh Thang (Team Leader)

	Fall 2025
	CS A250 - C++ 2

	Bot Elections
*/

#include "Election.h"

#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

void Election::addClubs(const vector<string>& theClubs)
{
	clubs = theClubs;
}

void Election::addBots(const string& botName, 
					   const vector<int>& votesForBot)
{
	electoralVotes.insert(make_pair(botName, votesForBot));
}

bool Election::noDataFound() const
{
	return clubs.empty() || electoralVotes.empty();
}

void Election::printAllBots() const
{
	for (const auto& pair : electoralVotes)
	{
		cout << pair.first << " ";
	}
	cout << "\n";
}

void Election::printBotVotesFromClub(const string& botName,
									 const string& clubName) const
{
	auto clubPositionIterator = find(clubs.begin(), clubs.end(),
									 clubName);
	auto botPositionIterator = electoralVotes.find(botName);

	cout << "\n\t" << botName << " received "
		 << botPositionIterator->second[
					static_cast<size_t>(distance(clubs.begin(), 
										clubPositionIterator))]
		 << " vote(s) from " << clubName << ".\n";
}

void Election::printBotTotalVotes(const string& botName) const
{
	auto botPositionIterator = electoralVotes.find(botName);
	int totalVotes = accumulate(botPositionIterator->second.begin(),
								botPositionIterator->second.end(), 0);
	cout << "\n\t" << botName << " received a total of " 
		 << totalVotes << " vote(s).\n";
}

void Election::printWinner() const
{
	string winner;
	int maxVotes = 0;
	auto endIterator = electoralVotes.end();
	for (auto it = electoralVotes.begin(); it != endIterator; ++it)
	{
		int totalVotes = accumulate(it->second.begin(), 
									it->second.end(), 0);
		if (totalVotes > maxVotes)
		{
			maxVotes = totalVotes;
			winner = it->first;
		}
	}
	cout << "\n\tWinner: " << winner 
		 << " with " << maxVotes << " vote(s).\n";
}

void Election::printFinalResults() const
{
	// Print header of the table
	cout << "\n\t" << left << setw(15) << "Bot";
	for (const auto& club : CLUB_ABBREVIATIONS)
	{
		cout << left << setw(3) << club;
	}
	cout << right << setw(8) << "Total\n"
		 << "\t" << string(52, '*') << "\n"; // Print separator line

	// Print each bot's votes
	for (const auto& pair : electoralVotes)
	{
		string botName = pair.first;
		vector<int> votesList = pair.second;

		cout << "\t" << left << setw(16) << botName;
		int totalVotes = 0;
		for (int votes : votesList)
		{
			cout << left << setw(3) << votes;
			totalVotes += votes;
		}
		cout << right << setw(6) << totalVotes << "\n";
	}
}

void Election::printAllClubs() const
{
	cout << "\n\t" << left << setw(9) << "CLUB" << "(abbreviation)\n"
		 << "\t" << string(23, '-') << "\n";
	for(int i = 0; i < NUMS_CLUBS; ++i)
	{
		cout << "\t" << left << setw(9)
			<< clubs[i] << "(" << CLUB_ABBREVIATIONS[i] << ")\n";
	}
}