/**************************
*   user.cpp
**************************/
#include "stdafx.h"
#include "salesystem.h"


void Salesys::enter_user()				//�ο����
{
	int n;
	do
	{
		cout << "**********************************" << endl;
		cout << "1����ѯ�ֻ���Ϣ" << endl << endl;
		cout << "0��������һ���˵�" << endl;
		cout << "**********************************" << endl;

		cout << "�����������ţ�";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			mobdisplay() ;		//��ǰ�ֻ���Ϣ����
			break;
		case 0:
			system("cls");
			return;
		default:
			cout<<"����������������룡"<<endl;
			break;
		}
	} while (1);
}