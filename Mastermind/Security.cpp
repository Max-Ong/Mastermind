#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <Windows.h>
#include <conio.h>

using namespace std;

int accessAccount(string user);
int createAccount(string user);
void removeAccount(string user);
string securityencoder(string user);
string securitypass(string user);
int passencoder(char subpass);
char passdecoder(int h);

int main() 
{
	int x;
	string choice, user;

	cout << "=========== Security Menu ===========" << endl << endl;

Choices:
	cout << "1. Sign In." << endl
		<< "2. Create account." << endl
		<< "3. Remove account." << endl << endl
		<< "Please Enter your choice to continue: ";
	cin >> choice;

	system("CLS");
	cout << "=========== Security Menu ===========" << endl << endl;

	if (choice == "1") 
	{
	Protocall:
		cout << "Please enter the username and password for the account you wish to access." << endl
			<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cin >> user;

		if (user == "0")
		{
			system("CLS");
			cout << "=========== Security Menu ===========" << endl << endl;
			goto Choices;
		}

		else
		{
			x = accessAccount(user);
		}
	}

	else if (choice == "2")
	{
	Creative:
		cout << "Please enter the username and password for your new account." << endl
			<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cin >> user;

		if (user == "0")
		{
			system("CLS");
			cout << "=========== Security Menu ===========" << endl << endl;
			goto Choices;
		}

		else
		{
			x = createAccount(user);
		}
	}

	else if (choice == "3")
	{
		cout << "Please enter the username and password for the account that you wish to remove." << endl
			<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cin >> user;

		if (user == "0") 
		{
			system("CLS");
			cout << "=========== Security Menu ===========" << endl << endl;
			goto Choices;
		}

		else
		{
			removeAccount(user);
			x = 2;
		}
	}

	else
	{
		cout << "(!) Invalid choice entered, Please enter a valid choice." << endl << endl;
		goto Choices;
	}

	system("CLS");
	cout << "=========== Security Menu ===========" << endl << endl;

	if (x == 0)
	{
		cout << "Access Granted. Welcome " << user << "." << endl;
		Sleep(8000);
		system("CLS");
		goto Programs;
	}

	else if (x == 1) 
	{
		cout << "(!) Access Denied. Please try again." << endl << endl;
		goto Protocall;
	}

	else if (x==2)
	{
		goto Choices;
	}

	else if (x == 3)
	{
		cout << "(!) This username has already been taken. Please use a different username." << endl << endl;
		goto Creative;
	}

Programs:

	system("pause");
	return 0;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

int accessAccount(string user)
{
	ifstream Secure("Security_Primer.txt");
	string apass, pass;

	if (!Secure)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;	
		system("pause");
		return 2;
	}

	else
	{
		Secure.close();
		cout << "Password: ";

		char ch;
		ch = _getch();
		while (ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		cout << endl;

		system("CLS");
		cout << "=========== Security Menu ===========" << endl << endl;

		apass = securitypass(user);

		if (pass == "0" || apass == "0")
		{
			return 2;
		}

		else if (pass == apass)
		{
			return 0;
		}

		else
		{
			cout << "(!) Access Denied. Please try again." << endl << endl;
			return 1;
		}
	}
}

int createAccount(string user)
{
	ofstream Worker("temp.txt", ofstream::app);
	ifstream Secure("Security_Primer.txt"), Readout("Security_Primer.txt");
	string apass, pass, auser, y, work;
	int h;

	if (!Secure)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		system("pause");

		Secure.close();
		Worker.close();
		Readout.close();
		remove("temp.txt");

		return 0;
	}

	else if (!Worker)
	{
		cout << "(!) Error: (temp.txt) cannot be created." << endl;
		system("pause");

		Secure.close();
		Worker.close();
		Readout.close();
		remove("temp.txt");

		return 0;
	}

	else 
	{
		auser = securityencoder(user);

		while (y != auser && !Secure.eof())
		{
			Secure >> y;

			if (Secure.fail()) 
			{
				cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
				break;
				system("pause");
			}
		}
		if (y != auser)
		{
		Password:
			cout << "Password: ";

			char ch;
			ch = _getch();
			while (ch != 13)
			{
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}

			cout << endl;

			if (pass == "0")
			{
				Secure.close();
				Worker.close();
				Readout.close();
				remove("temp.txt");

				return 2;
			}

			else
			{
				int x;
				char spass[40];
				char subpass;

				strncpy_s(spass, pass.c_str(), sizeof(spass));
				spass[sizeof(spass) - 1] = 0;

				for (x = 0; spass[x] != '\0'; x++) 
				{
					subpass = spass[x];
					h = passencoder(subpass);
					apass += passdecoder(h);
				}
				cout << "Confirm Password: ";

				char ch;
				ch = _getch();
				while (ch != 13)
				{
					pass.push_back(ch);
					cout << '*';
					ch = _getch();
				}

				cout << endl;

				system("CLS");
				cout << "=========== Security Menu ===========" << endl << endl;

				if (pass == "0" || apass == "0")
				{
					Secure.close();
					Worker.close();
					Readout.close();
					remove("temp.txt");
					return 2;
				}

				else if (pass == apass)
				{
					for (x = 0; spass[x] != '\0'; x++)
					{
						subpass = spass[x];
						h = passencoder(subpass);
						work += (" ") + to_string(h);
					}

					string line;
					while (getline(Readout, line))
					{
						if (line.substr(0, auser.size()) != auser) 
						{
							Worker << line << endl;
						}
					}
					
					Worker << auser << work;

					Secure.close();
					Worker.close();
					Readout.close();
					remove("Security_Primer.txt");
					rename("temp.txt", "Security_Primer.txt");
					cout << "Account created, please login at mainscreen to access your new account :)" << endl << endl;
					system("pause");
					return 2;
				}

				else
				{
					cout << "Please enter the username and password for your new account." << endl
						<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
						<< "Username: " << user << endl;
					cout << endl << "(!) The re-entered password is not the same as created password. Please recreate password." << endl << endl;
					goto Password;
				}
			}
		}

		else
		{
			Secure.close();
			Worker.close();
			Readout.close();
			remove("temp.txt");

			return 3;
		}
	}
}

