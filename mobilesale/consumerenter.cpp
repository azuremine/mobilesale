/****************************
*consumer.cpp
****************************/


#include "stdafx.h"
#include "salesystem.h"


string Consumer::get_consid()					//获取客户账号
{
	return consid;
}
string Consumer::get_conspasswd()				//获取客户密码
{
	return conspasswd;
}

int Salesys::load_consumer()			//读入客户信息
{
	ifstream infile("consumer.txt", ios::in);	//以输入方式打开文件
	if (!infile)
	{
		system("cls");
		cerr << "读取错误，无客户信息！" << endl;
		return 1;
	}
	int i;
	string consid, conspasswd, consname, consphone;
	infile >> consnum;
	for (i = 0; i<consnum; i++)					//全部读入
	{
		infile >> consid;
		infile >> conspasswd;
		infile >> consname;
		infile >> consphone;

		Consumer *cons = new Consumer(consid, conspasswd, consname, consphone);	//每读入一个i开辟一段内存
		conscount[i] = cons;						//赋值首地址
	}
	infile.close();
	cout << "读取客户资料正常！" << endl;
	return 0;
}

void Salesys::enter_consumer()			//客户登录
{
	string consid;
	cout << "请输入客户账号：";
	cin >> consid;
	int flag = 1;
	int i = 0;							//__page_break__
	while ((i<consnum) && (flag == 1))			//循环查找
	{
		if (consid.compare(conscount[i]->get_consid()) == 0)	//判断账号
			flag = 0;
		else
			i++;
	}
	if (flag == 1)
	{
		cout << "该账号不存在!" << endl;
		getch();
		return;								//返回
	}
	cout << "请输入客户密码：";
	string conspasswd;
	cin >> conspasswd;
	if (conspasswd != conscount[i]->get_conspasswd())	//判断密码
	{
		cout<<"输入密码错误！"<<endl;
		getch();
		return;								//返回
	}
	int n;
	do
	{
		system("cls");
		cout << "**********************************" << endl;
		cout << "1、查询手机信息" << endl << endl;
		cout << "2、购买" << endl;
		cout << "0、返回上一级菜单" << endl;
		cout << "**********************************" << endl;

		cout << "请输入操作编号：";
		cin >> n;
		switch (n)
		{
		case 1:
			mobdisplay() ;		//当前手机信息总览
			system("cls");
			break;
		case 2:
			system("cls");
			addsalelist() ;		//添加销售单信息
			break;
		case 0:
			system("cls");
			return;
		default:
			cout<<"输入错误！请重新输入！"<<endl;
			break;
		}
	} while (1);
}