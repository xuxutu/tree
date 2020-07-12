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

//����Ա��̳�����ݻ���
class Manager :public Identity
{
public:
	//����
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//����
	~Manager();

	//�˵�
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void clearFile();

	//��ʼ������
	void initVector();

	//����ظ�
	bool checkRepeat(int id, int type);

public:
	vector<Student>vStu;
	vector<Teacher>vTea;
	vector<ComputerRoom>vCom;//��������
};