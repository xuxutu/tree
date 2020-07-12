#pragma once
#include"identity.h"
#include <iostream>
#include<string>
#include"orderFile.h"
#include<vector>
using namespace std;

//教师类继承基类
class Teacher :public Identity
{
public:
	//构造
	Teacher();

	//有参构造
	Teacher(int empId,string name,string pwd);
	
	//析构
	~Teacher();

	//菜单界面
	virtual void openMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();


public:
	int m_EmpId;
};
