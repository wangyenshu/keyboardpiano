#include<iostream>
#include<windows.h>
#include<errno.h>
#include<conio.h>
#include<stdio.h>
#include <fstream>
using namespace std;
struct set
{
	char vocal='m';
	int time=300;
};
int t = 300;
int doo = 523;
int re = 578;
int mi = 659;
int fa = 698;
int so = 784;
int la = 880;
int si = 988;
set setting;
void play(char o)
{
	switch (o)
	{
	
	case'1':
		Beep(doo, t);
		break;
	case'2':
		Beep(re, t);
		break;
	case'3':
		Beep(mi, t);
		break;
	case'4':
		Beep(fa, t);
		break;
	case'5':
		Beep(so, t);
		break;
	case'6':
		Beep(la, t);
		break;
	case'7':
		Beep(si, t);
		break;
	case'e':
		cout << endl;
		break;
	case'm':
		doo = 523;
		re = 578;
		mi = 659;
		fa = 698;
		so = 784;
		la = 880;
		si = 988;
		setting.vocal = 'm';
		break;
	case'l':
		doo = 262;
		re = 294;
		mi = 330;
		fa = 349;
		so = 392;
		la = 440;
		si = 494;
		setting.vocal = 'l';
		break;
	case'h':
		doo = 1046;
		re = 1175;
		mi = 1318;
		fa = 1480;
		so = 1568;
		la = 1760;
		si = 1976;
		setting.vocal = 'h';
		break;
	case'+':
		t += 50;
		setting.time = setting.time + 50;
		break;
	case'-':
		if (t > 50)
		{
			t -= 50;
			setting.time = setting.time - 50;
			break;
		}
		else
		{
			cout << "Error, beeping time is too short" << endl;
			break;
		}
	case's':
		cout << endl;
		if (setting.vocal == 'l')
			cout << "low voice mode" << setting.time << endl;
		else if (setting.vocal == 'm')
			cout << "medium voice mode" << setting.time << endl;
		else
			cout << "high voice mode" << setting.time << endl;
		break;
	case'?':
		cout << "help:" << endl << "1.Type \"1\",\"2\",\"3\",\"4\",\"5\",\"6\",\"7\" to produce \"do\",\"re\",\"mi\",\"fa\",\"so\",\"la\",\"si\"." << endl << "2.This software is set to medium voice mode by default. Type \"h\",\"m\",\"l\" to convert it into high voice or medium voice or low voice mode." << endl << "3.Type \"+\" , \"-\" to make it beep longer or shorter." << endl << "4.Type \"e\" to make line breaks." << endl << "5.Type \"s\" to print current settings." << endl << "6.Type \"?\" to print help." << endl << "7.Type \"0\" to quit." << endl;
		break;
	default:
		cout << "invalid";
		break;
	}

}
int main()
{
	
	cout << "keyboard piano" << endl << "by Yanshu Wang as a homework for the Freshman year Programming course" << endl << "reference:" << endl << "https://www.cnblogs.com/zhcs/p/6832228.html" << endl << "A Zhihu article that can no longer be accessed without logging in" << endl;
	cout << "Please select the mode, type \"a\" to enter the live playing mode, type \"b\" to enter the compose/play mode, type \"0\" to exit" << endl;

	for (;;)
	{
		char choice;
		cin >> choice;
		if (choice == 'a')
		{
			cout << "help:" << endl << "1.Type \"1\",\"2\",\"3\",\"4\",\"5\",\"6\",\"7\" to produce \"do\",\"re\",\"mi\",\"fa\",\"so\",\"la\",\"si\"." << endl << "2.This software is set to medium voice mode by default. Type \"h\",\"m\",\"l\" to convert it into high voice or medium voice or low voice mode." << endl << "3.Type \"+\" , \"-\" to make it beep longer or shorter." << endl << "4.Type \"e\" to make line breaks." << endl << "5.Type \"s\" to print current settings." << endl << "6.Type \"?\" to print help." << endl << "7.Type \"0\" to quit." << endl;
			for (;;)
			{
				char o = _getche();
				if (o != '0')
					play(o);
				else
					goto P;
			}
		}
		else if (choice == 'b')
		{
			for (;;)
			{
				cout<< "Type \"w\" to write, type \"r\" to read pianoscore.txt and play it, type \"0\" to exit. Note: spaces or 0 encountered when reading pianoscore.txt are regarded as terminators." << endl;
				char cho2;
				cin >> cho2;
				char data[10000];
				if (cho2 == 'w')
				{
					ofstream outfile;
					outfile.open("pianoscore.txt");

					cout << "type to edit pianoscore.txt" << endl;
					cin.getline(data, sizeof(data));
					outfile << data << endl;
					outfile.close();
				}
				else if (cho2 == 'r')
				{
					ifstream infile;
					infile.open("pianoscore.txt");

					cout << "reading pianoscore.txt:" << endl;
					infile >> data;
					cout << data << endl;
					for (int u = 0; u < sizeof(data) && u != 0; u++)
					{
						play(data[u]);
					}
					infile.close();
				}

				else if (cho2 == '0')
					goto P;
			}
		}
		else if (choice == '0')
			goto P;
	}
	P:
return 0;
}