#ifndef ADMINUSER_H
#define ADMINUSER_H
#include <string>
#include <iostream>
#include "userDB.h"
using namespace std;
enum options
{
	BILANC0 = 1,
	kanMinus,
	kanPlus,
	ALL,
	addUser,
	kerkoEmer,
	kerkoMbiemer,
	kerkoDyjat,
	ADDADMIN,
	EnD
};
int admReq();
void admin(string admin)
{
	database user;
	cout << "Welcome " << admin << endl;
	int opsioni = NULL;
	while (opsioni!=EnD)
	{
		opsioni = admReq();
		switch (opsioni)
		{
		case BILANC0:
		{
			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.sum[i] == 0)
					cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case kanMinus:
		{

			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.sum[i] < 0)
					cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case kanPlus:
		{

			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.sum[i] >0)
					cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case ALL:
		{

			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case addUser:
		{
			user.add();
			break;
		}
		case kerkoEmer:
		{
			string emri;
			cout << "Jepni emrin ne baze te se cilit deshironi te kerkoni: "; cin.ignore();
			cin >> emri;
			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.emri[i]==emri)
				cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case kerkoMbiemer:
		{
			string mbiemer;
			cout << "Jepni mbiemrin ne baze te se cilit deshironi te kerkoni: "; cin.ignore();
			cin >> mbiemer;
			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.mbiemri[i] == mbiemer)
					cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case kerkoDyjat:
		{
			string emri, mbiemer;
			cout << "Jepni emrin ne baze te se cilit deshironi te kerkoni : "; cin.ignore();
			cin >> emri;
			cout << "Jepni mbiemrin: ";
			cin >> mbiemer;
			cout << "Emri  Mbiemri  Bilanci" << endl
				<< "========================" << endl;
			for (int i = 0; i < user.totalUsera; i++)
			{
				if (user.emri[i] == emri&&user.mbiemri[i]==mbiemer)
					cout << user.emri[i] << " " << user.mbiemri[i] << " " << user.sum[i] << endl;
			}
			cout << "========================" << endl << endl;
			break;
		}
		case ADDADMIN:
		{
			user.AddAdmin();
			break;
		}

		}
	}
}
int admReq()
{
	int k;
	cout << "Shtyp numrin: " << endl
		<< " 1- Per te pare te gjithe klientet me bilance 0EUR" << endl
		<< " 2- Per te pare te gjithe klientet me bilance negative" << endl
		<< " 3- Per te pare te gjithe klientet me bilance pozitive" << endl
		<< " 4- Per te pare te gjithe klientet" << endl
		<< " 5- Per te shtuar nje perdorues" << endl
		<< " 6- Per te kerkuar klient ne baze te emrit" << endl
		<< " 7- Per te kerkuar klient ne baze te mbiemrit" << endl
		<< " 8- Per te kerkuar klient ne baze te emrit dhe mbiemrit" << endl
		<< " 9- Per te shtuar nje administrator" << endl
		<< " 10- Per te perfunduar" << endl;
	cout << "\n? ";
	cin >> k;
	return k;
}
#endif