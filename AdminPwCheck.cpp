#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string user, pw;
	ifstream logCheck("admin.txt", ios::in);

	for (;;)
	{
		cout << "Jepni admin username: "; getline(cin, user);
		cout << "Jepni passwordin: "; getline(cin, pw);
		string checkUser = user;
		string checkPw = pw;
		while (!logCheck.eof())
		{
			logCheck >> user >> pw;
			if (user == checkUser&&pw == checkPw)
			{
				cout << "Sukses!\n";
				goto dil;
			}

		}
		logCheck.clear(); // reset eof for next input
		logCheck.seekg(0); // reposition to beginning of file
	}
	dil:
	system("pause");
	return 0;

}