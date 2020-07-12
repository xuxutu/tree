#include"teacher.h"

//构造
Teacher::Teacher()
{


}
//有参构造
Teacher::Teacher(int empId, string name, string pwd)
{


}
//析构
Teacher::~Teacher()
{


}

//菜单界面
void Teacher::openMenu()
{
	cout << "欢迎教师" << m_Name << "登录！" << endl;
	cout << endl << "----------------------------------------------------------------\n" << endl;
	cout << "\t\t|------------------------------|\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         1.查看所有人预约     |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         2.审核预约           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|         0.注销登录           |\n";
	cout << "\t\t|                              |\n";
	cout << "\t\t|------------------------------|\n" << endl;
	cout << "请选择您的操作：" << endl;

}

//查看所有预约
void Teacher::showAllOrder()
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
			cout << "预约日期：周" << of.m_OrderData[i]["data"] << " ";
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "姓名；" << of.m_OrderData[i]["stuName"] << " ";
			cout << "学号：" << of.m_OrderData[i]["stuId"] << " ";
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

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index=0;
	cout << "待审核预约记录如下：\n" << endl;

	for (int i = 0; i < of.m_Size; i++)
	{

		if (of.m_OrderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_OrderData[i]["data"] << " ";
			cout << "时间段：" << (of.m_OrderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "姓名；" << of.m_OrderData[i]["stuName"] << " ";
			cout << "学号：" << of.m_OrderData[i]["stuId"] << " ";
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
	}

	cout <<"请输入要审核的预约记录，0代表返回"<< endl;
	int sel = 0;//记录用户的选择
	int ret = 0;//记录结果

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
				cout <<"请输入审核结果：" <<endl;
				cout << "1、通过" << endl;
				cout << "2、未通过" << endl;
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
				cout <<"审核完毕！"<< endl;
				break;
			}
		}
		cout <<"输入有误请重新输入！" <<endl;

	}
	

	system("pause");
	system("cls");
}