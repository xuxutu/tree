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

//ѧ����̳���ݻ���
class Student :public Identity
{
public:
	//���캯��
	Student();
	//�вι���
	Student(int id,string name,string pawd);
	//����
	~Student();

    //�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴������ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

public:
	int m_id;
    //��������
	vector<ComputerRoom>vCom;
};