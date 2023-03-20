#include <iostream>
#include<cstdio>
#include<string>
#include <fstream>
using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");

	int deistvie;
	string usingname;
	string password;
	string poisk;
	string vvod;

	cout << "выберите действие:" << endl
		<< "1. регистрация" << endl
		<< "2. вход" << endl
		<< "3. посмотреть данные всех пользователей" << endl
		<< "0. выход из программы" << endl;
	cin >> deistvie;


	ofstream base("registration.txt", ios_base::app);
	ifstream base1("registration.txt", ios::in);

	while (deistvie > 0)
	{
		switch (deistvie)
		{
		case 1:
			cout << "придумайте имя пользователя: ";
			cin >> usingname;
			cout << "придумайте пароль: ";
			cin >> password;


			base << "имя пользователя: " << usingname << "\tпароль: " << password << endl;
			base.close();

			cout << "\vваши данные: " << endl << "имя пользователя: " << usingname << " пароль: " << password << endl;
			usingname.clear();
			password.clear();
			break;
		case 2:
			char buff[100];

			cout << "введите имя пользователя: ";
			cin >> usingname;
			cout << "введите пароль: ";
			cin >> password;

			vvod = "имя пользователя: ";
			vvod += usingname;
			vvod += "\tпароль: ";
			vvod += password;

			while (getline(base1, poisk))
			{
				if (vvod == poisk)
					cout << "добро пожаловать, " << usingname<<endl<<endl;

				if (poisk.empty())
				{
					cout << "неверное имя пользователя или парль";
					break;
				}
			}

			break;
		case 3:
			int usepassword;
			int adminpassword = 1234;
			int i = 0;
			string line;
			cout << "введите пароль администратора: ";
			cin >> usepassword;

			while (i < 3)
			{

				if (usepassword != adminpassword)
				{
					cout << "пароль неверный, попробуйте ещё раз: ";
					cin >> usepassword;
					i++;
				}
				else
				{
					char str;
					while (base1.get(str))
					{
						cout << str;
					}
				}
			}
			break;
		}
	}
	base.close();
	base1.close();
	return 0;
}