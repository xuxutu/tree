#define _CRT_SECURE_NO_WARNING
#include"globalFile.h"
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�������Ա���Ӳ˵�����
void managerMenu(Identity* manager)
{
	while (true)
	{
		//�����Ӳ˵�
		manager->openMenu();

		//������ָ��תΪ����ָ�룬�������������нӿ�
		Manager* man = (Manager*)manager;

		int sel = 0;
		//�����û���ѡ��
		cin >> sel;

		if (sel == 1)//����˺�
		{
			//cout <<"����˺�" << endl;
			man->addPerson();
		}
		else if (sel == 2)//�鿴�˺�
		{
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (sel == 3)//�鿴����
		{
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if(sel == 4)//���ԤԼ
		{
			//cout << "���ԤԼ" << endl;
			man->clearFile();
		}
		else
		{
			//cout << "ע����¼" << endl;
			//���ٵ���������Ա����
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//����ѧ�����Ӳ˵�
void studentMenu(Identity* student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->openMenu();
		Student* stu = (Student*)student;

		int sel = 0;
		cin >> sel;//�����û���ѡ��

		switch (sel)
		{
		case 1://����ԤԼ
			stu->applyOrder();
			break;
		case 2://�鿴����ԤԼ
			stu->showMyOrder();
			break;
		case 3://�鿴������ԤԼ
			stu->showAllOrder();
			break;
		case 4://ȡ��ԤԼ
			stu->cancelOrder();
			break;
		default://ע����¼
			delete student;
			cout <<"ע���ɹ���"<< endl;
			system("pause");
			system("cls");
			return;
		}
	}

}

//�����ʦ���Ӳ˵�
void TeacherMenu(Identity* teacher)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		teacher->openMenu();
		Teacher* tea = (Teacher*)teacher;

		int sel = 0;
		cin >> sel;//�����û���ѡ��

		switch (sel)
		{
		case 1://�鿴����ԤԼ
			tea->showAllOrder();
			break;
		case 2://���ԤԼ
			tea->validOrder();
			break;
		default://ע����¼
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}
//������
//fileName:�������ļ���
//    type:��½����ݣ�1.����ѧ����2.��ʦ��3.�������Ա��
void LoginIn(string fileName, int type)
{
	//��������ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName,ios::in);

	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ifs.is_open())
	{
		cout <<"�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//׼��������
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ�����
	{
		cout <<"���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "�������û����룺" << endl;
	cin >> pwd;

	//�����֤
	if (type == 1)
	{
		//ѧ�������֤
		//1 ���� 123
	    //2 ���� 12345
		
		//�洢���ļ��л�ȡ����Ϣ
		int fId;
		string fName;
		string fPwd;

		//��ȡ��Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//�����Ƿ����
			//cout << fId << fName << fPwd << endl;

			//�Ա�
			if ( fId == id && fName == name && fPwd == pwd)
			{
				cout <<"ѧ������֤��¼�ɹ���" << endl;

				
				system("pause");
				system("cls");
				//��ʾѧ���˵�
				person = new Student(id, name, pwd);
        		studentMenu(person);
				system("pause");
				return;
			}
		}
		
	}
	else if (type==2)
	{
		//��ʦ�����֤
		//1 ���� 123

		//�洢���ļ��л�ȡ����Ϣ
		int fId;
		string fName;
		string fPwd;

		//��ȡ��Ϣ
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//�����Ƿ����
			//cout << fId << fName << fPwd << endl;

			//�Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ����֤��¼�ɹ���" << endl;


				system("pause");
				system("cls");
				//��ʾ��ʦ�˵�
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				
				system("pause");
				return;
			}
		}
    }
	else if (type == 3)
	{
		//����Ա�����֤
		//admin 123

		//�洢���ļ��л�ȡ����Ϣ
		string fName;
		string fPwd;

		//��ȡ��Ϣ
		while (ifs >> fName && ifs >> fPwd)
		{
			//�����Ƿ����
			//cout  << fName << fPwd << endl;

			//�Ա�
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա����֤��¼�ɹ���" << endl;


				system("pause");
				system("cls");
				//��ʾ����Ա�˵�
				person = new Manager(name, pwd);
				managerMenu(person);
				system("pause");
				return;
			}
		}
	}

	cout<< "��֤��¼ʧ�ܣ�" << endl;
	/*system("pause");
	system("cls");*/

	return;
}

int main(void)
{
	int sel;
	while (true)
	{
		cout << "=============��ӭ��������ԤԼϵͳ==============================" << endl;
		cout << "�������������:" << endl;
		cout << endl << "----------------------------------------------------------------\n" << endl;
		cout << "\t\t|------------------------------|\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         1.ѧ������           |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         2.��ʦ               |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         3.����Ա             |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|         0.�˳�               |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|------------------------------|\n" << endl;
		cout << "����������ѡ��" << endl;

		cin >> sel;
		switch (sel)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE,1);
			break;

		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout <<"��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout <<"������������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
	

	system("pause");
	return 0;
}