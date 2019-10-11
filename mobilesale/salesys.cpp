// salesys.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "salesystem.h"

Salesys::Salesys(string Ctype,string Scrtrait,float Scrsize,string Ramrom,double Mprice) 
	//�ֻ���Ϣ���캯��	
{
	ctype=Ctype;
	scrtrait=Scrtrait;
	scrsize=Scrsize;
	ramrom=Ramrom;
	mprice=Mprice;
}

Salesys::Salesys(int Saleno,string Bname,string Ctype,double Aprice,string Gift,
				 unsigned long long Bphoneno,string Bdate,string Salename)
	//���۵���Ϣ���캯��
{
	saleno=Saleno;
	bname=Bname;
	ctype=Ctype;
	aprice=Aprice;
	gift=Gift;
	bphoneno=Bphoneno;
	bdate=Bdate;
	salename=Salename;
}

void Salesys::psave()			//�����ֻ�����
{
	//�������ʽ���ļ�
	ofstream ofile("phonedata.txt",ios::out);
	//�������ʽ���ļ� phonedata.text ,���մ��ڴ����������
	ofstream outfile("phonedata.txt",ios::out);
	int n=0;
	outfile<<acnump;
	outfile<<endl;
	for(n=0;n<acnump;n++)
	{
		//����Ϣд������ļ�phonedata.tet
		outfile<<accountp[n]->ctype<<" ";
		outfile<<accountp[n]->scrtrait<<" ";
		outfile<<accountp[n]->scrsize<<" ";
		outfile<<accountp[n]->ramrom<<" ";
		outfile<<accountp[n]->mprice<<endl;
	}
	outfile.close();
}

int Salesys::pload()			//�����ֻ�����
{
	//�����뷽ʽ���ļ�
	ifstream infile("phonedata.txt",ios::in);
	if(!infile)
	{
		cerr<<"��ȡ���󣬵�ǰ���ֻ�������Ϣ��"<<endl;
		return 1;
	}
	int n;
	infile>>acnump;
	for(n=0;n<acnump;n++)
	{
		infile>>ctype;
		infile>>scrtrait;
		infile>>scrsize;
		infile>>ramrom;
		infile>>mprice;
		Salesys *acc = new Salesys(ctype,scrtrait,scrsize,ramrom,mprice); //ÿ����һ��n����һ���ڴ�
		accountp[n] = acc;	//��ֵ�׵�ַ
	}
	infile.close();
	cout<<"��ȡ�ֻ�������Ϣ������"<<endl;
	return 0;
}

void Salesys::addmob()			//����ֻ���Ϣ
{
	cout<<"������Ҫ����ֻ��Ļ�����Ϣ��";
	cout<<endl<<"�ֻ��ͺţ�";
	cin>>ctype;
	cout<<endl<<"�ֻ���Ļ���ԣ�";
	cin>>scrtrait;
	cout<<endl<<"�ֻ���Ļ�ߴ磺";
	cin>>scrsize;
	cout<<endl<<"�ֻ� RAM+ROM ������";
	cin>>ramrom;
	cout<<endl<<"�ֻ���ۣ�";
	cin>>mprice;
	Salesys *acc = new Salesys(ctype,scrtrait,scrsize,ramrom,mprice);
	accountp[acnump] = acc;
	cout<<"����ֻ��Ļ�����Ϣ�ɹ�"<<endl;
	acnump++;
	psave();					//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();
	return ;
}

void Salesys::delmob()					//ɾ�������ֻ���Ϣ
{
	string id;
	cout<<"������Ҫɾ�����ֻ��ͺţ�";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnump)&&(flag))			//����ҵ���Ӧ�ֻ��ͺ�
	{
		if(!id.compare(accountp[i]->ctype))
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"������ֻ��ͺŲ����ڣ�"<<endl;
		return;
	}
	for(int j=i;j<acnump;j++)
	{
		accountp[j]=accountp[j+1];
	}
	accountp[acnump-1]=NULL;
	acnump--;
	cout<<"���ֻ��ͺ���ɾ����"<<endl;
	psave();						//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();
	return ;
}	

void Salesys::delallmob()				//ɾ�������ڿ��ֻ���Ϣ
{
	char ch;
	cout<<"�Ƿ�ȷ��ɾ�������ڿ��ֻ���Ϣ����Y/N)"<<endl;
	cin>>ch;						//�жϼ����ַ��Ƿ�Ϊ�� Y\N ��
	if(ch == 'Y')
	{
		acnump=0;			//���ǣ��������������
		cout<<"������ݳɹ���"<<endl;
	}
	else if(ch == 'N')
		cout<<"ȡ��ɾ�������ڿ��ֻ���Ϣ������������һ���˵���"<<endl;		//�����ǣ��򷵻���һ������
	else
		cout<<"������󣡼���������һ���˵���"<<endl;
	psave();			//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();							
	return ;
}

