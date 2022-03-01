#include "Security.h"
using namespace std;

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	int columns = columnsrows(0);
	int rows = columnsrows(1);
	creditTitle(rows, columns);

	string user = Security();

	return 0;
}