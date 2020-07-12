#include"student.h"

//���캯��
Student::Student()
{


}

//�вι���
Student::Student(int id, string name, string pwd)
{
	//��ʼ��ѧ����Ϣ
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_Max)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//����
Student::~Student()
{


}

//�˵�����
void Student::openMenu()
{
	cout << "��ӭѧ������" << m_Name << "��¼��" << endl;
	cout << endl << "----------------------------------------------------------------\n" << endl;
	cout << "\t\t|------------------------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         1.����ԤԼ           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.�鿴�ҵ�ԤԼ       |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         3.�鿴������ԤԼ     |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         4.ȡ��ԤԼ           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.ע����¼           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|------------------------------|\n" << endl;
	cout << "��ѡ�����Ĳ�����" << endl;


}

//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl; 

	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//�������

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout <<"������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" <<endl;
	cout << "2������" <<endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}

	cout <<"��ѡ�������" <<endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������Ϊ��" << vCom[i].m_Max << endl;
	}
	
	while (true)
	{
		cin >> room;
		if(room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout <<"ԤԼ�ɹ��������......"<< endl;
    
	//д���ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout <<"��ԤԼ��¼��"<< endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//��stringתΪchar,��charתΪint
		if (this->m_id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//�ҵ�����ԤԼ
			cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["data"]<<" ";
			cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����": "����")<<" ";
			cout << "�����ţ�" << of.m_OrderData[i]["roomId"]<<" ";
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

			cout <<status << endl;
		}
	}

	system("pause");
	system("cls");
}

//�鿴������ԤԼ
void Student::showAllOrder()
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
		cout <<"��" <<i + 1 << "���� ";
		cout << "ԤԼ���ڣ���" << of.m_OrderData[i]["data"] << " ";
		cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_OrderData[i]["stuId"]<< " ";
		cout << "������" << of.m_OrderData[i]["stuName"] << " ";
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

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼:" << endl;
	vector<int>v;//��ţ�����������ı��
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//���ж��������ѧ��
		if (this->m_id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//��ɸѡ����л���ԤԼ�ɹ���״̬
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++<<"��";
				cout <<"ԤԼ���ڣ���" <<of.m_OrderData[i]["data"]<<" ";
				cout << "ʱ��Σ�" << (of.m_OrderData[i]["interval"] == "1" ? "����": "����")<<" ";
				cout << "������ţ�" << of.m_OrderData[i]["roomId"]<<" ";
				string status = "״̬��";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout <<"������ȡ���ļ�¼��0�����أ�"<< endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//ȡ��ԤԼ
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout <<"�Ѿ�ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout <<"������������������"<< endl;
	}
	system("pause");
	system("cls");
	return;
}