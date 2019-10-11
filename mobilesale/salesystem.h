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

static int adminnum;						//管理员数量
static int salernum;						//销售员数量
static int consnum;							//客户数量

class Type		//抽象基类
{
	
};

class Phone:public Type		//手机类
{
	protected:				//公用成员，方便公共派生类使用
		double mprice;		//手机标价
		float scrsize;		//手机屏幕尺寸
		string ctype;		//手机型号
		string ramrom;		//手机RAM、ROM参数
		string scrtrait;	//手机屏幕特性
		Salesys *accountp[50];	
		int acnump;			//手机信息数
};

class SaleList: public Type		//销售单类
{
	protected:
		int saleno;			//销售单号
		string bname;		//客户姓名
		unsigned long long bphoneno;		//客户联系电话
		string bdate;		//购买日期
		double aprice;		//成交价格
		string gift;		//赠品
		string salename;	//销售员姓名
		Salesys *accounts[100];
		int acnums;			//销售单数
};

class Salesys: public Phone , public SaleList		//销售系统类
{
	public:
		Salesys(){};
		Salesys(string Ctype,string Scrtrait,float Scrsize,string Ramrom,double Mprice);
			//手机信息构造函数		
		
		Salesys(int Saleno,string BName,string Ctype,double Aprice,string Gift,
			unsigned long long Bphoneno,string Bdate,string Salename);
			//销售单信息构造函数

		void addmob() ;				//添加整条手机信息
		void delmob() ;				//删除整条手机信息
		void delallmob() ;			//清空全部手机记录
		void altermob() ;			//修改手机基本参数
		void psave() ;				//保存手机数据
		int pload() ;				//读入手机数据
		void ssave() ;				//保存销售单数据
		int sload() ;				//读入销售单数据
		void delsalelist() ;		//删除销售单信息
		void delasalelist() ;		//清空全部销售单记录
		void altersalelist() ;		//修改销售单基本信息
		void salelistdisplay() ;	//当前销售单信息总览
		void addsalelist() ;		//添加销售单信息
		void enter_admin();			//管理员登录
		void enter_saler();			//销售员登录
		void enter_consumer();		//客户登录
		void enter_user();			//游客入口
		void exitsystem();			//退出系统
		int load_admin();			//读入管理员信息
		int load_saler();			//读入销售员信息
		int load_consumer();		//读入客户信息


		void functionshow();	//主界面显示

		void mobdisplay() ;		//当前手机信息总览
	protected:
		Admin * adcount[10];						//存放管理员
		Saler *salercount[10];						//存放销售员
		Consumer *conscount[10];					//存放客户
};

class Admin: public Salesys		//系统管理员公有继承salesys
{
	public:
		Admin(){};
		Admin(string Adid, string Adpasswd) :adid(Adid), adpasswd(Adpasswd) {}
		string get_adid();						//获取管理员账号
		string get_adpasswd();					//获取管理员密码

	private:
		string adid;							//管理员账号
		string adpasswd;						//管理员密码
};

class Saler: private Admin		//销售员私有继承admin
{
	public:
		Saler(){};
		Saler(string Salerid, string Salerpasswd, string Salername) :
			salerid(Salerid), salerpasswd(Salerpasswd), salername(Salername) {}
		string get_salerid();						//获取销售员账号
		string get_salerpasswd();					//获取销售员密码

	private:
		string salerid;							//销售员账号
		string salerpasswd;						//销售员密码
		string salername;						//销售员姓名
};

class Consumer: private Admin	//顾客私有继承admin
{
	public:
		Consumer(){};
		Consumer(string Consid, string Conspasswd, string Consname, string Consphone) :
			consid(Consid), conspasswd(Conspasswd), consname(Consname),
		consphone(Consphone) {}
		string get_consid();						//获取客户账号
		string get_conspasswd();					//获取客户密码
	private:
		string consphone;						//客户电话
		string consid;							//客户账号
		string conspasswd;						//客户密码
		string consname;						//客户姓名
};

class Visitor: private Admin	//游客私有继承admin
{

};
