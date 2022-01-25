#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

void initiateMatchmaking() {

	string gamemode, rounds;
	char proceed = 'N';

	system("CLS");

	cout << "~~~~~Gamemode~~~~~~" << endl << endl;
	Sleep(100);
	cout << "(1) Player vs player" << endl;
	Sleep(100);
	cout << "(2) Singleplayer" << endl;
	Sleep(100);
	cin >> gamemode;
	while (cin.fail()) {

		cin.clear();
		cin.ignore();
		cin >> gamemode;

	}

	if (gamemode != "1") {

		cout << endl << "How many rounds would you like to play?" << endl;
		cin >> rounds;

	}

}