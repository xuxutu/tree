#pragma once
#include"globalFile.h"
#include"identity.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
using namespace std;

//管理员类继承于身份基类
class Manager :public Identity
{
public:
	//构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//析构
	~Manager();

	//菜单
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void clearFile();

	//初始化容器
	void initVector();

	//检测重复
	bool checkRepeat(int id, int type);

public:
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;//机房容器
};