#include <iostream>
#include <utility>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#ifdef _WIN32
#include<Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int columnsrows(int q);
void leaderboardTitle();
void leaderboard();
void update(vector<pair<int, string>> scoreboard);
void addUser(string user);
void removeUser(string user);
void highScore(string user, int takenScore);
void podium();
string identifier(int realc);

void leaderboardTitle()
{
	int columns = columnsrows(0);

	int realc = (columns - 25) / 2;
	string x = identifier(realc);
	system("CLS");
	cout << " " << x + "|>| ================ |<|" + x << endl;
	cout << " " << x + "|>|   LEADERBOARD    |<|" + x << endl;
	cout << " " << x + "|>| ================ |<|" + x << endl << endl;
}

void leaderboard()
{
	ifstream inFile;
	string user, shortUser;
	string tempScore;
	int score;
	string all;
	vector<pair<int, string>> scoreboard;
	vector<pair<int, string>> shortScore;
	int columns = columnsrows(0);

	inFile.open("scoretest.txt");

	if (!inFile)
		cout << "Unable to open file.";
	else
	{
		while (getline(inFile, all))
		{
			user = all.substr(0, all.find('µ'));
			shortUser = user.substr(0, 16);
			tempScore = all.substr(all.find('µ') + 1);

			stringstream points(tempScore);
			points >> score;

			scoreboard.push_back(make_pair(score, user));
			shortScore.push_back(make_pair(score, shortUser));
		}
		sort(scoreboard.begin(), scoreboard.end());
		sort(shortScore.begin(), shortScore.end());
		update(scoreboard);
	}
	inFile.close();
	podium();
	cout << left;
	for (int i = 0; i < scoreboard.size(); i++)
	{
		for (int i = 0; i < (columns - 68) / 2; i++)
			cout << " ";
		cout << setw(59) << shortScore[i].second << shortScore[i].first << endl;
	}
}

void update(vector<pair<int, string>> scoreboard) //updates text file with names and scores in score order
{
	ofstream outFile;

	outFile.open("scoretest.txt");

	if (!outFile)
		cout << "Error";
	else
	{
		for (int i = 0; i < scoreboard.size(); i++)
			outFile << scoreboard[i].second << "µ" << scoreboard[i].first << endl;
	}
	outFile.close();
}

void addUser(string user) //add user and also set score to 0
{
	ofstream outFile;
	char space = 'µ';

	outFile.open("scoretest.txt", ofstream::app);

	if (!outFile)
		cout << "Unable to open file.";
	else
	{
		outFile << user << "µ2147483647" << endl;
	}
	outFile.close();
}

void removeUser(string user) // remove user and score
{
	ifstream inFile;
	ofstream outFile;
	string line;

	inFile.open("scoretest.txt");
	outFile.open("temp.txt");

	if (!inFile || !outFile)
		cout << "Error";
	else
	{
		while (getline(inFile, line))
		{
			if (line.substr(0, line.find('µ')) != user)
				outFile << line << endl;
		}
		outFile.close();
		inFile.close();
		remove("scoretest.txt");
		rename("temp.txt", "scoretest.txt");
	}
}

void podium()
{
	int columns = columnsrows(0);
	string all, name1, name2, name3;
	int score, i, n, y, len1, len2, len3; //i is counter for reading txt file, n is counter for centering name display, y is for centering podium
	ifstream inFile;
	inFile.open("scoretest.txt");
	if (!inFile) cout << "Error, cannot open file";
	else
	{
		for (i = 0; i < 1; i++) //read first line for first name
		{
			getline(inFile, all);
			name1 = all.substr(0, all.find('µ'));
			if (inFile.fail()) break;
		}
		for (i = 0; i < 1; i++) //read second line for second name
		{
			getline(inFile, all);
			name2 = all.substr(0, all.find('µ'));
			if (inFile.fail()) break;
		}
		for (i = 0; i < 1; i++) //read third line for third name
		{
			getline(inFile, all);
			name3 = all.substr(0, all.find('µ'));
			if (inFile.fail()) break;
		}

		len1 = name1.length();
		len2 = name2.length();
		len3 = name3.length();

		cout << "                      ";

		for (n = 0; n < (23 - len1) / 2; n++)  //centralise first name 
			cout << " ";
		if (len1 % 2 == 1) cout << " "; //if name1 has odd no. characters start 1 space later
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << name1.substr(0, 22) << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "                      ***********************" << endl;

		for (n = 0; n < (22 - len2) / 2; n++) //centralise second name
			cout << " ";
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		if (len2 % 2 == 1) cout << " "; //if name2 has odd no. characters start 1 space later
		cout << name2.substr(0, 22);
		for (n = 0; n < (22 - len2) / 2; n++)
			cout << " ";
		cout << "|         1st         |" << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "***********************                     |" << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "|         2nd                               |";

		for (n = 0; n < (22 - len3) / 2; n++) //centralise third name
			cout << " ";
		cout << name3.substr(0.22) << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "|                                           ***********************" << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "|                                                     3rd         |" << endl;
		for (y = 0; y < (columns - 68) / 2; y++) //centralise podium
			cout << " ";
		cout << "*******************************************************************" << endl;
	}
	inFile.close();
}

void highScore(string user, int takenScore)
{
	string all, name, tempScore;
	int score, points;
	ifstream inFile;
	ofstream outFile;
	inFile.open("scoretest.txt");
	outFile.open("temp.txt");
	if (!inFile) cout << "Error, cannot open file";
	else
	{
		while (getline(inFile, all))
		{
			name = all.substr(0, all.find('µ'));
			tempScore = all.substr(all.find('µ') + 1);
			stringstream points(tempScore);
			points >> score;

			if (user == name)
			{
				if (takenScore < score)
				{
					outFile << name << "µ" << takenScore << endl;
				}
				else
				{
					outFile << name << "µ" << score << endl;
				}
			}
			else
			{
				outFile << all << endl;
			}
		}
	}
	inFile.close();
	outFile.close();
	remove("scoretest.txt");
	rename("temp.txt", "scoretest.txt");
}

int columnsrows(int q)
{
	CONSOLE_SCREEN_BUFFER_INFO	csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	if (q == 0)
	{
		return columns;
	}
	else if (q == 1)
	{
		return rows;
	}
}

string identifier(int realc)
{
	string gg = "";
	for (int x = 0; x < realc; x++)
		gg += '#';

	return gg;
}