#pragma once
#include <iostream>
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>
using namespace std;

class OrderFile
{
public:
	//构造函数
	OrderFile();
	
	//析构
	~OrderFile();

	//更新预约记录
	void updateOrder();

public:
	//记录预约条目
	int m_Size;

	//记录所有预约信息的容器
	//key 条数
	//value 每一条所有信息
	map<int, map<string, string>> m_OrderData;

};