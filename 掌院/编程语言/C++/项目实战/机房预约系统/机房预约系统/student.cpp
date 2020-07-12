#include"student.h"

//构造函数
Student::Student()
{


}

//有参构造
Student::Student(int id, string name, string pwd)
{
	//初始化学生信息
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_Max)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//析构
Student::~Student()
{


}

//菜单界面
void Student::openMenu()
{
	cout << "欢迎学生代表" << m_Name << "登录！" << endl;
	cout << endl << "----------------------------------------------------------------\n" << endl;
	cout << "\t\t|------------------------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         1.申请预约           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.查看我的预约       |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         3.查看所有人预约     |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         4.取消预约           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.注销登录           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|------------------------------|\n" << endl;
	cout << "请选择您的操作：" << endl;


}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放的时间为周一到周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl; 

	int data = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房编号

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout <<"输入有误，请重新输入" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" <<endl;
	cout << "2、下午" <<endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	cout <<"请选择机房：" <<endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房的容量为：" << vCom[i].m_Max << endl;
	}
	
	while (true)
	{
		cin >> room;
		if(room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	cout <<"预约成功，审核中......"<< endl;
    
	//写入文件
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

//查看自身预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout <<"无预约记录！"<< endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//将string转为char,将char转为int
		if (this->m_id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//找到自身预约
			cout << "预约日期：周" << of.m_OrderData[i]["data"]<<" ";
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午": "下午")<<" ";
			cout << "机房号：" << of.m_OrderData[i]["roomId"]<<" ";
			string status = "状态: ";
			//1、审核中 2、已预约 0、取消预约 -1、预约失败
			if (of.m_OrderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_OrderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_OrderData[i]["status"] == "0")
			{
				status += "取消预约";
			}
			else
			{
				status += "预约失败,审核未通过！";
			}

			cout <<status << endl;
		}
	}

	system("pause");
	system("cls");
}

//查看所有人预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout <<"第" <<i + 1 << "条、 ";
		cout << "预约日期：周" << of.m_OrderData[i]["data"] << " ";
		cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_OrderData[i]["stuId"]<< " ";
		cout << "姓名：" << of.m_OrderData[i]["stuName"] << " ";
		cout << "机房号：" << of.m_OrderData[i]["roomId"] << " ";
		string status = "状态: ";
		//1、审核中 2、已预约 0、取消预约 -1、预约失败
		if (of.m_OrderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_OrderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_OrderData[i]["status"] == "0")
		{
			status += "取消预约";
		}
		else
		{
			status += "预约失败,审核未通过！";
		}

		cout << status << endl;
			
	}

	system("pause");
	system("cls");

}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;

	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中或预约成功的记录可以取消，请输入取消的记录:" << endl;
	vector<int>v;//存放，在最大容器的编号
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		//先判断是自身的学号
		if (this->m_id == atoi(of.m_OrderData[i]["stuId"].c_str()))
		{
			//再筛选审核中或者预约成功的状态
			if (of.m_OrderData[i]["status"] == "1" || of.m_OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++<<"、";
				cout <<"预约日期：周" <<of.m_OrderData[i]["data"]<<" ";
				cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午": "下午")<<" ";
				cout << "机房编号：" << of.m_OrderData[i]["roomId"]<<" ";
				string status = "状态：";
				if (of.m_OrderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_OrderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout <<"请输入取消的记录，0代表返回："<< endl;
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
				//取消预约
				of.m_OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout <<"已经取消预约！" << endl;
				break;
			}
		}
		cout <<"输入有误，请重新输入"<< endl;
	}
	system("pause");
	system("cls");
	return;
}