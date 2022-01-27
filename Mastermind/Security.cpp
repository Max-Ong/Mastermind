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
string pinencoder(string pass);
void changePassword(string user);
void nameListGone(string user);
void nameListAdd(string user);

int main()
{
	int x;
	string choice, user;


	ifstream Secure("Security_Primer.txt"), nameList("nameList.txt");
	ofstream Tester("temp.txt");
	if (!Tester)
	{
		cout << "(!) Error: (temp.txt) cannot be created." << endl;
		system("pause");
		exit(0);
	}
	else if (!Secure)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		remove("temp.txt");
		system("pause");
		exit(0);
	}
	else if (!nameList)
	{
		cout << "(!) Error 101: (nameList.txt) cannot be opened. \n    Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		remove("temp.txt");
		system("pause");
		exit(0);
	}

	Secure.close();
	nameList.close();
	Tester.close();
	remove("temp.txt");

	cout << "============ Security Menu ============" << endl << endl;

Choices:
	cout << "1. Sign In." << endl
		<< "2. Create account." << endl
		<< "3. Remove account." << endl
		<< "4. Change password." << endl << endl
		<< "Please Enter your choice to continue: ";
	cin >> choice;

	system("CLS");
	cout << "============ Security Menu ============" << endl << endl;

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
			cout << "============ Security Menu ============" << endl << endl;
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
			<< "Note: Username shounld not include spaces or system shall take the first word entered as username. \n(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cin >> user;

		if (user == "0")
		{
			system("CLS");
			cout << "============ Security Menu ============" << endl << endl;
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
			cout << "============ Security Menu ============" << endl << endl;
			goto Choices;
		}

		else
		{
			removeAccount(user);
			x = 2;
		}
	}

	else if (choice == "4")
	{
		cout << "Please enter the username and password for the account you wish to change the password of." << endl
			<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cin >> user;

		if (user == "0")
		{
			system("CLS");
			cout << "============ Security Menu ============" << endl << endl;
			goto Choices;
		}

		else
		{
			changePassword(user);
			x = 2;
		}
	}
	else
	{
		cout << "(!) Invalid choice entered, Please enter a valid choice." << endl << endl;
		goto Choices;
	}

	system("CLS");
	cout << "============ Security Menu ============" << endl << endl;

	if (x == 0)
	{
		cout << "Access Granted. Welcome " << user << "." << endl;
		Sleep(4000);
		system("CLS");
		goto Programs;
	}

	else if (x == 1)
	{
		cout << "(!) Access Denied. Please try again." << endl << endl;
		goto Protocall;
	}

	else if (x == 2)
	{
		goto Choices;
	}

	else if (x == 3)
	{
		cout << "(!) This username has already been taken. Please use a different username." << endl << endl;
		goto Creative;
	}

