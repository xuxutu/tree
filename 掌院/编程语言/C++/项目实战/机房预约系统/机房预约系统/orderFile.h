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
	//���캯��
	OrderFile();
	
	//����
	~OrderFile();

	//����ԤԼ��¼
	void updateOrder();

public:
	//��¼ԤԼ��Ŀ
	int m_Size;

	//��¼����ԤԼ��Ϣ������
	//key ����
	//value ÿһ��������Ϣ
	map<int, map<string, string>> m_OrderData;

};