#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;//日期
	string interval;//时间段
	string stuId;//学生id
	string stuName;//学生名字
	string roomId;//机房号
	string status;//审核状态

	this->m_Size = 0;//记录条数

	while (ifs >> data && ifs >> interval && ifs 
		       >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//测试 cout << data << "  " << interval << "  " 
		//<<stuId << "  " << stuName << "  " << roomId << "  " << status << endl;

		//解析字符串
		//data:1
		string key;
		string value;
		map<string, string>m;

		//1.1
		int pos = data.find(':');//找‘:’
		if (pos != -1)
		{
			key = data.substr(0, pos);//从0开始截取，截取pos个
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.2
		pos = interval.find(':');//找‘:’
		if (pos != -1)
		{
			key =interval.substr(0, pos);//从0开始截取，截取pos个
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.3
	    pos = stuId.find(':');//找‘:’
		if (pos != -1)
		{
			key = stuId.substr(0, pos);//从0开始截取，截取pos个
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.4
		pos = stuName.find(':');//找‘:’
		if (pos != -1)
		{
			key = stuName.substr(0, pos);//从0开始截取，截取pos个
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.5
		pos = roomId.find(':');//找‘:’
		if (pos != -1)
		{
			key = roomId.substr(0, pos);//从0开始截取，截取pos个
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		//1.6
		pos = status.find(':');//找‘:’
		if (pos != -1)
		{
			key = status.substr(0, pos);//从0开始截取，截取pos个
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}

		m_OrderData.insert(make_pair(this->m_Size,m));	

		this->m_Size++;

	}
	ifs.close();

	////测试，容器遍历
	//for (auto it = m_OrderData.begin(); it != m_OrderData.end(); it++)
	//{
	//	cout << "第" << it->first<<"信息如下："<< endl;
	//	for (auto itm = (it->second).begin(); itm != (it->second).end(); itm++)
	//	{
	//		cout << "key="<<itm->first<<" value="<< itm->second << endl;
	//	}

	//}
}

//析构
OrderFile::~OrderFile()
{


}

//更新预约记录
void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;//无需更新
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