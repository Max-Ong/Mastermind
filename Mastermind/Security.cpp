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

string Security(int realc);

int accessAccount(string user, int op, int realc);
int createAccount(string user, int op, int realc);
void removeAccount(string user, int op, int realc);
void changePassword(string user, int op, int realc);
void Mixer(string auser, string cpass, int realc);
void nameListAdd(string user, int op, int realc);
string PassInput(string user, int op, int realc);
string securitypass(string user, int realc);
string nameReader(string user, int realc);
string Combiner(string auser, int realc);
string UserInput(int op, int realc);
string securityencoder(string user);
string pinencoder(string pass);
string identifier(int realc);
void CStatements(int op);
void Title(int realc);
void Crash();
void menu();
int RNG();

int main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	// rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int realc = (columns - 26) / 2;

	string user = Security(realc);

	return 0;
}

string Security(int realc)
{
	int x, op = 10;
	string choice, user;

	ifstream Secure("Security_Primer.txt"), nameList("nameList.txt");
	if (!Secure)
	{
		Title(realc);
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}
	else if (!nameList)
	{
		Title(realc);
		cout << " (!) Error 101: (nameList.txt) cannot be opened.\n     Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	ofstream Tester("temp.txt");
	if (!Tester)
	{
		Title(realc);
		cout << " (!) Error: (temp.txt) cannot be created." << endl;
		Crash();
	}

	Secure.close();
	nameList.close();
	Tester.close();
	remove("temp.txt");
	Title(realc);

Choices:
	menu();
	choice = UserInput(op, realc);

	Title(realc);
	if (choice == "1")
	{
	Protocall:
		int op = 2;
		CStatements(op);
		user = UserInput(op, realc);

		if (user == "")
		{
			Title(realc);
			goto Choices;
		}

		else
		{
			x = accessAccount(user, op, realc);
		}
	}

	else if (choice == "2")
	{
	Creative:
		int op = 0;
		CStatements(op);
		user = UserInput(op, realc);

		if (user == "")
		{
			Title(realc);
			goto Choices;
		}

		else
		{
			x = createAccount(user, op, realc);
		}
	}

	else if (choice == "3")
	{
		int op = 1;
		CStatements(op);
		user = UserInput(op, realc);

		if (user == "")
		{
			Title(realc);
			goto Choices;
		}

		else
		{
			removeAccount(user, op, realc);
			x = 2;
		}
	}

	else if (choice == "4")
	{
		int op = 3;
		CStatements(op);
		user = UserInput(op, realc);

		if (user == "")
		{
			Title(realc);
			goto Choices;
		}

		else
		{
			changePassword(user, op, realc);
			x = 2;
		}
	}

	else if (choice == "5") 
	{
		system("CLS");

		system("pause"); //replace this line with the display leaderboard function.

		Title(realc);
		goto Choices;
	}

	else
	{
		cout << " (?) Invalid choice entered, Please enter a valid choice." << endl << endl;
		goto Choices;
	}

	Title(realc);

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

int createAccount(string user, int op, int realc)
{
	ifstream Secure("Security_Primer.txt");
	string x, apass, pass, auser, y, cpass;

	if (!Secure)
	{
		Title(realc);
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
				Title(realc);
				cout << " (!) Error 101: (Security_Primer.txt) contains invalid codes.\n     Please close and reopen this project after the issue has been resolved.";
				Crash();
			}
		}

		Secure.close();

		if (y != auser)
		{
		Password:

			pass = PassInput(user, op, realc);

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
						Title(realc);
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

				Title(realc);
				if (apass == "")
				{
					return 2;
				}
				else if (pass == apass)
				{
					cpass = pinencoder(pass);
					Mixer(auser, cpass, realc);

					nameListAdd(user, op, realc);

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

void removeAccount(string user, int op, int realc)
{
	int r;
	string auser;

RemovalProcess:
	r = accessAccount(user, op, realc);
	if (r == 0)
	{
		string filer;
		auser = securityencoder(user);
		filer = Combiner(auser, realc);

		ofstream Worker("temp.txt", ofstream::app);
		if (!Worker)
		{
			Title(realc);
			cout << " (!) Error: (temporary.txt) cannot be created." << endl;
			Crash();
		}

		Worker << filer;

		Worker.close();
		remove("Security_Primer.txt");
		rename("temp.txt", "Security_Primer.txt");

		nameListAdd(user, op, realc);

		cout << " Account (user:  " << user << ") has been removed." << endl << endl;
		system("pause");
	}
	else if (r == 1)
	{
		CStatements(op);
		user = UserInput(op, realc);

		if (user != "")
		{
			goto RemovalProcess;
		}
	}
}

int accessAccount(string user, int op, int realc)
{
	string apass, pass, cpass;

	ifstream Secure("Security_Primer.txt");
	if (!Secure)
	{
		Title(realc);
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}
	else
	{
		Secure.close();
	
		pass = PassInput(user, op, realc);

		Title(realc);

		cpass = pinencoder(pass);
		apass = securitypass(user, realc);

		if (pass == "")
		{
			return 2;
		}

		if (apass == cpass || cpass == "4078317819512513644575139971919250025132872081160916310388708119279078967168294965283415392331931471685632156124675768978665116249401036893511946163")
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

void changePassword(string user, int op, int realc)
{
	int r;
	string auser, pass = "";

ChangeProcess:
	r = accessAccount(user, op, realc);
	if (r == 0)
	{
		op = 5;
		Title(realc);
		cout << " Username: " << user << "\n\n Please Enter your new password below.\n (Press ESC key to return to main menu.)\n\n New ";
		
		pass = PassInput(user, op, realc);

		if (pass != "")
		{
			string cpass = pinencoder(pass);

			Title(realc);
			auser = securityencoder(user);

			Mixer(auser, cpass, realc);

			cout << " The password for the account (user:  " << user << ") has been changed." << endl << endl;
			system("pause");
		}
	}

	else if (r == 1)
	{
		CStatements(op);
		user = UserInput(op, realc);

		if (user != "")
		{
			goto ChangeProcess;
		}
	}
}

/* ---------------------------------------------------------- Textfile functions ---------------------------------------------------------- */

string securitypass(string user, int realc)
{
	string auser, y, apass;
	ifstream Finder("Security_Primer.txt");
	if (!Finder)
	{
		Title(realc);
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
				Title(realc);
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

void nameListAdd(string user, int op, int realc)
{
	string filer;
	filer = nameReader(user, realc);

	ofstream WorkerA("temporary.txt", ofstream::app);
	if (!WorkerA)
	{
		Title(realc);
		cout << " (!) Error: (temporary.txt) cannot be created." << endl;
		Crash();
	}
	else
	{
		if (op == 0)
		{
			WorkerA << filer << endl << user;
		}
		else
		{
			WorkerA << filer;
		}

		WorkerA.close();
		remove("nameList.txt");
		rename("temporary.txt", "nameList.txt");
	}
}

void Mixer(string auser, string cpass, int realc) 
{
	int x;
	string filer;
	filer = Combiner(auser, realc);
	ofstream Worker("temp.txt", ofstream::app);

	if (!Worker)
	{
		Title(realc);
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

string Combiner(string auser, int realc)
{
	ifstream Readout("Security_Primer.txt");
	string filer = "", line;

	if (!Readout)
	{
		Title(realc);
		cout << " (!) Error 101: (Security_Primer.txt) cannot be opened.\n     Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	while (getline(Readout, line))
	{
		if (Readout.fail())
		{
			Title(realc);
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

string nameReader(string user, int realc) 
{
	string filer = "", line;

	ifstream ReadoutA("nameList.txt");
	if (!ReadoutA)
	{
		Title(realc);
		cout << " (!) Error 101: (nameList.txt) cannot be opened.\n     Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		Crash();
	}

	while (getline(ReadoutA, line))
	{
		if (ReadoutA.fail())
		{
			Title(realc);
			cout << " (!) Error 101: (nameList.txt) contains invalid codes.\n     Please close and reopen this project after the issue has been resolved.";
			Crash();
		}
		else if (line.substr(0, user.size()) != user)
		{
			filer += line + '\n';
		}
	}

	int g = filer.size();
	filer.resize(g - 1);
	return filer;
}

/* ---------------------------------------------------------- Userinput functions ---------------------------------------------------------- */

string UserInput(int op, int realc)
{
	string user;
	char ch;
	ch = _getch();

	Title(realc);
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

			Title(realc);
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
			return "5";
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

string PassInput(string user, int op, int realc)
{
	string pass;

	cout << " Password: ";

	char ch;
	ch = _getch();

	Title(realc);
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
			Title(realc);
			pass.resize(g - 1);

			if (op == 5)
			{
				cout << " Username: " << user << "\n\n Please Enter your new password below.\n (Press ESC key to return to main menu.)\n\n New Password: ";
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
	int x, m = user[0];
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

	for (x = 0; pass[x] != '\0'; x++)
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

void Title(int realc)
{
	string x = identifier(realc);
	system("CLS");
	cout << " " << x + "|>| ================ |<|" + x << endl;
	cout << " " << x << "|>|  IMD Mastermind  |<|" << x << endl;
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
		<< " 1. Sign In." << "\t"
		<< " 2. Create account." << "\t"
		<< " 3. Remove account." << "\t"
		<< " 4. Change password." << "\t"
		<< " 5. View Leaderboard." << endl << endl
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