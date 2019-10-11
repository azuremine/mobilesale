// salesys.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "salesystem.h"

Salesys::Salesys(string Ctype,string Scrtrait,float Scrsize,string Ramrom,double Mprice) 
	//手机信息构造函数	
{
	ctype=Ctype;
	scrtrait=Scrtrait;
	scrsize=Scrsize;
	ramrom=Ramrom;
	mprice=Mprice;
}

Salesys::Salesys(int Saleno,string Bname,string Ctype,double Aprice,string Gift,
				 unsigned long long Bphoneno,string Bdate,string Salename)
	//销售单信息构造函数
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

void Salesys::psave()			//保存手机数据
{
	//以输出方式打开文件
	ofstream ofile("phonedata.txt",ios::out);
	//以输出方式打开文件 phonedata.text ,接收从内存输出的数据
	ofstream outfile("phonedata.txt",ios::out);
	int n=0;
	outfile<<acnump;
	outfile<<endl;
	for(n=0;n<acnump;n++)
	{
		//把信息写入磁盘文件phonedata.tet
		outfile<<accountp[n]->ctype<<" ";
		outfile<<accountp[n]->scrtrait<<" ";
		outfile<<accountp[n]->scrsize<<" ";
		outfile<<accountp[n]->ramrom<<" ";
		outfile<<accountp[n]->mprice<<endl;
	}
	outfile.close();
}

int Salesys::pload()			//读入手机数据
{
	//已输入方式打开文件
	ifstream infile("phonedata.txt",ios::in);
	if(!infile)
	{
		cerr<<"读取错误，当前无手机数据信息！"<<endl;
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
		Salesys *acc = new Salesys(ctype,scrtrait,scrsize,ramrom,mprice); //每读入一个n开辟一段内存
		accountp[n] = acc;	//赋值首地址
	}
	infile.close();
	cout<<"读取手机数据信息正常！"<<endl;
	return 0;
}

void Salesys::addmob()			//添加手机信息
{
	cout<<"请输入要添加手机的基本信息：";
	cout<<endl<<"手机型号：";
	cin>>ctype;
	cout<<endl<<"手机屏幕特性：";
	cin>>scrtrait;
	cout<<endl<<"手机屏幕尺寸：";
	cin>>scrsize;
	cout<<endl<<"手机 RAM+ROM 参数：";
	cin>>ramrom;
	cout<<endl<<"手机标价：";
	cin>>mprice;
	Salesys *acc = new Salesys(ctype,scrtrait,scrsize,ramrom,mprice);
	accountp[acnump] = acc;
	cout<<"添加手机的基本信息成功"<<endl;
	acnump++;
	psave();					//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();
	return ;
}

void Salesys::delmob()					//删除整条手机信息
{
	string id;
	cout<<"请输入要删除的手机型号：";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnump)&&(flag))			//如果找到对应手机型号
	{
		if(!id.compare(accountp[i]->ctype))
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"输入的手机型号不存在！"<<endl;
		return;
	}
	for(int j=i;j<acnump;j++)
	{
		accountp[j]=accountp[j+1];
	}
	accountp[acnump-1]=NULL;
	acnump--;
	cout<<"该手机型号已删除！"<<endl;
	psave();						//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();
	return ;
}	

void Salesys::delallmob()				//删除所有在库手机信息
{
	char ch;
	cout<<"是否确认删除所有在库手机信息？（Y/N)"<<endl;
	cin>>ch;						//判断键入字符是否为： Y\N ？
	if(ch == 'Y')
	{
		acnump=0;			//若是，则清空数组内容
		cout<<"清空数据成功！"<<endl;
	}
	else if(ch == 'N')
		cout<<"取消删除所有在库手机信息！即将返回上一级菜单！"<<endl;		//若不是，则返回上一级界面
	else
		cout<<"输入错误！即将返回上一级菜单！"<<endl;
	psave();			//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();							
	return ;
}

void Salesys::altermob()					//修改手机基本参数
{
	string id;
	cout<<"请输入要修改参数的手机型号：";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnump)&&(flag))			//如果找到对应手机型号
	{
		if(!id.compare(accountp[i]->ctype))
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"输入的手机型号不存在！"<<endl;
		return;
	}
	else if(!flag)
	{
		int num;
		cout<<"请选择要修改的参数名称（键入1、2、..回车)：1、手机型号 2、手机";
		cout<<"屏幕特性 3、手机屏幕尺寸 4、手机RAM+ROM参数 5、手机价格 0、返回主菜单"<<endl;
		cin>>num;
		if(num == 1)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accountp[i]->ctype = alter;
		}
		else if(num == 2)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accountp[i]->scrtrait = alter;
		}
		else if(num == 3)
		{
			float alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accountp[i]->scrsize = alter;
		}
		else if(num == 4)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accountp[i]->ramrom = alter;
		}
		else if(num == 5)
		{
			double alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accountp[i]->mprice = alter;
		}
		else if(num == 0)
			return ;
		else
		{
			cout<<"输入错误！即将返回主菜单！";
			cin.get();
			return ;
		}
	}
	cout<<endl<<"修改手机参数成功！";
	psave();						//保存信息
	cin.get();
	return ;
}

void Salesys::mobdisplay()			//当前在库手机信息总览
{
	if(pload())						//读入数据
		return ;
	int n; 
	cout<<"型号"<<"\t\t        "<<"屏幕特性"<<"     \t"<<"屏幕尺寸";
	cout<<"    \t"<<"手机RAM+ROM参数"<<"    \t"<<"手机标价"<<endl;
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
	cout<<"****************总计"<<acnump<<"条记录******************"<<endl;
	cout<<"按任意键返回上一级!"<<endl;
	getch();
	return;
}

