/**************************
*   saler.cpp
**************************/
#include "stdafx.h"
#include "salesystem.h"


string Saler::get_salerid()					//获取销售员账号
{
	return salerid;
}
string Saler::get_salerpasswd()				//获取销售员密码
{
	return salerpasswd;
}

int Salesys::load_saler()					//读入销售员信息
{
	ifstream infile("saler.txt", ios::in);	//以输入方式打开文件
	if (!infile)
	{
		system("cls");
		cerr << "读取错误，无销售员信息！" << endl;
		return 1;
	}
	int i;
	string salerid, salerpasswd, salername;
	infile >> salernum;
	for (i = 0; i<salernum; i++)					//全部读入
	{
		infile >> salerid;
		infile >> salerpasswd;
		infile >> salername;

		Saler *sa = new Saler(salerid, salerpasswd, salername);	//每读入一个i开辟一段内存
		salercount[i] = sa;						//赋值首地址
	}
	infile.close();
	cout << "读取销售员资料正常！" << endl;
	return 0;
}
void Salesys::enter_saler()				//销售员登陆
{
	string salerid;
	cout << "请输入销售员账号：";
	cin >> salerid;
	int flag = 1;
	int i = 0;							//__page_break__
	while ((i<salernum) && (flag == 1))			//循环查找
	{
		if (salerid.compare(salercount[i]->get_salerid()) == 0)	//判断账号
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
	cout << "请输入销售员密码：";
	string salerpasswd;
	cin >> salerpasswd;
	if (salerpasswd != salercount[i]->get_salerpasswd())	//判断密码
	{
		cout<<"输入密码错误！";
		getch();
		return;								//返回
	}
	int n;
	do
	{
		cout << "**********************************" << endl;
		cout << "1、增加销售单信息" << endl;
		cout << "2、删除销售单信息" << endl;
		cout << "3、修改销售单信息" << endl;
		cout << "4、查询销售单信息" << endl;
		cout << "5、清空销售单信息" << endl;
		cout << "0、返回上一级菜单" << endl << endl;
		cout << "**********************************" << endl;
		cout << "请输入操作编号：";
		cin >> n;
		switch (n)
		{
		case 1:
			addsalelist() ;			//添加销售单信息
			break;
		case 2:
			delsalelist() ;			//删除销售单信息
			break;
		case 3:
			altersalelist() ;		//修改销售单基本信息
			break;
		case 4:
			system("cls");
			salelistdisplay() ;		//当前销售单信息总览
			break;
		case 5:
			delasalelist() ;		//清空全部销售单记录
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