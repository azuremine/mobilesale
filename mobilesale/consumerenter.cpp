/****************************
*consumer.cpp
****************************/


#include "stdafx.h"
#include "salesystem.h"


string Consumer::get_consid()					//��ȡ�ͻ��˺�
{
	return consid;
}
string Consumer::get_conspasswd()				//��ȡ�ͻ�����
{
	return conspasswd;
}

int Salesys::load_consumer()			//����ͻ���Ϣ
{
	ifstream infile("consumer.txt", ios::in);	//�����뷽ʽ���ļ�
	if (!infile)
	{
		system("cls");
		cerr << "��ȡ�����޿ͻ���Ϣ��" << endl;
		return 1;
	}
	int i;
	string consid, conspasswd, consname, consphone;
	infile >> consnum;
	for (i = 0; i<consnum; i++)					//ȫ������
	{
		infile >> consid;
		infile >> conspasswd;
		infile >> consname;
		infile >> consphone;

		Consumer *cons = new Consumer(consid, conspasswd, consname, consphone);	//ÿ����һ��i����һ���ڴ�
		conscount[i] = cons;						//��ֵ�׵�ַ
	}
	infile.close();
	cout << "��ȡ�ͻ�����������" << endl;
	return 0;
}

void Salesys::enter_consumer()			//�ͻ���¼
{
	string consid;
	cout << "������ͻ��˺ţ�";
	cin >> consid;
	int flag = 1;
	int i = 0;							//__page_break__
	while ((i<consnum) && (flag == 1))			//ѭ������
	{
		if (consid.compare(conscount[i]->get_consid()) == 0)	//�ж��˺�
			flag = 0;
		else
			i++;
	}
	if (flag == 1)
	{
		cout << "���˺Ų�����!" << endl;
		getch();
		return;								//����
	}
	cout << "������ͻ����룺";
	string conspasswd;
	cin >> conspasswd;
	if (conspasswd != conscount[i]->get_conspasswd())	//�ж�����
	{
		cout<<"�����������"<<endl;
		getch();
		return;								//����
	}
	int n;
	do
	{
		system("cls");
		cout << "**********************************" << endl;
		cout << "1����ѯ�ֻ���Ϣ" << endl << endl;
		cout << "2������" << endl;
		cout << "0��������һ���˵�" << endl;
		cout << "**********************************" << endl;

		cout << "�����������ţ�";
		cin >> n;
		switch (n)
		{
		case 1:
			mobdisplay() ;		//��ǰ�ֻ���Ϣ����
			system("cls");
			break;
		case 2:
			system("cls");
			addsalelist() ;		//������۵���Ϣ
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