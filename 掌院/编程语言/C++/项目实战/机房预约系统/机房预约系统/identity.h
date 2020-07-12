#pragma once
#include<iostream>
using namespace std;

//整个系统当中，有三种身份，有共性也有特性
//抽象出身份基类

class Identity
{
public:
	//公共接口，每个类继承它都要重写属于自己的方法
	virtual void openMenu() = 0;

public:
	string m_Name;//姓名
	string m_Pwd;//密码
};