void Salesys::altermob()					//�޸��ֻ���������
{
	string id;
	cout<<"������Ҫ�޸Ĳ������ֻ��ͺţ�";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnump)&&(flag))			//����ҵ���Ӧ�ֻ��ͺ�
	{
		if(!id.compare(accountp[i]->ctype))
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"������ֻ��ͺŲ����ڣ�"<<endl;
		return;
	}
	else if(!flag)
	{
		int num;
		cout<<"��ѡ��Ҫ�޸ĵĲ������ƣ�����1��2��..�س�)��1���ֻ��ͺ� 2���ֻ�";
		cout<<"��Ļ���� 3���ֻ���Ļ�ߴ� 4���ֻ�RAM+ROM���� 5���ֻ��۸� 0���������˵�"<<endl;
		cin>>num;
		if(num == 1)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accountp[i]->ctype = alter;
		}
		else if(num == 2)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accountp[i]->scrtrait = alter;
		}
		else if(num == 3)
		{
			float alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accountp[i]->scrsize = alter;
		}
		else if(num == 4)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accountp[i]->ramrom = alter;
		}
		else if(num == 5)
		{
			double alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accountp[i]->mprice = alter;
		}
		else if(num == 0)
			return ;
		else
		{
			cout<<"������󣡼����������˵���";
			cin.get();
			return ;
		}
	}
	cout<<endl<<"�޸��ֻ������ɹ���";
	psave();						//������Ϣ
	cin.get();
	return ;
}

void Salesys::mobdisplay()			//��ǰ�ڿ��ֻ���Ϣ����
{
	if(pload())						//��������
		return ;
	int n; 
	cout<<"�ͺ�"<<"\t\t        "<<"��Ļ����"<<"     \t"<<"��Ļ�ߴ�";
	cout<<"    \t"<<"�ֻ�RAM+ROM����"<<"    \t"<<"�ֻ����"<<endl;
	for(n=0;n<acnump;n++)
	{
		cout<<accountp[n]->ctype;
		cout<<"\t\t"<<accountp[n]->scrtrait;
		cout<<"\t\t"<<accountp[n]->scrsize;
		cout<<"\t\t"<<accountp[n]->ramrom;
		cout<<"\t\t"<<accountp[n]->mprice;
		cout<<endl;
	}
	cout<<endl;
	cout<<"****************�ܼ�"<<acnump<<"����¼******************"<<endl;
	cout<<"�������������һ��!"<<endl;
	getch();
	return;
}

void Salesys::addsalelist()	//�˿�������۵���Ϣ
{
	cout<<"������Ҫ������۵��Ļ�����Ϣ��";
	cout<<endl<<"���۵��ţ�";
	cin>>saleno;
	cout<<endl<<"�ͻ�������";
	cin>>bname;
	cout<<endl<<"�ֻ��ͺţ�";
	cin>>ctype;
	cout<<endl<<"�ɽ��۸�";
	cin>>aprice;
	cout<<endl<<"��Ʒ��";
	cin>>gift;
	cout<<endl<<"�ͻ���ϵ�绰��";
	cin>>bphoneno;
	cout<<endl<<"�������ڣ�20XX-XX-XX����";
	cin>>bdate;
	cout<<endl<<"����Ա������";
	cin>>salename;
	Salesys *acc = new Salesys(saleno,bname,ctype,aprice,gift,
				 bphoneno,bdate,salename);
	accounts[acnums] = acc;
	cout<<endl<<"������۵��Ļ�����Ϣ�ɹ�!"<<endl;
	acnums++;
	ssave();							//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();
	return ;
}

void Salesys::ssave()			////�������۵�����
{
	//�������ʽ���ļ�
	ofstream ofile("slistdata.txt",ios::out);
	//�������ʽ���ļ� phonedata.txt ,���մ��ڴ����������
	ofstream outfile("slistdata.txt",ios::out);
	int n=0;
	outfile<<acnums;
	outfile<<endl;
	for(n=0;n<acnums;n++)
	{
		//����Ϣд������ļ�phonedata.dat
		outfile<<accounts[n]->saleno<<" ";
		outfile<<accounts[n]->bname<<" ";
		outfile<<accounts[n]->ctype<<" ";
		outfile<<accounts[n]->aprice<<" ";
		outfile<<accounts[n]->gift<<" ";
		outfile<<accounts[n]->bphoneno<<" ";
		outfile<<accounts[n]->bdate<<" ";
		outfile<<accounts[n]->salename<<endl;
	}
	outfile.close();
}

