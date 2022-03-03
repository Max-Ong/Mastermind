#include <iostream>
#include <string>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;

int columnsrows(int q);
void creditTitle(int rows, int columns);
string Security();
void mainmenu(string);

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	int columns = columnsrows(0);
	int rows = columnsrows(1);
	creditTitle(rows, columns);

loger:
	string user = Security();
	mainmenu(user);
	goto loger;

	return 0;
}