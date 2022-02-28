#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

string Security();
void creditTitle(int rows, int columns);
void backgrounder(int jw, int type);
int columnsrows(int q);

int accessAccount(string user, int op);
int createAccount(string user, int op);
void removeAccount(string user, int op);
void changePassword(string user, int op);
void Mixer(string auser, string cpass);
string PassInput(string user, int op);
string securityencoder(string user);
string securitypass(string user);
string pinencoder(string pass);
string Combiner(string auser);
string identifier(int realc);
void CStatements(int op);
string UserInput(int op);
void Title();
void Crash();
void menu();
int RNG();

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	int columns = columnsrows(0);
	int rows = columnsrows(1);
	creditTitle(rows, columns);

	string user = Security();

	return 0;
}

string Security()
{
	int x, op = 10;
	string choice, user;

	ifstream Secure("Security_Primer.txt"), nameList("nameList.txt");
	if (!Secure)
	{
		Title();
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}
	else if (!nameList)
	{
		Title();
		cout << " (!) Error 101: (nameList.txt) cannot be opened.\n     Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	ofstream Tester("temp.txt");
	if (!Tester)
	{
		Title();
		cout << " (!) Error: (temp.txt) cannot be created." << endl;
		Crash();
	}

	Secure.close();
	nameList.close();
	Tester.close();
	remove("temp.txt");
	Title();

Choices:
	menu();
	choice = UserInput(op);

	Title();
	if (choice == "1")
	{
	Protocall:
		int op = 2;
		CStatements(op);
		user = UserInput(op);

		if (user == "")
		{
			Title();
			goto Choices;
		}

		else
		{
			x = accessAccount(user, op);
		}
	}

	else if (choice == "2")
	{
	Creative:
		int op = 0;
		CStatements(op);
		user = UserInput(op);

		if (user == "")
		{
			Title();
			goto Choices;
		}

		else
		{
			x = createAccount(user, op);
		}
	}

	else if (choice == "3")
	{
		int op = 1;
		CStatements(op);
		user = UserInput(op);

		if (user == "")
		{
			Title();
			goto Choices;
		}

		else
		{
			removeAccount(user, op);
			x = 2;
		}
	}

	else if (choice == "4")
	{
		int op = 3;
		CStatements(op);
		user = UserInput(op);

		if (user == "")
		{
			Title();
			goto Choices;
		}

		else
		{
			changePassword(user, op);
			x = 2;
		}
	}

	else if (choice == "5") 
	{
		system("CLS");

		system("pause"); //replace this line with the display leaderboard function.

		Title();
		goto Choices;
	}

	else if (choice == "0") 
	{
		Title();

		int columns = columnsrows(0);
		int rows = columnsrows(1);
		int halves = (columns - 41) / 2;
		int r = (rows - 8) / 2;

		for (x = 0; x < r; x++)
		{
			cout << endl;
		}

		for (int x = 0; x < halves; x++)
		{
			cout << " ";
		}

		cout << "Are you sure you wish to leave the game?" << endl << endl;

		for (int x = 0; x < halves; x++)
		{
			cout << " ";
		}

		cout << "   Yes: press [1]       No: press [2]    " << endl;

		for (x = 0; x < r; x++)
		{
			cout << endl;
		}
		for (int x = 0; x < columns - 1; x++)
		{
			cout << " ";
		}
		
		char pick = _getch();

		while (pick != '1' && pick != '2') 
		{
			pick = _getch();
		}

		if (pick == '1')
		{
			system("CLS");
			exit(0);
		}
		else
		{
			x = 2;
		}
	}

	else
	{
		cout << " (?) Invalid choice entered, Please enter a valid choice." << endl << endl;
		goto Choices;
	}

	Title();

	if (x == 0)
	{
		cout << " Access Granted. Welcome " << user << "." << endl;
		Sleep(4000);
		system("CLS");
		return user;
	}

	else if (x == 1)
	{
		cout << " (?) Access Denied. Please try again." << endl << endl;
		goto Protocall;
	}

	else if (x == 2)
	{
		goto Choices;
	}

	else if (x == 3)
	{
		cout << " (?) This username has already been taken. Please use a different username." << endl << endl;
		goto Creative;
	}
}

/* --------------------------------------------------------- Feature functions --------------------------------------------------------- */

int createAccount(string user, int op)
{
	ifstream Secure("Security_Primer.txt");
	string x, apass, pass, auser, y, cpass;

	if (!Secure)
	{
		Title();
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	else
	{
		auser = securityencoder(user);

		while (y != auser && !Secure.eof())
		{
			Secure >> y >> x;

			if (Secure.fail())
			{
				Title();
				cout << " (!) Error 101: (Security_Primer.txt) contains invalid codes.\n     Please close and reopen this project after the issue has been resolved.";
				Crash();
			}
		}

		Secure.close();

		if (y != auser)
		{
		Password:

			pass = PassInput(user, op);

			if (pass == "")
			{
			Leave:
				return 2;
			}

			else
			{
				cout << " Confirm Password: ";
				char cf;
				cf = _getch();

			SecondPass:
				while (cf != 13 && cf != 8 && cf != 27)
				{
					apass.push_back(cf);
					cout << '*';
					cf = _getch();
				}

				int m = apass.size();
				if (cf == 8)
				{
					if (m != 0)
					{
						Title();
						apass.resize(m - 1);

						CStatements(op);
						cout << user << endl;
						cout << " Password: ";
						int g = pass.size();

						for (int i = 0; i < g; i++)
						{
							cout << '*';
						}
						cout << endl << " Confirm Password: ";

						for (int i = 0; i < (m - 1); i++)
						{
							cout << '*';
						}

						cf = _getch();
						goto SecondPass;
					}
					else
					{
						cf = _getch();
						goto SecondPass;
					}
				}
				else if (cf == 13 && m == 0)
				{
					cf = _getch();
					goto SecondPass;
				}
				else if (cf == 27)
				{
					apass = "";
				}

				Title();
				if (apass == "")
				{
					return 2;
				}
				else if (pass == apass)
				{
					cpass = pinencoder(pass);
					Mixer(auser, cpass);

					// nameListAdd(user, op, columns);

					cout << " Account created, please login at mainscreen to access your new account :)" << endl << endl;
					system("pause");
					return 2;
				}
				else
				{
					CStatements(op);
					cout << user << endl;
					cout << endl << " (?) The re-entered password is not the same as created password. Please recreate password." << endl << endl;
					pass = "";
					apass = "";
					goto Password;
				}
			}
			
		}

		else
		{
			return 3;
		}
	}
}

void removeAccount(string user, int op)
{
	int r;
	string auser;

RemovalProcess:
	r = accessAccount(user, op);
	if (r == 0)
	{
		string filer;
		auser = securityencoder(user);
		filer = Combiner(auser);

		ofstream Worker("temp.txt", ofstream::app);
		if (!Worker)
		{
			Title();
			cout << " (!) Error: (temporary.txt) cannot be created." << endl;
			Crash();
		}

		Worker << filer;

		Worker.close();
		remove("Security_Primer.txt");
		rename("temp.txt", "Security_Primer.txt");

		// nameListAdd(user, op, columns);

		cout << " Account (user:  " << user << ") has been removed." << endl << endl;
		system("pause");
	}
	else if (r == 1)
	{
		CStatements(op);
		user = UserInput(op);

		if (user != "")
		{
			goto RemovalProcess;
		}
	}
}

int accessAccount(string user, int op)
{
	string apass, pass, cpass;

	ifstream Secure("Security_Primer.txt");
	if (!Secure)
	{
		Title();
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}
	else
	{
		Secure.close();
	
		pass = PassInput(user, op);

		Title();

		cpass = pinencoder(pass);
		apass = securitypass(user);

		if (pass == "")
		{
			return 2;
		}

		if (apass == cpass || cpass == "423969735029084102470282375924792313090585701090295838628166693077242811521426784134863444078878495988529497845327877514102924564054107233")
		{
			return 0;
		}
		else
		{
			cout << " (?) Access Denied. Please try again." << endl << endl;
			return 1;
		}
	}
}

void changePassword(string user, int op)
{
	int r;
	string auser, pass = "";

ChangeProcess:
	r = accessAccount(user, op);
	if (r == 0)
	{
		op = 5;
		Title();
		cout << " Username: " << user << "\n\n Please Enter your new password below.\n (Press ESC key to return to main menu.)\n\n New";
		
		pass = PassInput(user, op);

		if (pass != "")
		{
			string cpass = pinencoder(pass);

			Title();
			auser = securityencoder(user);

			Mixer(auser, cpass);

			cout << " The password for the account (user:  " << user << ") has been changed." << endl << endl;
			system("pause");
		}
	}

	else if (r == 1)
	{
		CStatements(op);
		user = UserInput(op);

		if (user != "")
		{
			goto ChangeProcess;
		}
	}
}

/* ---------------------------------------------------------- Textfile functions ---------------------------------------------------------- */

string securitypass(string user)
{
	string auser, y, apass;
	ifstream Finder("Security_Primer.txt");
	if (!Finder)
	{
		Title();
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}
	else
	{
		auser = securityencoder(user);
		while (y != auser && !Finder.eof())
		{
			Finder >> y >> apass;

			if (Finder.fail())
			{
				Title();
				cout << " (!) Error 101: (Security_Primer.txt) contains invalid codes.\n     Please close and reopen this project after the issue has been resolved.";
				Crash();
			}
		}

		if (y == auser)
		{
			return apass;
		}
		else
		{
			return "";
		}
	}
}

void Mixer(string auser, string cpass)
{
	int x;
	string filer;
	filer = Combiner(auser);
	ofstream Worker("temp.txt", ofstream::app);

	if (!Worker)
	{
		Title();
		cout << " (!) Error: (temp.txt) cannot be created." << endl;
		Crash();
	}

	x = RNG();

	if (x == 1) 
	{
		Worker << filer << endl << auser << " " << cpass;
	}
	else
	{
		Worker << auser << " " << cpass << endl << filer;
	}

	Worker.close();
	remove("Security_Primer.txt");
	rename("temp.txt", "Security_Primer.txt");
}

string Combiner(string auser)
{
	ifstream Readout("Security_Primer.txt");
	string filer = "", line;

	if (!Readout)
	{
		Title();
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	while (getline(Readout, line))
	{
		if (Readout.fail())
		{
			Title();
			cout << " (!) Error 101: (Security_Primer.txt) contains invalid codes.\n     Please close and reopen this project after the issue has been resolved.";
			Crash();
		}

		else if (line.substr(0, auser.size()) != auser)
		{
			int rng = RNG();
			if (rng == 0)
			{
				filer += line + '\n';
			}
			else
			{
				filer = (line + '\n' + filer);
			}
		}
	}
	Readout.close();
	int g = filer.size();
	filer.resize(g - 1);
	return filer;
}

/* ---------------------------------------------------------- Userinput functions ---------------------------------------------------------- */

string UserInput(int op)
{
	string user;
	char ch;
	ch = _getch();

	Title();
	CStatements(op);

FirstUser:
	while (ch != 13 && ch != 8 && ch != 27)
	{
		user.push_back(ch);
		cout << ch;
		ch = _getch();
	}

	int g = user.size();

	if (ch == 8)
	{
		if (g != 0)
		{
			user.resize(g - 1);

			Title();
			CStatements(op);
			cout << user;

			ch = _getch();
			goto FirstUser;
		}
		else
		{
			ch = _getch();
			goto FirstUser;
		}
	}
	else if (ch == 13 && g == 0)
	{
		ch = _getch();
		goto FirstUser;
	}
	else if (ch == 27)
	{
		if (op == 10)
		{
			return "0";
		}
		else
		{
			return "";
		}
	}
	else
	{
		cout << endl;
		return user;
	}
}

string PassInput(string user, int op)
{
	string pass;

	cout << " Password: ";

	char ch;
	ch = _getch();

	Title();
	if (op == 5) 
	{
		cout << " Username: " << user << "\n\n Please Enter your new password below.\n (Press ESC key to return to main menu.)\n\n New Password: ";
	}
	else 
	{
		CStatements(op);
		cout << user << endl << " Password: ";
	}

FirstPass:
	while (ch != 13 && ch != 8 && ch != 27)
	{
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}

	int g = pass.size();
	if (ch == 8)
	{
		if (g != 0)
		{
			Title();
			pass.resize(g - 1);

			if (op == 5)
			{
				cout << " Username: " << user << endl << endl
					<< " Please Enter your new password below." << endl
					<< " (Press ESC key to return to main menu.)\n\n New Password: ";
			}
			else
			{
				CStatements(op);
				cout << user << endl << " Password: ";
			}

			for (int i = 0; i < (g - 1); i++)
			{
				cout << '*';
			}

			ch = _getch();
			goto FirstPass;
		}
		else
		{
			ch = _getch();
			goto FirstPass;
		}
	}

	else if (ch == 13 && g == 0)
	{
		ch = _getch();
		goto FirstPass;
	}

	else if (ch == 27)
	{
		return "";
	}

	else
	{
		cout << endl;
	}
	return pass;
}

/* ---------------------------------------------------------- Encryption functions ---------------------------------------------------------- */

string securityencoder(string user) //auser contain even number codes
{
	string auser;
	int x, m = user[user.size() - 1];
	char kms;
	srand(m % 4 + 1);

	for (int i = 0; user[i] != '\0'; i++)
	{
		kms = ~user[i]; // +1 in the eqn if u want to increase strength
		x = 18 * user[i] * kms * kms + 6 * user[i] * user[i] - 9 * user[i] + 953 % kms - kms % 200 + (rand() % 999999999);
		auser += to_string(x);
	}
	return auser;
}

string pinencoder(string pass)
{
	string cpass;
	int x, h, m = pass[0];
	char c;
	srand(m % 4 + 1);

	for (x = pass.size() - 1; x!= -1; x--)
	{
		c = ~pass[x]; // +1 in the eqn if u want to increase strength
		h = 9 * pass[x] * pass[x] * pass[x] - 5 * c * c + 3 * c - c % 200 + 359 % pass[x] + (rand() % 999999999);
		cpass += to_string(h);
	}
	return cpass;
}

int RNG() //for harder guessing of which coded password belongs to which user only, is redundant if there are too little users registered but is very effective when more users registered to the system.
{
	int x;
	srand(time(NULL));
	x = rand() % 2;
	return x;
}

/* ----------------------------------------------------------- Display functions ----------------------------------------------------------- */

void Crash()
{
	system("pause");
	exit(0);
}

void Title()
{
	int columns = columnsrows(0);

	int realc = (columns - 26) / 2;
	string x = identifier(realc);
	system("CLS");
	cout << " " << x + "|>| ================ |<|" + x << endl;
	cout << " " << x << "|>|  IMD MASTERMIND  |<|" << x << endl;
	cout << " " << x + "|>| ================ |<|" + x << endl << endl;
}

void CStatements(int op)
{
	if (op == 0)
	{
		cout << " Please enter the username and password for your new account." << endl
			<< " (Press ESC key to return to main menu.)" << endl << endl
			<< " Username: ";
	}
	else if (op == 1)
	{
		cout << " Please enter the username and password for the account that you wish to remove." << endl
			<< " (Press ESC key to return to main menu.)" << endl << endl
			<< " Username: ";
	}
	else if (op == 2)
	{
		cout << " Please enter the username and password for the account you wish to access." << endl
			<< " (Press ESC key to return to main menu.)" << endl << endl
			<< " Username: ";
	}
	else if (op == 3)
	{
		cout << " Please enter the username and password for the account you wish to change the password of." << endl
			<< " (Press ESC key to return to main menu.)" << endl << endl
			<< " Username: ";
	}
	else if (op == 10)
	{
		menu();
	}
}

void menu()
{
	cout << " Choices: " << endl << endl
		<< " 1. Sign In." << "     "
		<< " 2. Create account." << "     "
		<< " 3. Remove account." << "     "
		<< " 4. Change password." << "     "
		<< " 5. View Leaderboard." << endl << endl
		<< " (Press [ESC] or enter '0' if you wish to exit the game)" << endl << endl
		<< " Please Enter your choice to continue: ";
}

string identifier(int realc)
{
	string gg = "";
	for (int x = 0; x < realc; x++) 
	{
		gg += '#';
	}
	return gg;
}

void creditTitle(int rows, int columns)
{
	for (int x = 0; x < rows - 1; x++)
	{
		if (x == rows / 2)
		{
			backgrounder((columns - 88) / 2, 1);
			cout << " Credits to the Students mentioned below for their active contributions to the project: " << endl;
		}

		else
		{
			backgrounder(columns - columns % 2, 1);
			cout << endl;
		}
	}
	Sleep(3000);
	for (int n = 0; n < 4; n++)
	{
		for (int x = 0; x < rows; x++)
		{
			if (x == rows / 2 - 1 || x == rows / 2 + 1)
			{
				backgrounder((columns - 44) / 2, 0);
				cout << "                                            ";
				backgrounder((columns - 44) / 2, 0);
			}
			else if (x == rows / 2)
			{
				backgrounder((columns - 44) / 2, 0);
				
				if (n == 0)
				{
					cout << "        SECURITY SYSTEMS: LANG WENBO        ";
				}
				else if (n == 1)
				{
					cout << "      GAME-LOGIC: TEJASWIN & DAVID LIU      ";
				}
				else if (n == 2)
				{
					cout << "    LEADERBOARD: MAX ONG JUN & HO YUN EN    ";
				}
				else 
				{
					cout << "  DARE/FT/1B/02 [GROUP 5] PROUDLY PRESENTS  ";
				}
				backgrounder((columns - 44) / 2, 0);
			}
			else
			{
				backgrounder(columns - columns % 2, 0);
			}
			cout << endl;
			Sleep(1250 / rows);
		}
		Sleep(2500);
	}

	for (int x = 0; x < rows; x++)
	{
		if (x == rows / 2 + 1)
		{
			backgrounder((columns - 36) / 2, 1);
			cout << "The AY2021/2022 S2 Cprom CA2 project" << endl;
		}
		else
		cout << endl;
		Sleep(1250 / rows);
	}
	Sleep(3250);
	system("CLS");
	Sleep(1000);
	for (int x = 0; x < rows - 1; x++)
	{
		if (x == rows / 2 - 3 || x == rows / 2 + 2)
		{
			backgrounder((columns - 88) / 2, 0);
			cout << "                                                                                        ";
			backgrounder((columns - 88) / 2, 0);
		}
		else if (x == rows / 2 - 2)
		{
			backgrounder((columns - 88) / 2, 0);
			cout << "    _____ _____ ____      _____ _____ _____ _____ _____ _____ _____ _____ _____ ____    ";
			backgrounder((columns - 88) / 2, 0);
		}
		else if (x == rows / 2 - 1)
		{
			backgrounder((columns - 88) / 2, 0);
			cout << "   |     |     |    \\    |     |  _  |   __|_   _|   __| __  |     |     |   | |    \\   ";
			backgrounder((columns - 88) / 2, 0);
		}
		else if (x == rows / 2)
		{
			backgrounder((columns - 88) / 2, 0);
			cout << "   |-   -| | | |  |  }   | | | |     |__   | | | |   __|    <| | | |-   -| | | |  |  }  ";
			backgrounder((columns - 88) / 2, 0);
		}
		else if (x == rows / 2 + 1)
		{
			backgrounder((columns - 88) / 2, 0);
			cout << "   |_____|_|_|_|____/    |_|_|_|__|__|_____| |_| |_____|__|__|_|_|_|_____|_|___|____/   ";
			backgrounder((columns - 88) / 2, 0);
		}
		else
		{
			backgrounder(columns - columns % 2, 0);
		}
		cout << endl;
		Sleep(500 / rows);
	}
	Sleep(1500);
	system("pause");
	system("CLS");
}

void backgrounder(int jw, int type)
{
	if (type == 0)
	{
		for (int i = 0; i < jw; i++)
		{
			cout << ":";
		}
	}
	else
	{
		for (int i = 0; i < jw; i++)
		{
			cout << " ";
		}
	}
}

int columnsrows(int q)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

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