int Salesys::sload()			//�������۵�����
{
	//�����뷽ʽ���ļ�
	ifstream infile("slistdata.txt",ios::in);
	if(!infile)
	{
		cerr<<"��ȡ���󣬵�ǰ�����۵�������Ϣ��"<<endl;
		return 1;
	}
	int n;
	infile>>acnums;
	for(n=0;n<acnums;n++)
	{
		infile>>saleno;
		infile>>bname;
		infile>>ctype;
		infile>>aprice;
		infile>>gift;
		infile>>bphoneno;
		infile>>bdate;
		infile>>salename;
		Salesys *acc = new Salesys(saleno,bname,ctype,aprice,gift,
				 bphoneno,bdate,salename); //ÿ����һ��n����һ���ڴ�
		accounts[n] = acc;	//��ֵ�׵�ַ
	}
	infile.close();
	cout<<"��ȡ���۵�������Ϣ������"<<endl;
	return 0;
}

void Salesys::delsalelist()			//ɾ���������۵���Ϣ
{
	int id;
	cout<<"������Ҫɾ�������۵��ţ�";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnums)&&(flag))			//����ҵ���Ӧ���۵���
	{
		if(id==accounts[i]->saleno)
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"��������۵��Ų����ڣ�"<<endl;
		cin.get();
		return;
	}
	for(int j=i;j<acnums;j++)
	{
		accounts[j]=accounts[j+1];
	}
	accounts[acnums-1]=NULL;
	acnums--;
	cout<<"�����۵�����ɾ����"<<endl;
	ssave();							//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();
	return ;
}

void Salesys::delasalelist()			//���ȫ�����۵���¼
{
	char ch;
	cout<<"�Ƿ�ȷ��ɾ���������۵���Ϣ����Y/N)"<<endl;
	cin>>ch;						//�жϼ����ַ��Ƿ�Ϊ�� Y\N ��
	if(ch == 'Y')
	{
		acnums = 0;	//���ǣ��������������	
		cout<<"������ݳɹ���"<<endl;
	}
	else if(ch == 'N')
		cout<<"ȡ��ɾ���������۵���Ϣ������������ҳ�棡";		//�����ǣ��򷵻���һ������
	else
		cout<<"������󣡼����������˵���"<<endl;
	ssave();				//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();			
	return ;
}

void Salesys::altersalelist() 					//�޸����۵�������Ϣ
{
	int id;
	cout<<"������Ҫ�޸���Ϣ�����۵��ţ�";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnums)&&(flag))			//����ҵ���Ӧ�ֻ��ͺ�
	{
		if(id==accounts[i]->saleno)
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"��������۵��Ų����ڣ�"<<endl;
		cin.get();
		return;
	}
	else if(!flag)
	{
		int num;
		cout<<"��ѡ��Ҫ�޸ĵ���Ϣ���ƣ�����1��2��..�س�)��1�����۵��� 2���ͻ����� ";
		cout<<"3���ֻ��ͺ� 4���ɽ��۸� 5����Ʒ 6���ͻ���ϵ�绰 7���������� ";
		cout<<"8������Ա���� 0���������˵�"<<endl;
		cin>>num;
		if(num == 1)
		{
			int alter;
			cout<<"�������޸ĵ����ݣ�";
			cin>>alter;
			accounts[i]->saleno = alter;
		}
		else if(num == 2)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->bname = alter;
		}
		else if(num == 3)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->ctype = alter;
		}
		else if(num == 4)
		{
			double alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->aprice = alter;
		}
		else if(num == 5)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->gift = alter;
		}
		else if(num == 6)
		{
			unsigned long long alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->bphoneno;
		}
		else if(num == 7)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->bdate;
		}
		else if(num == 8)
		{
			string alter;
			cout<<"�������޸ĵĲ�����";
			cin>>alter;
			accounts[i]->salename;
		}
		else if(num == 0)
			return ;
		else
		{
			cout<<"������󣡼���������һ����";
			getch();
			return ;
		}
	}
	cout<<endl<<"�޸��ֻ������ɹ���"<<endl;
	ssave();						//������Ϣ
	cout<<"�������������һ���˵���"<<endl;
	getch();
	return ;
}

void Salesys::salelistdisplay()		//��ǰ���۵���Ϣ����
{
	if(sload())
		return;						//��������
	int n;
	cout<<"���۵���"<<"   "<<"�ͻ�����"<<"   "<<"�ֻ��ͺ�";
	cout<<"   "<<"�ɽ��۸�"<<"   "<<"��Ʒ"<<"   "<<"�ͻ���ϵ�绰";
	cout<<"   "<<"��������"<<"   "<<"����Ա����"<<endl;
	for(n=0;n<acnums;n++)
	{
		cout<<accounts[n]->saleno;
		cout<<"       "<<accounts[n]->bname;
		cout<<"       "<<accounts[n]->ctype;
		cout<<"      "<<accounts[n]->aprice;
		cout<<"      "<<accounts[n]->gift;
		cout<<"    "<<accounts[n]->bphoneno;
		cout<<"    "<<accounts[n]->bdate;
		cout<<"    "<<accounts[n]->salename;
		cout<<endl;
	}
	cout<<endl<<"***************�ܼ�"<<acnums<<"����¼****************"<<endl;
	cout<<"�������������һ���˵�!"<<endl;
	getch();
	return;
}


