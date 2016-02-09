#ifndef USERDB_H
#define USERDB_H
#include <string>
#include <iostream>
using namespace std;
#include<fstream>
#include <Windows.h>
const int u = 50;
class database
{
private:
	int pin[u], accnr[u];
public:
	string emri[u], mbiemri[u];
	double sum[u];
	int getPin(int i);
	int getAcc(int i);
	int totalUsera;
	database()
	{
		int numrues = 0;
		int Accnr, Pin; int i = 0;
		double Sum;
		string Emri, Mbiemri;
		ifstream lexim("bankTest.dat", ios::in);
		if (!lexim)
		{
			cerr << "\nKa ndodhur nje gabim ne qasjen e te dhenave, programi do te mbyllet ne: \n";
			for (int i = 5; i>0; i--)
			{
				cout << i << endl;
				Sleep(1000);
			}
			exit(1);
		}
		while (!lexim.eof())
		{
			lexim >> Accnr >> Pin >> Emri >> Mbiemri >> Sum;
			pin[i] = Pin;
			accnr[i] = Accnr;
			emri[i] = Emri;
			mbiemri[i] = Mbiemri;
			sum[i] = Sum;
			i++;
			numrues++;
		}
		totalUsera = numrues;
		lexim.close();
	}
	void add()
	{
		ofstream shkruaj("bankTest.dat", ios::app);
		int pini, account;
		string emr, mbie;
		double shum;
		cout << "Te jepet nr Xhirollogaris: ";
		cin >> account;
		cout << "Te jepet pin ";
		cin >> pini;
		cin.ignore();
		cout << "Te jepet Emri: ";
		cin >> emr;
		cout << "Te jepet Mbiemri: ";
		cin >> mbie;
		cout << "Te jepet numri i te hollave: ";
		cin >> shum;
		shkruaj << endl<< account << ' ' << pini << ' ' << emr << ' ' << mbie << ' ' << shum;
	}
	void AddAdmin()
	{
		ofstream shkruaj("admin.dat", ios::app);
		string user, pw;
		cin.ignore();
		cout << "Te jepet Username: ";
		cin >> user;
		cout << "Te jepet password: ";
		cin >> pw;
		shkruaj << user << ' ' << pw << endl;
	}
	void SAVE()
	{
		ofstream shkruaj("bankTest.dat", ios::out);
		if (!shkruaj)
		{
			cerr << "Gabim fatal gjat ruajtjes\n";
			Sleep(2000);
			exit(1);
		}
		for (int i = 0; i < totalUsera ; i++)
		{
			shkruaj << accnr[i] << ' ' << pin[i] << ' ' << emri[i] << ' ' << mbiemri[i] << ' ' << sum[i] << endl;
		}
		shkruaj.close();
	}
};
int database::getPin(int i)
{
	return pin[i];
}
int database::getAcc(int i)
{
	return accnr[i];
}
#endif
