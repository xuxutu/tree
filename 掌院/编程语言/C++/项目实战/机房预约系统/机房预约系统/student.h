#pragma once
#include"identity.h"
#include<iostream>
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
using namespace std;

//学生类继承身份基类
class Student :public Identity
{
public:
	//构造函数
	Student();
	//有参构造
	Student(int id,string name,string pawd);
	//析构
	~Student();

    //菜单界面
	virtual void openMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有人预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

public:
	int m_id;
    //机房容器
	vector<ComputerRoom>vCom;
};