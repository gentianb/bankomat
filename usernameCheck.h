#ifndef USERNAMECHECK_H
#define USERNAMECHECK_H
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "adminUser.h"
using namespace std;
void checkforAdmin()
{
	cin.ignore();
	string user, pw;
	ifstream logCheck("admin.dat", ios::in);
	if (!logCheck)
	{
		cerr << "\nKa ndodhur nje gabim ne qasjen e te dhenave, programi do te mbyllet ne: \n";
		for (int i = 5; i>0; i--)
		{
			cout << i << endl;
			Sleep(1000);
		}
		exit(1);
	}
	for (int i = 1;i<=3;i++)
	{
		cout << "\nJepni admin username: "; getline(cin, user);
		cout << "Jepni passwordin: "; getline(cin, pw);
		string checkUser = user;
		string checkPw = pw;
		while (!logCheck.eof())
		{
			logCheck >> user >> pw;
			if (user == checkUser&&pw == checkPw)
			{
				logCheck.close();
				admin(user);// inicializohet ui per admin
				goto out;
			}

		}
		if (i == 1)
			cout << "Mbas 3 tentimeve programi do te mbyllet!\n";
		if (i == 3)
			exit(0);
		logCheck.clear(); // reset eof for next input
		logCheck.seekg(0); // reposition to beginning of file
	}
out:;
}
#endif