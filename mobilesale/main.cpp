#include "stdafx.h"
#include "salesystem.h"

int main()
{
	Salesys sale;
	int n;
	do{
		system("cls");
		cout << "****************��ݵ������*************" << endl;
		cout << "		1������Ա		" << endl;
		cout << "		2������Ա		" << endl;
		cout << "		3���ͻ�		" << endl;
		cout << "		4���ο�		" << endl;
		cout << "		0���˳�ϵͳ			" << endl;
		cout << "�����������ţ�";
		cin >> n;
		switch (n)
		{
			case 1:
				system("cls");
				if(!sale.load_admin())			//����Ա
					sale.enter_admin();
				break;
			case 2:
				system("cls");
				if(!sale.load_saler())
					sale.enter_saler();			//����Ա
				break;
			case 3:
				system("cls");
				if(!sale.load_consumer())		//�˿�
					sale.enter_consumer();
				break;
			case 4:
				system("cls");					//�ο�
				sale.enter_user();
				break;
			case 0:
				return 0;
			default:
				cout<<"����������������룡"<<endl;
				break;
		}
	  }while(1);
	return 0;
}