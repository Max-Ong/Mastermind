#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void viewHowToPlay();
void initiateMatchmaking();

int main() {

	int menu;

	cout << "~~~~~Mastermind~~~~~" << endl << endl;

	cout << "(1) Start Game" << endl;
	Sleep(100);
	cout << "(2) How To Play" << endl;
	Sleep(100);
	cout << "(3) Leaderboards" << endl;
	Sleep(100);
	cout << "(4) Log Out" << endl;

	cin >> menu;

	while (cin.fail() || cin > 4 || cin < 1) {

		cin.clear();
		cin.ignore();
		cin >> menu;

	}

	if (menu == "1") {

		initiateMatchmaking();

	}

	return 0;
}