void Salesys::addsalelist()	//顾客添加销售单信息
{
	cout<<"请输入要添加销售单的基本信息：";
	cout<<endl<<"销售单号：";
	cin>>saleno;
	cout<<endl<<"客户姓名：";
	cin>>bname;
	cout<<endl<<"手机型号：";
	cin>>ctype;
	cout<<endl<<"成交价格：";
	cin>>aprice;
	cout<<endl<<"赠品：";
	cin>>gift;
	cout<<endl<<"客户联系电话：";
	cin>>bphoneno;
	cout<<endl<<"购买日期（20XX-XX-XX）：";
	cin>>bdate;
	cout<<endl<<"销售员姓名：";
	cin>>salename;
	Salesys *acc = new Salesys(saleno,bname,ctype,aprice,gift,
				 bphoneno,bdate,salename);
	accounts[acnums] = acc;
	cout<<endl<<"添加销售单的基本信息成功!"<<endl;
	acnums++;
	ssave();							//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();
	return ;
}

void Salesys::ssave()			////保存销售单数据
{
	//以输出方式打开文件
	ofstream ofile("slistdata.txt",ios::out);
	//以输出方式打开文件 phonedata.txt ,接收从内存输出的数据
	ofstream outfile("slistdata.txt",ios::out);
	int n=0;
	outfile<<acnums;
	outfile<<endl;
	for(n=0;n<acnums;n++)
	{
		//把信息写入磁盘文件phonedata.dat
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

int Salesys::sload()			//读入销售单数据
{
	//已输入方式打开文件
	ifstream infile("slistdata.txt",ios::in);
	if(!infile)
	{
		cerr<<"读取错误，当前无销售单数据信息！"<<endl;
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
				 bphoneno,bdate,salename); //每读入一个n开辟一段内存
		accounts[n] = acc;	//赋值首地址
	}
	infile.close();
	cout<<"读取销售单数据信息正常！"<<endl;
	return 0;
}

void Salesys::delsalelist()			//删除单条销售单信息
{
	int id;
	cout<<"请输入要删除的销售单号：";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnums)&&(flag))			//如果找到对应销售单号
	{
		if(id==accounts[i]->saleno)
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"输入的销售单号不存在！"<<endl;
		cin.get();
		return;
	}
	for(int j=i;j<acnums;j++)
	{
		accounts[j]=accounts[j+1];
	}
	accounts[acnums-1]=NULL;
	acnums--;
	cout<<"该销售单号已删除！"<<endl;
	ssave();							//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();
	return ;
}

void Salesys::delasalelist()			//清空全部销售单记录
{
	char ch;
	cout<<"是否确认删除所有销售单信息？（Y/N)"<<endl;
	cin>>ch;						//判断键入字符是否为： Y\N ？
	if(ch == 'Y')
	{
		acnums = 0;	//若是，则清空数组内容	
		cout<<"清空数据成功！"<<endl;
	}
	else if(ch == 'N')
		cout<<"取消删除所有销售单信息！即将返回主页面！";		//若不是，则返回上一级界面
	else
		cout<<"输入错误！即将返回主菜单！"<<endl;
	ssave();				//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();			
	return ;
}

void Salesys::altersalelist() 					//修改销售单基本信息
{
	int id;
	cout<<"请输入要修改信息的销售单号：";
	cin>>id;
	int flag = 1;
	int i = 0;
	while ((i<acnums)&&(flag))			//如果找到对应手机型号
	{
		if(id==accounts[i]->saleno)
			flag = 0;					
		else
			i++;
	}
	if(flag)
	{
		cout<<"输入的销售单号不存在！"<<endl;
		cin.get();
		return;
	}
	else if(!flag)
	{
		int num;
		cout<<"请选择要修改的信息名称（键入1、2、..回车)：1、销售单号 2、客户姓名 ";
		cout<<"3、手机型号 4、成交价格 5、赠品 6、客户联系电话 7、购买日期 ";
		cout<<"8、销售员姓名 0、返回主菜单"<<endl;
		cin>>num;
		if(num == 1)
		{
			int alter;
			cout<<"请输入修改的内容：";
			cin>>alter;
			accounts[i]->saleno = alter;
		}
		else if(num == 2)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->bname = alter;
		}
		else if(num == 3)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->ctype = alter;
		}
		else if(num == 4)
		{
			double alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->aprice = alter;
		}
		else if(num == 5)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->gift = alter;
		}
		else if(num == 6)
		{
			unsigned long long alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->bphoneno;
		}
		else if(num == 7)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->bdate;
		}
		else if(num == 8)
		{
			string alter;
			cout<<"请输入修改的参数：";
			cin>>alter;
			accounts[i]->salename;
		}
		else if(num == 0)
			return ;
		else
		{
			cout<<"输入错误！即将返回上一级！";
			getch();
			return ;
		}
	}
	cout<<endl<<"修改手机参数成功！"<<endl;
	ssave();						//保存信息
	cout<<"按任意键返回上一级菜单！"<<endl;
	getch();
	return ;
}

void Salesys::salelistdisplay()		//当前销售单信息总览
{
	if(sload())
		return;						//读入数据
	int n;
	cout<<"销售单号"<<"   "<<"客户姓名"<<"   "<<"手机型号";
	cout<<"   "<<"成交价格"<<"   "<<"赠品"<<"   "<<"客户联系电话";
	cout<<"   "<<"购买日期"<<"   "<<"销售员姓名"<<endl;
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
	cout<<endl<<"***************总计"<<acnums<<"条记录****************"<<endl;
	cout<<"按任意键返回上一级菜单!"<<endl;
	getch();
	return;
}


