#include<iostream>
#include<Windows.h>
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
			cout << "���󣬷���ʱ�����" << endl;
			break;
		}
	case's':
		cout << endl;
		if (setting.vocal == 'l')
			cout << "������" << setting.time << endl;
		else if (setting.vocal == 'm')
			cout << "������" << setting.time << endl;
		else
			cout << "������" << setting.time << endl;
		break;
	case'?':
		cout << "������" << endl << "1.���롰1������2������3������4������5������6������7���ֱ����do������re������mi������fa������so������la������si��" << endl << "2.��ʼĬ�������������롰h������m������l���ֱ�תΪ�ߡ��С�������" << endl << "3.���� �� + �� �� �� - �����߳����̷���ʱ��" << endl << "4.���롰e������" << endl << "5.���롰s����ȡ��ǰ����" << endl << "6.���롰������ȡ����" << endl << "7.���롰0���˳�" << endl;
		break;
	default:
		cout << "��Ч";
		break;
	}

}
int main()
{
	
	cout << "���̸���" << endl << "����������" << endl << "�ο����ϣ�" << endl << "v1t1p9hvbd.C++�з�������Beep���" << endl << "ziwulan.����C++������" << endl;
	for (;;)
	{
		cout << "��ѡ��ģʽ�����롰a�����뵯��ģʽ�����롰b����������/����ģʽ,���롰0���˳�" << endl;
		char choice;
		cin >> choice;
		if (choice == 'a')
		{
			cout << "������" << endl << "1.���롰1������2������3������4������5������6������7���ֱ����do������re������mi������fa������so������la������si��" << endl << "2.��ʼĬ�������������롰h������m������l���ֱ�תΪ�ߡ��С�������" << endl << "3.���� �� + �� �� �� - �����߳����̷���ʱ��" << endl << "4.���롰e������" << endl << "5.���롰s����ȡ��ǰ����" << endl << "6.���롰?��(Ӣ���ʺ�)��ȡ����" << endl << "7.���롰0���˳�" << endl;
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
				cout<< "���롰w����д�����롰r����ȡ�����ţ����롰0���˳���ע�⣺��ȡ����ʱ�����ո��0��Ϊ��ֹ��" << endl;
				char cho2;
				cin >> cho2;
				char data[10000];
				if (cho2 == 'w')
				{
					ofstream outfile;
					outfile.open("����.txt");

					cout << "�����Ա༭����" << endl;
					cin.getline(data, sizeof(data));
					outfile << data << endl;
					outfile.close();
				}
				else if (cho2 == 'r')
				{
					ifstream infile;
					infile.open("����.txt");

					cout << "��ȡ���ף�" << endl;
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