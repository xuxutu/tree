#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;//����
	string interval;//ʱ���
	string stuId;//ѧ��id
	string stuName;//ѧ������
	string roomId;//������
	string status;//���״̬

	this->m_Size = 0;//��¼����

	while (ifs >> data && ifs >> interval && ifs 
		       >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//���� cout << data << "  " << interval << "  " 
		//<<stuId << "  " << stuName << "  " << roomId << "  " << status << endl;

		//�����ַ���
		//data:1
		string key;
		string value;
		map<string, string>m;

		//1.1
		int pos = data.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key = data.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.2
		pos = interval.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key =interval.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.3
	    pos = stuId.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key = stuId.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.4
		pos = stuName.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key = stuName.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.5
		pos = roomId.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key = roomId.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.6
		pos = status.find(':');//�ҡ�:��
		if (pos != -1)
		{
			key = status.substr(0, pos);//��0��ʼ��ȡ����ȡpos��
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		m_OrderData.insert(make_pair(this->m_Size,m));	

		this->m_Size++;

	}
	ifs.close();

	////���ԣ���������
	//for (auto it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	//{
	//	cout << "��" << it->first<<"��Ϣ���£�"<< endl;
	//	for (auto itm = (it->second).begin(); itm != (it->second).end(); itm++)
	//	{
	//		cout << "key="<<itm->first<<" value="<< itm->second << endl;
	//	}

	//}
}

//����
OrderFile::~OrderFile()
{


}

//����ԤԼ��¼
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//�������
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "data:" << this->m_OrderData[i]["data"]<< " ";
		ofs << "interval:" << this->m_OrderData[i]["interva"]<< " ";
		ofs << "stuId:" << this->m_OrderData[i]["stuId"]<< " ";
		ofs << "stuName:" << this->m_OrderData[i]["stuName"]<< " ";
		ofs << "roomId:" << this->m_OrderData[i]["roomId"]<< " ";
		ofs << "status:" << this->m_OrderData[i]["status"]<<endl;
	}

	ofs.close();

}