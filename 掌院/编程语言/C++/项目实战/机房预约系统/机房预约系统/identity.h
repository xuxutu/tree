#pragma once
#include<iostream>
using namespace std;

//����ϵͳ���У���������ݣ��й���Ҳ������
//�������ݻ���

class Identity
{
public:
	//�����ӿڣ�ÿ����̳�����Ҫ��д�����Լ��ķ���
	virtual void openMenu() = 0;

public:
	string m_Name;//����
	string m_Pwd;//����
};