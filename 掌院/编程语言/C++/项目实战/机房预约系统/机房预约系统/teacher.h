#pragma once
#include"identity.h"
#include <iostream>
#include<string>
#include"orderFile.h"
#include<vector>
using namespace std;

//��ʦ��̳л���
class Teacher :public Identity
{
public:
	//����
	Teacher();

	//�вι���
	Teacher(int empId,string name,string pwd);
	
	//����
	~Teacher();

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();


public:
	int m_EmpId;
};
