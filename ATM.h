#ifndef ATM_H
#define ATM_H
#define NOMINMAX
#include <iostream>
#include "usernameCheck.h"
#include "user.h"
using namespace std;
void start()
{
	string emri;
	bool textSwitch = false;
	int gabim = 0, gabimeTeLejuara=2;
	int k;
	cout << "Mirsevini ne ATM v0.1" << endl; 
	cout << "Shtypni 1 per te vazhduar! ";hyrja: cin >> k;
	if (gabim == 3) //mbyllet nrast qe shtypet 3her gabim
		exit(0);
	if (!cin) // Pjesa ku kqyret se a ka gabim(pasiqe nrast qe jep shkronja jep gabim)
	{
		cin.clear(); // reset failbit 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// injoron dej n'pakufi(!) karakteret qe i shtypum na
		gabim++;
		goto hyrja;
	} 
	if (k == 1)//inicializohet useri i thjesht
	{
		normalUser();
	}
	else if (k == 0) // inicializohet queri per admin user
		 checkforAdmin();//usernameCheck.h
	else if (!textSwitch) //Nrast gabim (k!=1||0) heren e par paraqitet kjo
	{
		cout << "\nJu lutem shtypni 1, nese deshtoni 3her, programi mbyllet!  :  ";
		textSwitch = true;
		gabim++;
		goto hyrja;
	}
	else //pastaj ky tekst(mu dok ma estetike)
	{
		cout << "Shtyp 1(Kan mbetur edhe "<<gabimeTeLejuara<<" tentim/e)"<<" : ";
		gabimeTeLejuara--;
		gabim++;
		goto hyrja;
	}
	 //cout << "\nMirsevini " << emri<< " !!"  << endl;

}
#endif