Programs:
	return 0;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int createAccount(string user)
{
	ofstream Worker("temp.txt", ofstream::app);
	ifstream Secure("Security_Primer.txt"), Readout("Security_Primer.txt");
	string x, apass, pass, auser, y, cpass;

	if (!Worker)
	{
		cout << "(!) Error: (temp.txt) cannot be created." << endl;
		system("pause");
		exit(0);
	}

	else if (!Secure)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		remove("temp.txt");
		system("pause");
		exit(0);
	}

	else
	{
		auser = securityencoder(user);

		while (y != auser && !Secure.eof())
		{
			Secure >> y >> x;

			if (Secure.fail())
			{
				cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
				remove("temp.txt");
				system("pause");
				exit(0);
			}
		}
		if (y != auser)
		{
		Password:
			cout << "Password: ";

			char ch;
			ch = _getch();

			system("CLS");
			cout << "============ Security Menu ============" << endl << endl;
			cout << "Please enter the username and password for your new account." << endl
				<< "Note: Username shounld not include spaces or system shall take the first word entered as username. \n(Enter 0 as Username or Password to return to main menu.)" << endl << endl
				<< "Username: ";
			cout << user << endl;
			cout << "Password: ";

		FirstPass:
			while (ch != 13 && ch != 8)
			{
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}

			if (ch == 8)
			{
				int g = pass.size();
				if (g != 0)
				{
					system("CLS");
					cout << "============ Security Menu ============" << endl << endl;
					pass.resize(g - 1);

					cout << "Please enter the username and password for your new account." << endl
						<< "Note: Username shounld not include spaces or system shall take the first word entered as username. \n(Enter 0 as Username or Password to return to main menu.)" << endl << endl
						<< "Username: ";
					cout << user << endl << "Password: ";
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

			else if (ch == 13 && pass == "")
			{
				ch = _getch();
				goto FirstPass;
			}

			else
			{
				cout << endl;
			}

			if (pass == "0")
			{
			Leave:
				Secure.close();
				Worker.close();
				Readout.close();
				remove("temp.txt");

				return 2;
			}

			else
			{
				cout << "Confirm Password: ";

				char cf = _getch();

			SecondPass:
				while (cf != 13 && cf != 8)
				{
					apass.push_back(cf);
					cout << '*';
					cf = _getch();
				}

				if (cf == 8)
				{
					int m = apass.size();
					if (m != 0)
					{
						system("CLS");
						cout << "============ Security Menu ============" << endl << endl;

						apass.resize(m - 1);

						cout << "Please enter the username and password for your new account." << endl
							<< "Note: Username shounld not include spaces or system shall take the first word entered as username. \n(Enter 0 as Username or Password to return to main menu.)" << endl << endl
							<< "Username: ";
						cout << user << endl;
						cout << "Password: ";
						int g = pass.size();

						for (int i = 0; i < g; i++)
						{
							cout << '*';
						}
						cout << endl << "Confirm Password: ";

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

				else if (cf == 13 && apass == "")
				{
					cf = _getch();
					goto SecondPass;
				}

				else
				{
					cout << endl;
				}

				system("CLS");
				cout << "============ Security Menu ============" << endl << endl;

				if (apass == "0")
				{
					goto Leave;
				}

				else if (pass == apass)
				{
					cpass = pinencoder(pass);

					string line;

					while (getline(Readout, line))
					{
						if (Readout.fail())
						{
							cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
							remove("temp.txt");
							system("pause");
							exit(0);
						}

						else if (line.substr(0, auser.size()) != auser)
						{
							Worker << line << endl;
						}
					}

					Worker << auser << " " << cpass;

					Secure.close();
					Worker.close();
					Readout.close();
					remove("Security_Primer.txt");
					rename("temp.txt", "Security_Primer.txt");

					nameListAdd(user);

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
					pass = "";
					apass = "";
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
	string auser, gone;

	ifstream Remover("Security_Primer.txt");
	ofstream Editor("temporary.txt");

	if (!Editor)
	{
		cout << "(!) Error: (temporary.txt) cannot be created." << endl;
		system("pause");
		exit(0);
	}

	else if (!Remover)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		remove("temporary.txt");
		system("pause");
		exit(0);
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
				if (Remover.fail())
				{
					cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
					remove("temporary.txt");
					system("pause");
					exit(0);
				}
				else if (gone.substr(0, auser.size()) != auser)
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

			nameListGone(user);

			cout << "Account (user:  " << user << ") has been removed." << endl << endl;

			system("pause");
		}

		else if (r == 1)
		{
			cout << "Please enter the username and password for the account that you wish to remove." << endl
				<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
				<< "Username: ";
			cin >> user;

			if (user == "0")
			{
				goto Exit;
			}

			else
			{
				goto RemovalProcess;
			}
		}

		else
		{
		Exit:
			Remover.close();
			Editor.close();
			remove("temporary.txt");
		}
	}
}

int accessAccount(string user)
{
	ifstream Secure("Security_Primer.txt");
	string apass, pass, cpass;

	if (!Secure)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		system("pause");
		exit(0);
	}

	else
	{
		Secure.close();
		cout << "Password: ";

		char ch;
		ch = _getch();

		system("CLS");
		cout << "============ Security Menu ============" << endl << endl;
		cout << "Please enter the username and password for the account you wish to access." << endl
			<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
			<< "Username: ";
		cout << user << endl;
		cout << "Password: ";

	FirstPass:
		while (ch != 13 && ch != 8)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}

		if (ch == 8)
		{
			int g = pass.size();
			if (g != 0)
			{
				system("CLS");
				cout << "============ Security Menu ============" << endl << endl;

				pass.resize(g - 1);

				cout << "Please enter the username and password for the account you wish to access." << endl
					<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
					<< "Username: ";
				cout << user << endl << "Password: ";
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

		else
		{
			cout << endl;
		}

		system("CLS");
		cout << "============ Security Menu ============" << endl << endl;

		cpass = pinencoder(pass);

		apass = securitypass(user);

		if (pass == "0")
		{
			return 2;
		}

		else if (apass == cpass)
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

void changePassword(string user)
{
	int r;
	string auser, gone, pass;

	ifstream Remover("Security_Primer.txt");
	ofstream Editor("temporary.txt", ofstream::app);

	if (!Editor)
	{
		cout << "(!) Error: (temporary.txt) cannot be created." << endl;
		system("pause");
		exit(0);
	}

	else if (!Remover)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened. \n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		remove("temporary.txt");
		system("pause");
		exit(0);
	}

	else
	{
	ChangeProcess:
		r = accessAccount(user);

		if (r == 0)
		{
			system("CLS");
			cout << "============ Security Menu ============" << endl << endl;
			cout << "User: " << user << "\n\nPlease Enter your new password below.\n\nNew password:";

			char ch;
			ch = _getch();

		FirstPass:
			while (ch != 13 && ch != 8)
			{
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}

			if (ch == 8)
			{
				int g = pass.size();
				if (g != 0)
				{
					system("CLS");
					cout << "============ Security Menu ============" << endl << endl;

					pass.resize(g - 1);

					cout << "User: " << user << "\n\nPlease Enter your new password below.\n\nNew password:";

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

			else
			{
				cout << endl;
			}
			if (pass == "0")
			{
				goto Exit;
			}
			string cpass = pinencoder(pass);

			system("CLS");
			cout << "============ Security Menu ============" << endl << endl;

			auser = securityencoder(user);

			string filer;

			while (getline(Remover, gone))
			{
				if (Remover.fail())
				{
					cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
					remove("temporary.txt");
					system("pause");
					exit(0);
				}

				else if (gone.substr(0, auser.size()) != auser)
				{
					filer += gone + '\n';
				}
			}

			Editor << filer;
			Editor << auser << " " << cpass;

			Remover.close();
			Editor.close();
			remove("Security_Primer.txt");
			rename("temporary.txt", "Security_Primer.txt");

			cout << "The password for the account (user:  " << user << ") has been changed." << endl << endl;

			system("pause");
		}

		else if (r == 1)
		{
			cout << "Please enter the username and password for the account you wish to change the password of." << endl
				<< "(Enter 0 as Username or Password to return to main menu.)" << endl << endl
				<< "Username: ";
			cin >> user;

			if (user == "0")
			{
				goto Exit;
			}

			else
			{
				goto ChangeProcess;
			}
		}

		else
		{
		Exit:
			Remover.close();
			Editor.close();
			remove("temporary.txt");
		}
	}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

string securitypass(string user)
{
	string auser, y;
	string apass;
	ifstream Finder("Security_Primer.txt");

	if (!Finder)
	{
		cout << "(!) Error 101: (Security_Primer.txt) cannot be opened.\n    Please ensure (Security_Primer.txt) is downloaded and available to this project before continuing." << endl;
		system("pause");
		exit(0);
	}
	else
	{
		auser = securityencoder(user);

		while (y != auser && !Finder.eof())
		{
			Finder >> y >> apass;

			if (Finder.fail())
			{
				cout << "(!) Error 101: (Security_Primer.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.";
				system("pause");
				exit(0);
			}
		}

		if (y == auser)
		{
			return apass;
		}
		else
		{
			return "0";
		}
	}
}

void nameListAdd(string user)
{
	ofstream WorkerA("temp2.txt", ofstream::app);
	ifstream ReadoutA("nameList.txt");

	if (!WorkerA)
	{
	cout << "(!) Error: (temp2.txt) cannot be created." << endl;
	system("pause");
	exit(0);
	}

	else if (!ReadoutA)
	{
		cout << "(!) Error 101: (nameList.txt) cannot be opened. \n    Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		remove("temp2.txt");
		system("pause");
		exit(0);
	}

	else 
	{
		string line;

		WorkerA << user;

		while (getline(ReadoutA, line))
		{
			if (ReadoutA.fail())
			{
				cout << "(!) Error 101: (nameList.txt) contains invalid data. Please close and reopen this project after the issue has been resolved.\n";
				remove("temp2.txt");
				system("pause");
				exit(0);
			}

			else if (line.substr(0, user.size()) != user)
			{
				WorkerA << endl << line;
			}
		}

		ReadoutA.close();
		WorkerA.close();
		remove("nameList.txt");
		rename("temp2.txt", "nameList.txt");
	}
}

void nameListGone(string user) 
{
	ifstream RemoverA("nameList.txt");
	ofstream EditorA("temporary2.txt");

	if (!EditorA)
	{
	cout << "(!) Error: (temporary2.txt) cannot be created." << endl;
	system("pause");
	exit(0);
	}

	else if (!RemoverA)
	{
		cout << "(!) Error 101: (nameList.txt) cannot be opened. \n    Please ensure (nameList.txt) is downloaded and available to this project before continuing." << endl;
		remove("temporary2.txt");
		system("pause");
		exit(0);
	}

	else 
	{
		string filer, gone;

		while (getline(RemoverA, gone))
		{
			if (RemoverA.fail())
			{
				cout << "(!) Error 101: (nameList.txt) contains invalid codes. Please close and reopen this project after the issue has been resolved.\n";
				remove("temporary2.txt");
				system("pause");
				exit(0);
			}
			else if (gone.substr(0, user.size()) != user)
			{
				filer += gone + '\n';
			}
		}

		int g = filer.size();
		filer.resize(g - 1);
		EditorA << filer;

		RemoverA.close();
		EditorA.close();
		remove("nameList.txt");
		rename("temporary2.txt", "nameList.txt");
	}
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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

string pinencoder(string pass)
{
	string cpass;
	int x, h;
	char spass[40];
	char subpass;

	strncpy_s(spass, pass.c_str(), sizeof(spass));
	spass[sizeof(spass) - 1] = 0;

	for (x = 0; spass[x] != '\0'; x++)
	{
		subpass = spass[x];
		h = passencoder(subpass);
		cpass += to_string(h);
	}
	return cpass;
}

int passencoder(char subpass)
{
	int h;
	h = subpass * 4 + 359;
	return h;
}