#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "userDB.h"
using namespace std;

enum Options
{
	BILANCI=1,
	TERHIQ,
	DEPOZITO,
	END
};

int request();

void normalUser()
{
	int gjirollogaria, pinCode;
	database ruajtja;
	string vi = "=============================";	
	cout << vi << endl;
	cout << "Miresevini!" << endl;
	cout << "Jepni Nr e xhirollogaris: "; cin >> gjirollogaria;
	cout << "Jepni PIN kodin: "; cin >> pinCode;
	for (int i = 0; i < ruajtja.totalUsera; i++)
	{
		if (gjirollogaria == ruajtja.getAcc(i) && pinCode == ruajtja.getPin(i))
		{
			cout << "Miresevini " << ruajtja.emri[i] << endl;
			int opsioni = NULL;
			while (opsioni!=END)
			{
				opsioni = request();
				switch (opsioni)
				{
				case BILANCI:
				{
					cout << "Ne xhirollogarin tuaj keni " << ruajtja.sum[i] << "EUR ";
					cout << "\nOperacioni perfundoi me sukses";
					break;
				}
				case TERHIQ:
				{
					char kujdes;
					int terhiq;
					cout << "Shkruani numrin e te hollave qe deshironi ti terhiqni: ";
					cin >> terhiq;
					if (terhiq > ruajtja.sum[i])
					{
						cout << "Kujdes, deshironi te terhiqni me shum sesa qe keni te depozituara\nDeshironi te vazhdoni?(p/j): ";
						cin >> kujdes;
						if (kujdes == 'p')
						{
							ruajtja.sum[i] -= terhiq;
							cout << "Keni nje bilanc negativ prej " << ruajtja.sum[i] << endl;
							cout << "\nOperacioni perfundoi me sukses";
						}
						else if (kujdes == 'j')
							cout << "Kerkesa u anulua." << endl;
					}
					else
					{
						ruajtja.sum[i] -= terhiq;
						cout << "\nOperacioni perfundoi me sukses";
					}
						
					break;
				}
				case DEPOZITO:
				{
					int depozito;
					cout << "Shkruani numrin e te hollave qe deshironi ti depozitoni: ";
					cin >> depozito;
					if (depozito <= 0)
					{
						cout << "Keni japur vler jo valide" << endl;
					}
					else
					{
						ruajtja.sum[i] += depozito;
						cout << "\nOperacioni perfundoi me sukses";
					}
					break;
				}
				}
			}
			break;
		}		
	}
	ruajtja.SAVE();
}

int request()
{
	int k;
	cout << "\nShtyp numrin: " << endl
		<< " 1- Per te pare bilancin" << endl
		<< " 2- Per te terhekur para " << endl
		<< " 3- Per te depozituar para" << endl
		<< " 4- Per te mbyllur programin" << endl;
	 cout << "\n? ";
	 cin >> k;
	return k;
}
#endif