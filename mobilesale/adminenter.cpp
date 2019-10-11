/**************************
*   admin.cpp
**************************/
#include "stdafx.h"
#include "salesystem.h"


string Admin::get_adid()					//获取管理员账号
{
	return adid;
}
string Admin::get_adpasswd()				//获取管理员密码
{
	return adpasswd;
}


int Salesys::load_admin()				//读入管理员信息
{
	ifstream infile("admin.txt", ios::in);	//以输入方式打开文件
	if (!infile)
	{
		system("cls");
		cerr << "读取错误，无管理员信息！" << endl;
		return 1;
	}
	int i;
	string adid, adpasswd;
	infile >> adminnum;
	for (i = 0; i<adminnum; i++)					//全部读入
	{
		infile >> adid;
		infile >> adpasswd;

		Admin *ad = new Admin(adid, adpasswd);	//每读入一个i开辟一段内存
		adcount[i] = ad;						//赋值首地址
	}
	infile.close();
	cout << "读取管理员资料正常！" << endl;
	return 0;
}

void Salesys::enter_admin()				//管理员登陆
{
	string adid;
	cout << "请输入管理员账号：";
	cin >> adid;
	int flag = 1;
	int i = 0;							//__page_break__
	while ((i<adminnum) && (flag == 1))			//循环查找
	{
		if (adid.compare(adcount[i]->get_adid()) == 0)	//判断账号
			flag = 0;
		else
			i++;
	}
	if (flag == 1)
	{
		cout << "该管理员账号不存在!" << endl;
		getch();
		return ;								//返回
	}
	cout << "请输入管理员密码：";
	string adpasswd;
	cin >> adpasswd;
	if (adpasswd != adcount[i]->get_adpasswd())	//判断密码
	{
		cout<<"密码错误！"<<endl;
		getch();
		return;								//返回
	}
	int n;
	do
	{
		cout << "**********************************" << endl;
		cout << "1、增加手机信息" << endl;
		cout << "2、删除手机信息" << endl;
		cout << "3、修改手机信息" << endl;
		cout << "4、查看手机信息" << endl;
		cout << "5、清空所有手机信息" << endl <<endl;

		cout << "6、增加销售单信息" << endl;
		cout << "7、删除销售单信息" << endl;
		cout << "8、修改销售单信息" << endl;
		cout << "9、查看销售单信息" << endl;
		cout << "10、清空所有销售单信息" << endl <<endl;

		cout << "0、返回上一级菜单" << endl;
		cout << "**********************************" << endl;

		cout << "请输入操作编号：";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			addmob();				//添加整条手机信息
			break;
		case 2:
			delmob();				//删除整条手机信息
			break;
		case 3:
			altermob();				//修改手机基本参数
			break;
		case 4:
			system("cls");
			mobdisplay();			//当前在库手机信息总览
			break;
		case 5:
			system("cls");
			delallmob();			//清空全部手机记录
			break;
		case 6:
			system("cls");
			addsalelist();			//添加销售单信息
			break;
		case 7:
			system("cls");
			delsalelist();			//删除销售单信息
			break;
		case 8:
			altersalelist();		//修改销售单基本信息
			system("cls");
			break;
		case 9:
			system("cls");
			salelistdisplay();		//当前销售单信息总览
			break;
		case 10:
			system("cls");
			delasalelist();			//清空全部销售单记录
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