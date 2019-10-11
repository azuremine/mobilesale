#include "stdafx.h"
#include "salesystem.h"

int main()
{
	Salesys sale;
	int n;
	do{
		system("cls");
		cout << "****************身份登入界面*************" << endl;
		cout << "		1、管理员		" << endl;
		cout << "		2、销售员		" << endl;
		cout << "		3、客户		" << endl;
		cout << "		4、游客		" << endl;
		cout << "		0、退出系统			" << endl;
		cout << "请输入操作编号：";
		cin >> n;
		switch (n)
		{
			case 1:
				system("cls");
				if(!sale.load_admin())			//管理员
					sale.enter_admin();
				break;
			case 2:
				system("cls");
				if(!sale.load_saler())
					sale.enter_saler();			//销售员
				break;
			case 3:
				system("cls");
				if(!sale.load_consumer())		//顾客
					sale.enter_consumer();
				break;
			case 4:
				system("cls");					//游客
				sale.enter_user();
				break;
			case 0:
				return 0;
			default:
				cout<<"输入错误！请重新输入！"<<endl;
				break;
		}
	  }while(1);
	return 0;
}