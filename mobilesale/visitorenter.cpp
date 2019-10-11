/**************************
*   user.cpp
**************************/
#include "stdafx.h"
#include "salesystem.h"


void Salesys::enter_user()				//游客入口
{
	int n;
	do
	{
		cout << "**********************************" << endl;
		cout << "1、查询手机信息" << endl << endl;
		cout << "0、返回上一级菜单" << endl;
		cout << "**********************************" << endl;

		cout << "请输入操作编号：";
		cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			mobdisplay() ;		//当前手机信息总览
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