void removeAccount(string user)
{
	int r;
	string auser;
	string gone;

	ifstream Remover("Security_Primer.txt");
	ofstream Editor("temporary.txt");

	if (!Remover)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		system("pause");
	}

	else if (!Editor)
	{
		cout << "(!) Error: (temporary.txt) cannot be created." << endl;
		system("pause");
	}

	else
	{
	RemovalProcess:
		r = accessAccount(user);
	
		if (r == 0)
		{
			
			auser = securityencoder(user);

			string filer;

			while (getline(Remover, gone))
			{
				if (gone.substr(0, auser.size()) != auser)
				{
						filer += gone + '\n';
				}
			}

			int g = filer.size();
			filer.resize(g - 1);
			Editor << filer;

			Remover.close();
			Editor.close();
			remove("Security_Primer.txt");
			rename("temporary.txt", "Security_Primer.txt");

			cout << "Account (user:  " << user << ") has been removed." << endl;

			system("pause");
			system("CLS");
			cout << "=========== Security Menu ===========" << endl << endl;
		}

		else if (r == 1)
		{
			cout << "Please enter the username and password for the account that you wish to remove." << endl
				<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
				<< "Username: ";
			cin >> user;

			if (user == "0")
			{
				Remover.close();
				Editor.close();
				remove("temporary.txt");

				system("CLS");
				cout << "=========== Security Menu ===========" << endl << endl;
			}

			else
			{
				goto RemovalProcess;
			}
		}

		else
		{

			Remover.close();
			Editor.close();
			remove("temporary.txt");

			system("CLS");
			cout << "=========== Security Menu ===========" << endl << endl;
		}
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

string securityencoder(string user) //auser contain even number codes
{
	string auser;
	int x;

	char userc[50];

	strncpy_s(userc, user.c_str(), sizeof(userc));
	userc[sizeof(userc) - 1] = 0;

	for (int i = 0; userc[i] != '\0'; i++) 
	{
		x = userc[i] * 2 + 50;
		auser += to_string(x);
	}
	
	return auser;
}

string securitypass(string user)
{
	string auser, y;
	string apass;
	ifstream Finder;

	Finder.open("Security_Primer.txt");

	if (!Finder)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened.\n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		system("pause");
		Finder.close();
		return "0";
	}
	else
	{
		auser = securityencoder(user);

		while (y != auser && !Finder.eof())
		{
			Finder >> y;

			if (Finder.fail())
			{
				cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.";
				break;
			}
		}

		if (y == auser)
		{
			int h;

			while(Finder.peek() != '\n' && Finder.peek() != '\r' && !Finder.eof())
			{
				Finder >> h;
				apass += passdecoder(h);
			}

			return apass;
		}
		else
		{
			Finder.close();
			return "00";
		}
	}
}

int passencoder(char subpass) 
{
	int h;
	h = subpass * 4 + 359;
	return h;
}

char passdecoder(int h) //code contains odd number codes
{
	char apass;
	apass = (h - 359) / 4;
	return apass;
}