#include"manager.h"

//����
Manager::Manager()
{


}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������,��ȡ�ļ�����ʦѧ������Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	ComputerRoom cr;

	while (ifs >> cr.m_ComId && ifs >> cr.m_Max)
	{
		vCom.push_back(cr);
	}
	ifs.close();
	cout <<"����������Ϊ��" <<vCom.size()<<endl;
}
//����
Manager::~Manager()
{



}

//�˵�
void Manager::openMenu()
{
	
	cout << "��ӭ����Ա" << m_Name << "��¼��" << endl;
		cout << endl << "----------------------------------------------------------------\n" << endl;
		cout << "\t\t|------------------------------|\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         1.����˺�           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         2.�鿴�˺�           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         3.�鿴����           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         4.���ԤԼ           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         0.ע����¼           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|------------------------------|\n" << endl;
		cout << "��ѡ�����Ĳ�����" << endl;



}

//����˺�
void Manager::addPerson()
{
	cout <<"����������˺�����" << endl;
	cout <<"1�����ѧ��" << endl;
	cout <<"2�������ʦ" << endl;

	string errorTip;//�ظ�������ʾ��
	string fileName;
	string tip;
	ofstream ofs;

	int sel = 0;
	cin >> sel;
	if (sel == 1)
	{
		//��ӵ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		//��ӵ�����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ������������룡";
	}

    //׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;//ѧ��/ְ����
	string name;
	string pwd;
	cout << tip << endl;
	
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id,sel);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout <<"��ӳɹ���" << endl;
	
	this->initVector();//ˢ������

	ofs.close();
	system("pause");
	system("cls");

}

void printStu(Student& s)
{
	cout << "ѧ�ţ�"<<s.m_id << "  ������ " << s.m_Name << endl;

}
void printTea(Teacher& t)
{
	cout << "ѧ�ţ�"<<t.m_EmpId<< "  ������ " << t.m_Name << endl;

}

//�鿴�˺�
void Manager::showPerson()
{
	cout <<"��ѡ��Ҫ��ʾ�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int sel = 0;
	cin >> sel;

	if (sel == 1)
	{
		cout <<"���е�ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(),vStu.end(),printStu);
	}
	else
	{
		cout << "���е���ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(),printTea);
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout <<"��������Ϣ����"<< endl;
	for (auto it = vCom.begin(); it != vCom.end(); it++)
	{
		cout <<"����id: " <<it->m_ComId <<" ���������"<< it->m_Max << endl;
	}

	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::clearFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout <<"ԤԼ��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//��ȡ��Ϣ ѧ������ʦ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout <<" �ļ���ʧ�� !"<< endl;
		return;
	}
	//ȷ���������
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}

	//����
	cout <<"��ǰ��ѧ������Ϊ��" <<vStu.size()<< endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << " �ļ���ʧ�� !" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	//����
	cout << "��ǰ����ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		for (auto it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
		return false;

	}

}