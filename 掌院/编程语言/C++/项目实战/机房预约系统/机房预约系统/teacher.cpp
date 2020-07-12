#include"teacher.h"

//����
Teacher::Teacher()
{


}
//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{


}
//����
Teacher::~Teacher()
{


}

//�˵�����
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ" << m_Name << "��¼��" << endl;
	cout << endl << "----------------------------------------------------------------\n" << endl;
	cout << "\t\t|------------------------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         1.�鿴������ԤԼ     |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.���ԤԼ           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.ע����¼           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|------------------------------|\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;

}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["data"] << " ";
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.m_OrderData[i]["stuName"] << " ";
			cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
			cout << "�����ţ�" << of.m_OrderData[i]["roomId"] << " ";
			string status = "״̬: ";
			//1������� 2����ԤԼ 0��ȡ��ԤԼ -1��ԤԼʧ��
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ";
			}
			else
			{
				status += "ԤԼʧ��,���δͨ����";
			}

			cout << status << endl;
	
	}

	
	system("pause");
	system("cls");

}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index=0;
	cout << "�����ԤԼ��¼���£�\n" << endl;

	for (int i = 0; i < of.m_Size; i++)
	{

		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["data"] << " ";
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "������" << of.m_OrderData[i]["stuName"] << " ";
			cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"] << " ";
			cout << "�����ţ�" << of.m_OrderData[i]["roomId"] << " ";
			string status = "״̬: ";
			//1������� 2����ԤԼ 0��ȡ��ԤԼ -1��ԤԼʧ��
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_OrderData[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ";
			}
			else
			{
				status += "ԤԼʧ��,���δͨ����";
			}
			cout << status << endl;

		}
	}

	cout <<"������Ҫ��˵�ԤԼ��¼��0������"<< endl;
	int sel = 0;//��¼�û���ѡ��
	int ret = 0;//��¼���

	while (true)
	{
		cin >> sel;
		if (sel >= 0 || sel <= v.size())
		{
			if (sel == 0)
			{
				break;
			}
			else
			{
				cout <<"��������˽����" <<endl;
				cout << "1��ͨ��" << endl;
				cout << "2��δͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_OrderData[v[sel-1] ]["status"] = 2;
				}
				else
				{
					of.m_OrderData[v[sel-1]]["status"] = -1;
				}
				of.updateOrder();
				cout <<"�����ϣ�"<< endl;
				break;
			}
		}
		cout <<"�����������������룡" <<endl;

	}
	

	system("pause");
	system("cls");
}