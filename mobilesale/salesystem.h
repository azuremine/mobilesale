#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "conio.h"
using namespace std;

class Salesys;
class Admin;
class Saler;
class Consumer;
class User;

static int adminnum;						//����Ա����
static int salernum;						//����Ա����
static int consnum;							//�ͻ�����

class Type		//�������
{
	
};

class Phone:public Type		//�ֻ���
{
	protected:				//���ó�Ա�����㹫��������ʹ��
		double mprice;		//�ֻ����
		float scrsize;		//�ֻ���Ļ�ߴ�
		string ctype;		//�ֻ��ͺ�
		string ramrom;		//�ֻ�RAM��ROM����
		string scrtrait;	//�ֻ���Ļ����
		Salesys *accountp[50];	
		int acnump;			//�ֻ���Ϣ��
};

class SaleList: public Type		//���۵���
{
	protected:
		int saleno;			//���۵���
		string bname;		//�ͻ�����
		unsigned long long bphoneno;		//�ͻ���ϵ�绰
		string bdate;		//��������
		double aprice;		//�ɽ��۸�
		string gift;		//��Ʒ
		string salename;	//����Ա����
		Salesys *accounts[100];
		int acnums;			//���۵���
};

class Salesys: public Phone , public SaleList		//����ϵͳ��
{
	public:
		Salesys(){};
		Salesys(string Ctype,string Scrtrait,float Scrsize,string Ramrom,double Mprice);
			//�ֻ���Ϣ���캯��		
		
		Salesys(int Saleno,string BName,string Ctype,double Aprice,string Gift,
			unsigned long long Bphoneno,string Bdate,string Salename);
			//���۵���Ϣ���캯��

		void addmob() ;				//��������ֻ���Ϣ
		void delmob() ;				//ɾ�������ֻ���Ϣ
		void delallmob() ;			//���ȫ���ֻ���¼
		void altermob() ;			//�޸��ֻ���������
		void psave() ;				//�����ֻ�����
		int pload() ;				//�����ֻ�����
		void ssave() ;				//�������۵�����
		int sload() ;				//�������۵�����
		void delsalelist() ;		//ɾ�����۵���Ϣ
		void delasalelist() ;		//���ȫ�����۵���¼
		void altersalelist() ;		//�޸����۵�������Ϣ
		void salelistdisplay() ;	//��ǰ���۵���Ϣ����
		void addsalelist() ;		//������۵���Ϣ
		void enter_admin();			//����Ա��¼
		void enter_saler();			//����Ա��¼
		void enter_consumer();		//�ͻ���¼
		void enter_user();			//�ο����
		void exitsystem();			//�˳�ϵͳ
		int load_admin();			//�������Ա��Ϣ
		int load_saler();			//��������Ա��Ϣ
		int load_consumer();		//����ͻ���Ϣ


		void functionshow();	//��������ʾ

		void mobdisplay() ;		//��ǰ�ֻ���Ϣ����
	protected:
		Admin * adcount[10];						//��Ź���Ա
		Saler *salercount[10];						//�������Ա
		Consumer *conscount[10];					//��ſͻ�
};

class Admin: public Salesys		//ϵͳ����Ա���м̳�salesys
{
	public:
		Admin(){};
		Admin(string Adid, string Adpasswd) :adid(Adid), adpasswd(Adpasswd) {}
		string get_adid();						//��ȡ����Ա�˺�
		string get_adpasswd();					//��ȡ����Ա����

	private:
		string adid;							//����Ա�˺�
		string adpasswd;						//����Ա����
};

class Saler: private Admin		//����Ա˽�м̳�admin
{
	public:
		Saler(){};
		Saler(string Salerid, string Salerpasswd, string Salername) :
			salerid(Salerid), salerpasswd(Salerpasswd), salername(Salername) {}
		string get_salerid();						//��ȡ����Ա�˺�
		string get_salerpasswd();					//��ȡ����Ա����

	private:
		string salerid;							//����Ա�˺�
		string salerpasswd;						//����Ա����
		string salername;						//����Ա����
};

class Consumer: private Admin	//�˿�˽�м̳�admin
{
	public:
		Consumer(){};
		Consumer(string Consid, string Conspasswd, string Consname, string Consphone) :
			consid(Consid), conspasswd(Conspasswd), consname(Consname),
		consphone(Consphone) {}
		string get_consid();						//��ȡ�ͻ��˺�
		string get_conspasswd();					//��ȡ�ͻ�����
	private:
		string consphone;						//�ͻ��绰
		string consid;							//�ͻ��˺�
		string conspasswd;						//�ͻ�����
		string consname;						//�ͻ�����
};

class Visitor: private Admin	//�ο�˽�м̳�admin
{

};
